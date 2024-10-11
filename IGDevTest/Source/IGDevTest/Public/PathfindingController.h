// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pathfinder.h"
#include "PathfindingGrid.h"
#include "Components/StaticMeshComponent.h"
#include "PathfindingController.generated.h"

class APathfinder;
class APathfindingGrid;
class UStaticMeshComponent;

UCLASS()
class IGDEVTEST_API APathfindingController : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    APathfindingController();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // References to the pathfinding components
    UPROPERTY(EditAnywhere, Category = "Pathfinding")
    TSubclassOf<APathfindingGrid> PathfindingGridClass;

    UPROPERTY(EditAnywhere, Category = "Pathfinding")
    TSubclassOf<APathfinder> PathfinderClass;

    UPROPERTY()
    APathfindingGrid* GridInstance;

    UPROPERTY()
    APathfinder* PathfinderInstance;

    // Number of cubes to spawn
    UPROPERTY(EditAnywhere, Category = "Pathfinding")
    int32 NumberOfCubes = 5;

    // Reference to the cubes
    UPROPERTY(EditAnywhere, Category = "Pathfinding")
    TArray<UStaticMeshComponent*> CubeArray;

    // Static mesh for the cubes
    UPROPERTY(EditAnywhere, Category = "Pathfinding")
    UStaticMesh* CubeMesh;

    // Start and Target points represented by static mesh cubes
    UPROPERTY(EditAnywhere)
    UStaticMeshComponent* StartPointCube;

    UPROPERTY(EditAnywhere)
    UStaticMeshComponent* TargetPointCube;

    // Function to update the pathfinding
    UFUNCTION(BlueprintCallable, Category = "Pathfinding")
    void UpdatePathfinding();

    // Debug function to visualize the path
    void VisualizePath(const TArray<FVector>& Path);


    // Function to spawn cubes in the grid
    void SpawnCubes();

    void MarkBlockedNodes();

    UPROPERTY(EditAnywhere, Category = Grid)
    bool DebugDraw;

    // Draw grid in the editor viewport
    virtual void OnConstruction(const FTransform& Transform) override;

private:

    // Variable to store the current path
    TArray<FVector> CurrentPath;
};