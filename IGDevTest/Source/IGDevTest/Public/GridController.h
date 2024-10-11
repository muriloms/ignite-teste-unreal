// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GridController.generated.h"

class UStaticMeshComponent;
class APathfindingGrid;
class APathfinder;
class APathfindingController;

/**
 * 
 */
UCLASS()
class IGDEVTEST_API AGridController : public APlayerController
{
	GENERATED_BODY()

public:

	AGridController();

protected:
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;

public:

    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Click handling methods
    UFUNCTION()
    void OnLeftMouseClick();

    // Pathfinding related
    UPROPERTY(EditAnywhere, Category = "Pathfinding")
    APathfindingGrid* GridInstance;

    UPROPERTY(EditAnywhere, Category = "Pathfinding")
    APathfinder* PathfinderInstance;

    APathfindingController* PathfindingController;

private:

    // Input action for mouse click
    UPROPERTY(EditAnywhere, Category = "Input")
    UInputAction* SetDestinationClickAction;

    UPROPERTY(EditAnywhere, Category = "Input")
    UInputMappingContext* DefaultMappingContext;

    // Helper function to get hit location on the grid
    bool GetHitResultOnGrid(FHitResult& OutHitResult);

    FVector StartLocation;
    FVector EndLocation;
    bool bIsStartSet;

    // Function to update the path and move the cube
    void UpdatePathAndMoveCube();


    UStaticMeshComponent* SelectedCube;
    FVector TargetLocation;

    void SelectCube(UStaticMeshComponent* Cube);
    void MoveCubeToTarget(UStaticMeshComponent* Cube, const FVector& Target);
    void ChangeCubeColor(UStaticMeshComponent* Cube, const FLinearColor& NewColor);

    // Helper method to trace objects under the mouse
    bool GetHitResultUnderCursorForGrid(FHitResult& HitResult);


    TArray<FVector> PathArray;
    int32 CurrentPathIndex;
    bool bIsAwaitingTarget;
    bool bIsMoving;
    bool bIsCubeMoving;
    float MoveSpeed;

    // Move o cubo ao longo do caminho
    void MoveAlongPath(float DeltaTime);

    FTimerHandle AwaitingTargetTimerHandle; // Gerencia o timer para o delay
    void EnableAwaitingTarget();
	
};
