// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "TopDownCameraPawn.generated.h"

UCLASS()
class IGDEVTEST_API ATopDownCameraPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATopDownCameraPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
    // Camera component to view the grid
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    UCameraComponent* TopDownCamera;

    // Scene component to define the root of the pawn
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    USceneComponent* Root;

    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Function to center the camera on the grid
    void CenterCameraOnGrid(FVector GridCenterLocation);

    // The target actor to focus on
    AActor* TargetActor;

    // Adjust camera pivot around the selected object
    void SetCameraPivot(AActor* NewTarget);

};
