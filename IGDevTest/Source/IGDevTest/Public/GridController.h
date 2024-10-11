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

    // Função chamada a cada frame
    virtual void Tick(float DeltaTime) override;

    // Métodos para manipulação de cliques
    UFUNCTION()
    void OnLeftMouseClick();

    // Propriedades relacionadas ao pathfinding
    UPROPERTY(EditAnywhere, Category = "Pathfinding")
    APathfindingGrid* GridInstance;  // Instância da grade de pathfinding

    UPROPERTY(EditAnywhere, Category = "Pathfinding")
    APathfinder* PathfinderInstance;  // Instância do pathfinder

    APathfindingController* PathfindingController;  // Controlador do pathfinding

private:

    // Ação de input para o clique do mouse
    UPROPERTY(EditAnywhere, Category = "Input")
    UInputAction* SetDestinationClickAction;

    UPROPERTY(EditAnywhere, Category = "Input")
    UInputMappingContext* DefaultMappingContext;

    // Função auxiliar para obter a localização do hit na grade
    bool GetHitResultOnGrid(FHitResult& OutHitResult);

    FVector StartLocation;  // Localização de início
    FVector EndLocation;    // Localização de destino
    bool bIsStartSet;       // Verifica se o ponto inicial está definido

    // Função para atualizar o caminho e mover o cubo
    void UpdatePathAndMoveCube();

    // Componente do cubo selecionado
    UStaticMeshComponent* SelectedCube;

    // Localização de destino do cubo
    FVector TargetLocation;

    // Seleciona o cubo a ser movido
    void SelectCube(UStaticMeshComponent* Cube);

    // Move o cubo para a localização de destino
    void MoveCubeToTarget(UStaticMeshComponent* Cube, const FVector& Target);

    // Altera a cor do cubo
    void ChangeCubeColor(UStaticMeshComponent* Cube, const FLinearColor& NewColor);

    // Método auxiliar para traçar objetos sob o cursor do mouse
    bool GetHitResultUnderCursorForGrid(FHitResult& HitResult);

    // Array de posições do caminho calculado
    TArray<FVector> PathArray;

    // Índice da posição atual no caminho
    int32 CurrentPathIndex;

    // Flags de controle de estado do movimento
    bool bIsAwaitingTarget;  // Verifica se está aguardando o destino
    bool bIsMoving;          // Verifica se o cubo está em movimento
    bool bIsCubeMoving;      // Verifica se um cubo está sendo movido
    float MoveSpeed;         // Velocidade de movimento do cubo

    // Função para mover o cubo ao longo do caminho
    void MoveAlongPath(float DeltaTime);

    // Gerenciador de timer para aguardar o destino
    FTimerHandle AwaitingTargetTimerHandle;
    
    // Habilita o estado de aguardo de um destino
    void EnableAwaitingTarget();

	
};
