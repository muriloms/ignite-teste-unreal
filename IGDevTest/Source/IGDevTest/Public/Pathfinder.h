// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PathfindingGrid.h"
#include "GameFramework/Actor.h"
#include "Pathfinder.generated.h"


UENUM(BlueprintType)
enum class EHeuristic : uint8
{
	Heuristic_Manhatten 	UMETA(DisplayName = "Manhatten"),
	Heuristic_Euclidean 	UMETA(DisplayName = "Euclidean"),

};

UCLASS()
class IGDEVTEST_API APathfinder : public AActor
{
	GENERATED_BODY()
	
public:	
    // Define os valores padrões para as propriedades deste ator
    APathfinder();

    // Define o tipo de heurística a ser utilizado
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
    EHeuristic Heuristic;

   
    // Função para encontrar o caminho entre dois pontos e retornar um array de posições
    UFUNCTION(BlueprintCallable, Category = "AStar")
    TArray<FVector> FindPath(FVector Start, FVector End);

    // Função para traçar o caminho de volta a partir do nó inicial até o nó final (retorna um array de posições)
    TArray<FVector> RetracePath(PathfindingNode* StartNode, PathfindingNode* EndNode);

    // Calcula a distância entre dois nós
    float GetDistance(PathfindingNode* A, PathfindingNode* B);

    // Método para obter um nó da grade a partir de uma localização específica
    PathfindingNode* NodeFromLocation(FVector Location);

    // Array que armazena os cubos instanciados
    UPROPERTY(EditAnywhere, Category = "Pathfinding")
    TArray<UStaticMeshComponent*> GridObjArray;

    // Método que verifica se há um cubo bloqueando o caminho em uma determinada localização
    bool IsCubeBlockingPath(FVector Location);

protected:
    // Função chamada quando o jogo começa ou o ator é gerado
    virtual void BeginPlay() override;

public:
    // Função chamada a cada frame
    virtual void Tick(float DeltaTime) override;

    // Referência para a instância da grade de pathfinding
    UPROPERTY(EditAnywhere, Category = Pathfinding)
    APathfindingGrid* GridInstance;

};
