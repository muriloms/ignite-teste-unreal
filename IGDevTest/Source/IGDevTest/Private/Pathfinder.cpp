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

// Called when the game starts or when spawned
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

// Called every frame
void APathfinder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector APathfinder::FindPath(FVector Start, FVector End)
{
	PathfindingNode* StartNode = GridInstance->NodeFromLocation(Start);	// Start node of the agent
	PathfindingNode* EndNode = GridInstance->NodeFromLocation(End);	// End goal node of the agent



	if (StartNode == nullptr) return Start;

	TArray<PathfindingNode*> OpenSet; // Nodes to be checked
	TArray<PathfindingNode*> ClosedSet; // Nodes already checked

	OpenSet.Add(StartNode); // Load our intial Node into the algorithm

	while (OpenSet.Num()) // While there is still nodes to be checked keep running the algorithm
	{

		PathfindingNode* CurrentNode = OpenSet[0]; // Run each cycle from the beginning element of the open list as the previous first element will have been processed and place into the closed list

		for (int i = 0; i < OpenSet.Num(); i++)
		{
			if (OpenSet[i] != nullptr && OpenSet[i]->FCost() <= CurrentNode->FCost() && OpenSet[i]->HCost < CurrentNode->HCost)
			{
				CurrentNode = OpenSet[i]; // Set Current node to be the closest node to the target
			}
		}
		//UKismetSystemLibrary::DrawDebugBox(this, GridInstance->LocationFromNode(CurrentNode), FVector::OneVector*GridInstance->NodeSize / 1, FLinearColor::Green, FRotator::ZeroRotator, 0);
		OpenSet.Remove(CurrentNode); // Once node has been processed remove it from the OpenSet
		ClosedSet.Add(CurrentNode); // Then add it to the closed set

		if (CurrentNode == EndNode)
		{
			int red = 1;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(red));
			return RetracePath(StartNode, EndNode); // If the CurrentNode is also the EndNode then we have reached out destination in the algorithm
		}

		TArray<PathfindingNode*> Neighbours = GridInstance->GetNeighbourNodes(CurrentNode); // Gather CurrentNodes neighbours into the list

		for (int i = 0; i < Neighbours.Num(); i++)
		{
			if (Neighbours[i] == nullptr || ClosedSet.Contains(Neighbours[i]))
			{
				continue;
			}

			float NewMovementCostToNeighbour = CurrentNode->GCost + GetDistance(CurrentNode, Neighbours[i]);
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(NewMovementCostToNeighbour));
			if (NewMovementCostToNeighbour < Neighbours[i]->GCost || !OpenSet.Contains(Neighbours[i]))
			{
				Neighbours[i]->GCost = NewMovementCostToNeighbour;
				Neighbours[i]->HCost = GetDistance(Neighbours[i], EndNode);
				Neighbours[i]->ParentNode = CurrentNode;
				//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(Neighbours[i]->GCost));
				if (!OpenSet.Contains(Neighbours[i]))
				{
					OpenSet.Add(Neighbours[i]);
				}
			}

		}

	}



	return GridInstance->LocationFromNode(StartNode);	// No path found
}

TArray<FVector> APathfinder::FindPathArray(FVector Start, FVector End)
{
	PathfindingNode* StartNode = GridInstance->NodeFromLocation(Start);
	PathfindingNode* EndNode = GridInstance->NodeFromLocation(End);

	if (StartNode == nullptr || EndNode == nullptr)
	{
		return {}; // Return empty if nodes are not valid
	}

	TArray<PathfindingNode*> OpenSet;
	TArray<PathfindingNode*> ClosedSet;

	OpenSet.Add(StartNode);

	while (OpenSet.Num() > 0)
	{
		PathfindingNode* CurrentNode = OpenSet[0];

		for (int i = 0; i < OpenSet.Num(); i++)
		{
			if (OpenSet[i]->FCost() < CurrentNode->FCost() ||
				(OpenSet[i]->FCost() == CurrentNode->FCost() && OpenSet[i]->HCost < CurrentNode->HCost))
			{
				CurrentNode = OpenSet[i];
			}
		}

		OpenSet.Remove(CurrentNode);
		ClosedSet.Add(CurrentNode);

		if (CurrentNode == EndNode)
		{
			return RetracePathArray(StartNode, EndNode);
		}

		TArray<PathfindingNode*> Neighbours = GridInstance->GetNeighbourNodes(CurrentNode);

		for (PathfindingNode* Neighbour : Neighbours)
		{
			// Verifica se o nó está bloqueado por um cubo
			if (ClosedSet.Contains(Neighbour) || Neighbour == nullptr || GridInstance->IsNodeBlocked(Neighbour))
			{
				continue; // Skip this neighbour if it's blocked by a cube or already in the closed set
			}

			float NewCost = CurrentNode->GCost + GetDistance(CurrentNode, Neighbour);
			if (NewCost < Neighbour->GCost || !OpenSet.Contains(Neighbour))
			{
				Neighbour->GCost = NewCost;
				Neighbour->HCost = GetDistance(Neighbour, EndNode);
				Neighbour->ParentNode = CurrentNode;

				// Ensure the neighbour is added to the open set if not already present
				if (!OpenSet.Contains(Neighbour))
				{
					OpenSet.Add(Neighbour);
				}
			}
		}
	}

	return {}; // Return empty if no path is found
}

