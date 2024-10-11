// Fill out your copyright notice in the Description page of Project Settings.


#include "Pathfinder.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#include "Algo/Reverse.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>
#include "Kismet/GameplayStatics.h"

// Sets default values
APathfinder::APathfinder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Função chamada quando o jogo começa ou o ator é gerado
void APathfinder::BeginPlay()
{
    Super::BeginPlay();

    // Tenta encontrar o PathfindingGrid no mundo
    TArray<AActor*> FoundGrids;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APathfindingGrid::StaticClass(), FoundGrids);

    if (FoundGrids.Num() > 0)
    {
        GridInstance = Cast<APathfindingGrid>(FoundGrids[0]);
        UE_LOG(LogTemp, Warning, TEXT("Pathfinding Grid encontrado!"));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Nenhum Pathfinding Grid encontrado no mundo!"));
    }
}

// Função chamada a cada frame
void APathfinder::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Função que encontra o caminho de Start para End e retorna a próxima posição no caminho
FVector APathfinder::FindPath(FVector Start, FVector End)
{
    PathfindingNode* StartNode = GridInstance->NodeFromLocation(Start); // Nó de início
    PathfindingNode* EndNode = GridInstance->NodeFromLocation(End); // Nó de destino

    if (StartNode == nullptr) return Start; // Se o nó inicial for inválido, retorna a posição inicial

    TArray<PathfindingNode*> OpenSet; // Nós a serem verificados
    TArray<PathfindingNode*> ClosedSet; // Nós já verificados

    OpenSet.Add(StartNode); // Adiciona o nó inicial ao conjunto de abertos

    while (OpenSet.Num() > 0) // Continua o algoritmo enquanto houver nós a serem processados
    {
        PathfindingNode* CurrentNode = OpenSet[0];

        for (int i = 0; i < OpenSet.Num(); i++)
        {
            if (OpenSet[i] != nullptr && OpenSet[i]->FCost() <= CurrentNode->FCost() && OpenSet[i]->HCost < CurrentNode->HCost)
            {
                CurrentNode = OpenSet[i]; // Define o nó atual como o mais próximo do destino
            }
        }

        OpenSet.Remove(CurrentNode); // Remove o nó atual do OpenSet
        ClosedSet.Add(CurrentNode); // Adiciona o nó ao ClosedSet

        if (CurrentNode == EndNode)
        {
            return RetracePath(StartNode, EndNode); // Caminho completo, traça o caminho de volta
        }

        // Obtém os nós vizinhos
        TArray<PathfindingNode*> Neighbours = GridInstance->GetNeighbourNodes(CurrentNode);

        for (int i = 0; i < Neighbours.Num(); i++)
        {
            if (Neighbours[i] == nullptr || ClosedSet.Contains(Neighbours[i]))
            {
                continue; // Ignora nós nulos ou já verificados
            }

            float NewMovementCostToNeighbour = CurrentNode->GCost + GetDistance(CurrentNode, Neighbours[i]);
            if (NewMovementCostToNeighbour < Neighbours[i]->GCost || !OpenSet.Contains(Neighbours[i]))
            {
                Neighbours[i]->GCost = NewMovementCostToNeighbour;
                Neighbours[i]->HCost = GetDistance(Neighbours[i], EndNode);
                Neighbours[i]->ParentNode = CurrentNode;

                if (!OpenSet.Contains(Neighbours[i]))
                {
                    OpenSet.Add(Neighbours[i]);
                }
            }
        }
    }

    return GridInstance->LocationFromNode(StartNode); // Retorna à posição inicial se não houver caminho
}

// Função que encontra o caminho de Start para End e retorna um array de posições
TArray<FVector> APathfinder::FindPathArray(FVector Start, FVector End)
{
    PathfindingNode* StartNode = GridInstance->NodeFromLocation(Start);
    PathfindingNode* EndNode = GridInstance->NodeFromLocation(End);

    if (StartNode == nullptr || EndNode == nullptr)
    {
        return {}; // Retorna vazio se os nós forem inválidos
    }

    TArray<PathfindingNode*> OpenSet;
    TArray<PathfindingNode*> ClosedSet;

    OpenSet.Add(StartNode);

    while (OpenSet.Num() > 0)
    {
        PathfindingNode* CurrentNode = OpenSet[0];

        for (int i = 0; i < OpenSet.Num(); i++)
        {
            if (OpenSet[i]->FCost() < CurrentNode->FCost() || (OpenSet[i]->FCost() == CurrentNode->FCost() && OpenSet[i]->HCost < CurrentNode->HCost))
            {
                CurrentNode = OpenSet[i];
            }
        }

        OpenSet.Remove(CurrentNode);
        ClosedSet.Add(CurrentNode);

        if (CurrentNode == EndNode)
        {
            return RetracePathArray(StartNode, EndNode); // Retorna o caminho completo como array de posições
        }

        TArray<PathfindingNode*> Neighbours = GridInstance->GetNeighbourNodes(CurrentNode);

        for (PathfindingNode* Neighbour : Neighbours)
        {
            // Verifica se o nó está bloqueado ou já verificado
            if (ClosedSet.Contains(Neighbour) || Neighbour == nullptr || GridInstance->IsNodeBlocked(Neighbour))
            {
                continue;
            }

            float NewCost = CurrentNode->GCost + GetDistance(CurrentNode, Neighbour);
            if (NewCost < Neighbour->GCost || !OpenSet.Contains(Neighbour))
            {
                Neighbour->GCost = NewCost;
                Neighbour->HCost = GetDistance(Neighbour, EndNode);
                Neighbour->ParentNode = CurrentNode;

                if (!OpenSet.Contains(Neighbour))
                {
                    OpenSet.Add(Neighbour);
                }
            }
        }
    }

    return {}; // Retorna vazio se nenhum caminho for encontrado
}

