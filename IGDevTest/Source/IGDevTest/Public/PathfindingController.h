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
    // Função chamada a cada frame
    virtual void Tick(float DeltaTime) override;

    // Referências para as classes de pathfinding
    UPROPERTY(EditAnywhere, Category = "Pathfinding")
    TSubclassOf<APathfindingGrid> PathfindingGridClass;  // Classe da grade de pathfinding

    UPROPERTY(EditAnywhere, Category = "Pathfinding")
    TSubclassOf<APathfinder> PathfinderClass;  // Classe do pathfinder

    // Instâncias da grade de pathfinding e do pathfinder
    UPROPERTY()
    APathfindingGrid* GridInstance;

    UPROPERTY()
    APathfinder* PathfinderInstance;

    // Número de cubos a serem gerados
    UPROPERTY(EditAnywhere, Category = "Pathfinding")
    int32 NumberOfCubes = 5;

    // Referência aos componentes de malha estática dos cubos
    UPROPERTY(EditAnywhere, Category = "Pathfinding")
    TArray<UStaticMeshComponent*> CubeArray;

    // Malha estática usada pelos cubos
    UPROPERTY(EditAnywhere, Category = "Pathfinding")
    UStaticMesh* CubeMesh;

    // Pontos de início e alvo representados por cubos de malha estática
    UPROPERTY(EditAnywhere)
    UStaticMeshComponent* StartPointCube;

    UPROPERTY(EditAnywhere)
    UStaticMeshComponent* TargetPointCube;

    // Função que atualiza o sistema de pathfinding
    UFUNCTION(BlueprintCallable, Category = "Pathfinding")
    void UpdatePathfinding();

    // Função de depuração para visualizar o caminho calculado
    void VisualizePath(const TArray<FVector>& Path);

    // Função que gera cubos na grade
    void SpawnCubes();

    // Função que marca os nós bloqueados na grade
    void MarkBlockedNodes();

    // Flag para desenhar a grade no modo de depuração
    UPROPERTY(EditAnywhere, Category = Grid)
    bool DebugDraw;

    // Função chamada ao construir o ator no editor (desenha a grade)
    virtual void OnConstruction(const FTransform& Transform) override;

private:
    // Variável que armazena o caminho atual calculado
    TArray<FVector> CurrentPath;

};