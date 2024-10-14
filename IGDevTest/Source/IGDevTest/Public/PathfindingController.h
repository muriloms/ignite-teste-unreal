// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pathfinder.h"
#include "PathfindingGrid.h"
#include "GridObject.h"
#include "Components/StaticMeshComponent.h"
#include "PathfindingController.generated.h"

class APathfinder;
class APathfindingGrid;
class AGridObject;
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
    // Função chamada a cada frame
    virtual void Tick(float DeltaTime) override;

    // Referências para as classes de pathfinding
    UPROPERTY(EditDefaultsOnly, Category = "Pathfinding")
    TSubclassOf<APathfindingGrid> PathfindingGridClass;

    UPROPERTY(EditDefaultsOnly, Category = "Pathfinding")
    TSubclassOf<APathfinder> PathfinderClass;

    // Instâncias da grade de pathfinding e do pathfinder
    UPROPERTY()
    APathfindingGrid* GridInstance;

    UPROPERTY()
    APathfinder* PathfinderInstance;

    // Número de cubos a serem gerados
    UPROPERTY(EditAnywhere, Category = "Pathfinding")
    int32 NumberOfCubes = 5;

    // Referência aos componentes de malha estática dos cubos
    UPROPERTY(EditDefaultsOnly, Category = "Pathfinding")
    TArray<AGridObject*> GridObjArray;

    // Objeto do grid
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pathfinding")
    TSubclassOf<AGridObject> GridObj;


    // Função de depuração para visualizar o caminho calculado
    void VisualizePath(const TArray<FVector>& Path);

    // Função que gera cubos na grade
    void SpawnCubes();

    // Função que marca os nós bloqueados na grade
    void MarkBlockedNodes();

    // Variável EditAnywhere para ativar/desativar o grid
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
    bool DrawGrid;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
    bool DrawPath;

    // Função para modificar o DebugDraw do Grid
    UFUNCTION(BlueprintCallable, Category = "Debug")
    void SetGridVisibility(bool bVisible);



private:
    // Variável que armazena o caminho atual calculado
    TArray<FVector> CurrentPath;

    // Variável para monitorar mudanças no DrawGrid
    bool bLastDrawGridValue;

};