float APathfinder::GetDistance(PathfindingNode* A, PathfindingNode* B)
{

	if (Heuristic == EHeuristic::Heuristic_Manhatten)
	{

		FVector ALoc, BLoc, Loc;
		ALoc = GridInstance->LocationFromNode(A);
		BLoc = GridInstance->LocationFromNode(B);

		Loc = ALoc - BLoc;

		return UKismetMathLibrary::Abs(Loc.X) + UKismetMathLibrary::Abs(Loc.Y) + UKismetMathLibrary::Abs(Loc.Z);
	}
	else if (Heuristic == EHeuristic::Heuristic_Euclidean)
	{
		return FVector::Distance(GridInstance->LocationFromNode(A), GridInstance->LocationFromNode(B));

	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("HEURISTIC MISSING, RETURNING 0 DISTANCE"));
	return 0;

}

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

	Algo::Reverse(Path);
	for (int i = 0; i < Path.Num(); i++)
	{
		UKismetSystemLibrary::DrawDebugBox(this, GridInstance->LocationFromNode(Path[i]), FVector::OneVector * GridInstance->NodeSize / 2.3f, FLinearColor::Green, FRotator::ZeroRotator, 0);
	}

	//if (Debug) DrawPath(Path);

	return GridInstance->LocationFromNode(Path[1]);
}


TArray<FVector> APathfinder::RetracePathArray(PathfindingNode* StartNode, PathfindingNode* EndNode)
{
    TArray<FVector> PathPositions; // Array que armazenará as posições do caminho

    if (StartNode == EndNode)
    {
        PathPositions.Add(GridInstance->LocationFromNode(StartNode));
        return PathPositions;
    }

    TArray<PathfindingNode*> PathNodes; // Array que armazenará os nós do caminho
    PathfindingNode* CurrentNode = EndNode;

    // Traçar o caminho de volta até o nó inicial
    while (CurrentNode != StartNode)
    {
        PathNodes.Add(CurrentNode);
        CurrentNode = CurrentNode->ParentNode;
    }

    PathNodes.Add(StartNode); // Adicionar o nó inicial

    // Inverter a ordem dos nós para que o caminho comece no StartNode
    Algo::Reverse(PathNodes);

    // Converter os nós em posições (FVector)
    for (PathfindingNode* Node : PathNodes)
    {
        FVector NodeLocation = GridInstance->LocationFromNode(Node);
        PathPositions.Add(NodeLocation); // Adiciona a posição correspondente do nó

        // Desenhar a caixa de debug para cada posição no caminho
        UKismetSystemLibrary::DrawDebugBox(this, NodeLocation, FVector::OneVector * GridInstance->NodeSize / 2.3f, FLinearColor::Green, FRotator::ZeroRotator, 0);
    }

    return PathPositions; // Retorna o caminho completo como um array de posições
}


PathfindingNode* APathfinder::NodeFromLocation(FVector Location)
{
	// Lógica para mapear a localização para um nó na grid
	return GridInstance->NodeFromLocation(Location);  // Certifique-se de que GridInstance tenha este método
}

bool APathfinder::IsCubeBlockingPath(FVector Location)
{
	for (UStaticMeshComponent* Cube : CubeArray)
	{
		// Verifica se o cubo está suficientemente próximo da localização atual para ser considerado um obstáculo
		if (FVector::Dist(Cube->GetComponentLocation(), Location) < (GridInstance->NodeSize * 0.5f))
		{
			return true; // O cubo está bloqueando o caminho
		}
	}
	return false;
}