// Função que calcula a distância entre dois nós baseado na heurística
float APathfinder::GetDistance(PathfindingNode* A, PathfindingNode* B)
{
    if (Heuristic == EHeuristic::Heuristic_Manhatten)
    {
        FVector ALoc = GridInstance->LocationFromNode(A);
        FVector BLoc = GridInstance->LocationFromNode(B);
        FVector Loc = ALoc - BLoc;

        return UKismetMathLibrary::Abs(Loc.X) + UKismetMathLibrary::Abs(Loc.Y) + UKismetMathLibrary::Abs(Loc.Z);
    }
    else if (Heuristic == EHeuristic::Heuristic_Euclidean)
    {
        return FVector::Distance(GridInstance->LocationFromNode(A), GridInstance->LocationFromNode(B));
    }

    UE_LOG(LogTemp, Error, TEXT("HEURISTIC MISSING, RETURNING 0 DISTANCE"));
    return 0;
}

// Função que traça o caminho de volta a partir do nó inicial até o nó final
FVector APathfinder::RetracePath(PathfindingNode* StartNode, PathfindingNode* EndNode)
{
    if (StartNode == EndNode)
    {
        return GridInstance->LocationFromNode(StartNode);
    }

    TArray<PathfindingNode*> Path;
    PathfindingNode* CurrentNode = EndNode;

    while (CurrentNode != StartNode)
    {
        Path.Add(CurrentNode);
        CurrentNode = CurrentNode->ParentNode;
    }

    Algo::Reverse(Path); // Inverte o caminho para que comece no StartNode

    for (int i = 0; i < Path.Num(); i++)
    {
        UKismetSystemLibrary::DrawDebugBox(this, GridInstance->LocationFromNode(Path[i]), FVector::OneVector * GridInstance->NodeSize / 2.3f, FLinearColor::Green, FRotator::ZeroRotator, 0);
    }

    return GridInstance->LocationFromNode(Path[1]); // Retorna a próxima posição
}

// Função que traça o caminho de volta como array de posições
TArray<FVector> APathfinder::RetracePathArray(PathfindingNode* StartNode, PathfindingNode* EndNode)
{
    TArray<FVector> PathPositions;

    if (StartNode == EndNode)
    {
        PathPositions.Add(GridInstance->LocationFromNode(StartNode));
        return PathPositions;
    }

    TArray<PathfindingNode*> PathNodes;
    PathfindingNode* CurrentNode = EndNode;

    while (CurrentNode != StartNode)
    {
        PathNodes.Add(CurrentNode);
        CurrentNode = CurrentNode->ParentNode;
    }

    PathNodes.Add(StartNode);
    Algo::Reverse(PathNodes);

    for (PathfindingNode* Node : PathNodes)
    {
        FVector NodeLocation = GridInstance->LocationFromNode(Node);
        PathPositions.Add(NodeLocation);

        UKismetSystemLibrary::DrawDebugBox(this, NodeLocation, FVector::OneVector * GridInstance->NodeSize / 2.3f, FLinearColor::Green, FRotator::ZeroRotator, 0);
    }

    return PathPositions; // Retorna o caminho como array de posições
}

// Função para mapear uma localização para um nó
PathfindingNode* APathfinder::NodeFromLocation(FVector Location)
{
    return GridInstance->NodeFromLocation(Location); // Mapeia a localização para um nó na grade
}

// Função que verifica se um cubo está bloqueando o caminho
bool APathfinder::IsCubeBlockingPath(FVector Location)
{
    for (UStaticMeshComponent* Cube : CubeArray)
    {
        // Verifica se há um cubo bloqueando o caminho na localização fornecida
        if (FVector::Dist(Cube->GetComponentLocation(), Location) < (GridInstance->NodeSize * 0.5f))
        {
            return true; // O cubo está bloqueando o caminho
        }
    }
    return false;
}
