// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PathfindingNode.h"
#include "GameFramework/Actor.h"
#include "PathfindingGrid.generated.h"

UCLASS()
class APathfindingGrid : public AActor
{
	GENERATED_BODY()

private:
	void BuildGrid();
	void DebugGrid();

public:
	// Sets default values for this actor's properties
	APathfindingGrid();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Grid)
	FVector GridSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Grid)
	float NodeSize;

	UPROPERTY(EditAnywhere, Category = Grid)
	TArray<TEnumAsByte<EObjectTypeQuery>> Trace;

	UPROPERTY(EditAnywhere, Category = Grid)
	bool DebugDraw;

	PathfindingNode* NodeFromLocation(FVector const& Loc);
	FVector LocationFromNode(PathfindingNode* const& Node);
	TArray<PathfindingNode*> GetNeighbourNodes(PathfindingNode* const& Node);

	TArray<AActor*> ActorsToIgnore;
	FHitResult HitResult;
	TArray<TArray<TArray<PathfindingNode*>>> NodeGrid;

	FVector GetRandomLocationWithinGrid();

	// Armazena as posições dos cubos no grid
	TSet<PathfindingNode*> BlockedNodes;

	// Marca um nó como bloqueado se houver um cubo presente
	void MarkBlockedNodes(TArray<UStaticMeshComponent*> CubeArray);

	// Verifica se o nó está bloqueado
	bool IsNodeBlocked(PathfindingNode* Node);

	FVector SnapToGrid(const FVector& Location);

	// Detecta o nó sob o cursor do mouse e altera a cor
	void HighlightNodeUnderCursor(FVector MouseLocation);

private:
	FVector CurrentHighlightedNodeLocation;
};