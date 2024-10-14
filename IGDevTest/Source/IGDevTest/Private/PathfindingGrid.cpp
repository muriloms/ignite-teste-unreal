// Fill out your copyright notice in the Description page of Project Settings.


#include "PathfindingGrid.h"
#include "DrawDebugHelpers.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>

// Sets default values
APathfindingGrid::APathfindingGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APathfindingGrid::BeginPlay()
{
	Super::BeginPlay();
	BuildGrid();
}

// Called every frame
void APathfindingGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DebugGrid();
}

// Função que constrói a grade de pathfinding
void APathfindingGrid::BuildGrid()
{
    for (int x = 0; x < GridSize.X; x++)
    {
        NodeGrid.Add(TArray<TArray<PathfindingNode*>>());
        for (int y = 0; y < GridSize.Y; y++)
        {
            NodeGrid[x].Add(TArray<PathfindingNode*>());
            for (int z = 0; z < GridSize.Z; z++)
            {
                // Verifica colisões com objetos para definir se o nó está bloqueado
                bool hit;
                hit = UKismetSystemLibrary::BoxTraceSingleForObjects(this, GetActorLocation() + FVector(x, y, z) * NodeSize, 
                    GetActorLocation() + FVector(x, y, z) * NodeSize, FVector::OneVector * NodeSize / 2, 
                    FRotator::ZeroRotator, Trace, false, ActorsToIgnore, EDrawDebugTrace::None, HitResult, true);

                // Cria o nó atual
                PathfindingNode* currentNode = new PathfindingNode(x, y, z);
                if (hit)
                {
                    NodeGrid[x][y].Add(nullptr); // Nó bloqueado
                }
                else
                {
                    NodeGrid[x][y].Add(currentNode); // Nó acessível
                }
            }
        }
    }
}

// Função que desenha a grade no modo de depuração
void APathfindingGrid::DebugGrid()
{
    if (DebugDraw)
    {
        for (int x = 0; x < GridSize.X; x++)
        {
            for (int y = 0; y < GridSize.Y; y++)
            {
                for (int z = 0; z < GridSize.Z; z++)
                {
                    if (NodeGrid[x][y][z] == nullptr)
                    {
                        UKismetSystemLibrary::DrawDebugBox(this, GetActorLocation() + FVector(x, y, z) * NodeSize, 
                            FVector::OneVector * NodeSize / 2.3f, FLinearColor::Red, FRotator::ZeroRotator, 0); // Nó bloqueado
                    }
                    else
                    {
                        UKismetSystemLibrary::DrawDebugBox(this, GetActorLocation() + FVector(x, y, z) * NodeSize, 
                            FVector::OneVector * NodeSize / 2.3f, FLinearColor::Green, FRotator::ZeroRotator, 0); // Nó acessível
                    }
                }
            }
        }
    }
}

// Função que retorna os nós vizinhos ao nó atual
TArray<PathfindingNode*> APathfindingGrid::GetNeighbourNodes(PathfindingNode* const& Node)
{
    TArray<PathfindingNode*> Neighbours;

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                if (x == 1 && y == 1 && z == 1) { continue; } // Ignora o nó atual

                int XIndex = Node->GridX + x - 1;
                int ZIndex = Node->GridZ + z - 1;
                int YIndex = Node->GridY + y - 1;

                // Verifica se o nó vizinho está dentro dos limites da grade
                if (XIndex >= 0 && XIndex < GridSize.X && ZIndex >= 0 && ZIndex < GridSize.Z && YIndex >= 0 && YIndex < GridSize.Y)
                {
                    if (NodeGrid[XIndex][YIndex][ZIndex] != nullptr)
                    {
                        Neighbours.Add(NodeGrid[XIndex][YIndex][ZIndex]);
                    }
                }
            }
        }
    }

    return Neighbours;
}

// Retorna o nó correspondente a uma localização no mundo
PathfindingNode* APathfindingGrid::NodeFromLocation(FVector const& loc)
{
    FVector GridLocation = ((loc - GetActorLocation()) / NodeSize);
    FVector RoundedGridLocation = FVector(
        UKismetMathLibrary::Clamp(UKismetMathLibrary::Round(GridLocation.X), 0, GridSize.X - 1),
        UKismetMathLibrary::Clamp(UKismetMathLibrary::Round(GridLocation.Y), 0, GridSize.Y - 1),
        UKismetMathLibrary::Clamp(UKismetMathLibrary::Round(GridLocation.Z), 0, GridSize.Z - 1));

    return NodeGrid[RoundedGridLocation.X][RoundedGridLocation.Y][RoundedGridLocation.Z];
}

// Retorna a localização de um nó no mundo
FVector APathfindingGrid::LocationFromNode(PathfindingNode* const& Node)
{
    return GetActorLocation() + FVector(Node->GridX, Node->GridY, Node->GridZ) * NodeSize;
}

// Retorna uma localização aleatória dentro da grade
FVector APathfindingGrid::GetRandomLocationWithinGrid()
{
    FVector GridOrigin = GetActorLocation();

    float GridMinX = GridOrigin.X;
    float GridMinY = GridOrigin.Y;
    float GridMaxX = GridMinX + (GridSize.X * NodeSize);
    float GridMaxY = GridMinY + (GridSize.Y * NodeSize);

    float RandomX = FMath::RandRange(GridMinX, GridMaxX);
    float RandomY = FMath::RandRange(GridMinY, GridMaxY);
    float Z = GridOrigin.Z;

    return FVector(RandomX, RandomY, Z);
}

// Marca nós bloqueados com base nas posições dos cubos
void APathfindingGrid::MarkBlockedNodes(TArray<AGridObject*> GridObjArray)
{
    // Limpa os nós bloqueados antigos
    BlockedNodes.Empty();

    // Itera sobre todos os objetos na GridObjArray
    for (AGridObject* GridObject : GridObjArray)
    {
        // Obtém a localização do ator (cubo)
        FVector CubeLocation = GridObject->GetCubeMesh()->GetComponentLocation();

        // Encontra o nó correspondente no grid
        PathfindingNode* Node = NodeFromLocation(CubeLocation);

        // Se o nó foi encontrado, marca-o como bloqueado
        if (Node)
        {
            BlockedNodes.Add(Node);
        }
    }
}

// Verifica se um nó está bloqueado
bool APathfindingGrid::IsNodeBlocked(PathfindingNode* Node)
{
    return BlockedNodes.Contains(Node);
}

// Ajusta uma localização para o centro do nó da grade mais próximo
FVector APathfindingGrid::SnapToGrid(const FVector& Location)
{
    float SnappedX = FMath::GridSnap(Location.X, NodeSize);
    float SnappedY = FMath::GridSnap(Location.Y, NodeSize);
    return FVector(SnappedX, SnappedY, Location.Z);
}

// Destaca o nó sob o cursor do mouse
void APathfindingGrid::HighlightNodeUnderCursor(FVector MouseLocation)
{
    FVector NodeLocation = SnapToGrid(MouseLocation);

    if (NodeLocation != CurrentHighlightedNodeLocation)
    {
        if (CurrentHighlightedNodeLocation != FVector::ZeroVector)
        {
            DrawDebugBox(GetWorld(), CurrentHighlightedNodeLocation, FVector(NodeSize / 2, NodeSize / 2, 50), FColor::Green, false, -1, 0, 5.0f);
        }

        DrawDebugBox(GetWorld(), NodeLocation, FVector(NodeSize / 2, NodeSize / 2, 50), FColor::Red, false, -1, 0, 5.0f);
        CurrentHighlightedNodeLocation = NodeLocation;
    }
}
