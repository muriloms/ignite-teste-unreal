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
    // Função para construir a grade de pathfinding
    void BuildGrid();

    // Função para desenhar a grade no modo de depuração
    void DebugGrid();

public:
    // Construtor que define os valores padrão para as propriedades deste ator
    APathfindingGrid();

protected:
    // Função chamada quando o jogo começa ou quando o ator é gerado
    virtual void BeginPlay() override;

public:
    // Função chamada a cada frame
    virtual void Tick(float DeltaTime) override;

    // Tamanho da grade no espaço 3D
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Grid)
    FVector GridSize;

    // Tamanho de cada nó na grade
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Grid)
    float NodeSize;

    // Tipos de objetos considerados no traço de detecção de nós
    UPROPERTY(EditAnywhere, Category = Grid)
    TArray<TEnumAsByte<EObjectTypeQuery>> Trace;

    // Flag para desenhar a grade no modo de depuração
    UPROPERTY(EditAnywhere, Category = Grid)
    bool DebugDraw;

    // Retorna o nó correspondente a uma determinada localização no espaço
    PathfindingNode* NodeFromLocation(FVector const& Loc);

    // Retorna a localização no espaço correspondente a um determinado nó
    FVector LocationFromNode(PathfindingNode* const& Node);

    // Retorna os nós vizinhos de um determinado nó
    TArray<PathfindingNode*> GetNeighbourNodes(PathfindingNode* const& Node);

    // Lista de atores a serem ignorados ao traçar os nós
    TArray<AActor*> ActorsToIgnore;

    // Resultado da detecção de colisão para os nós
    FHitResult HitResult;

    // Grade tridimensional de nós de pathfinding
    TArray<TArray<TArray<PathfindingNode*>>> NodeGrid;

    // Retorna uma localização aleatória dentro da grade
    FVector GetRandomLocationWithinGrid();

    // Conjunto de nós bloqueados (onde há cubos)
    TSet<PathfindingNode*> BlockedNodes;

    // Marca nós como bloqueados se houver cubos presentes
    void MarkBlockedNodes(TArray<UStaticMeshComponent*> CubeArray);

    // Verifica se um nó está bloqueado
    bool IsNodeBlocked(PathfindingNode* Node);

    // Ajusta uma localização para o centro do nó da grade mais próximo
    FVector SnapToGrid(const FVector& Location);

    // Detecta o nó sob o cursor do mouse e altera sua cor
    void HighlightNodeUnderCursor(FVector MouseLocation);

private:
    // Armazena a localização do nó atualmente destacado
    FVector CurrentHighlightedNodeLocation;
