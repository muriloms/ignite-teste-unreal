

#include "PathfindingController.h"
#include "PathfindingGrid.h"
#include "Pathfinder.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"

// Define os valores padrões para este ator
APathfindingController::APathfindingController()
{
    PrimaryActorTick.bCanEverTick = true;


    DrawGrid = true;
    bLastDrawGridValue = DrawGrid;

    DrawPath = true;

}

// Função chamada quando o jogo começa ou o ator é gerado
void APathfindingController::BeginPlay()
{
    Super::BeginPlay();

    // Instancia a grade de pathfinding
    if (PathfindingGridClass)
    {
        GridInstance = GetWorld()->SpawnActor<APathfindingGrid>(PathfindingGridClass, FVector::ZeroVector, FRotator::ZeroRotator);
    }

    // Instancia o pathfinder
    if (PathfinderClass)
    {
        PathfinderInstance = GetWorld()->SpawnActor<APathfinder>(PathfinderClass, FVector::ZeroVector, FRotator::ZeroRotator);
    }

    // Verifica se as instâncias e a malha dos cubos foram corretamente configuradas
    if (GridInstance == nullptr || PathfinderInstance == nullptr || GridObj == nullptr)
    {
        UE_LOG(LogTemp, Error, TEXT("Missing GridInstance, PathfinderInstance, or CubeMesh in the PathfindingController"));
        return;
    }

    // Define a localização inicial da grade com base na posição do controlador
    FVector StartLocation = GetActorLocation();
    GridInstance->SetActorLocation(StartLocation);

    // Gera os cubos na grade
    SpawnCubes();

    // Marca os nós bloqueados com base nos cubos
    MarkBlockedNodes();


    // Atualizar a visibilidade do grid com base na variável DrawGrid
    if (GridInstance)
    {
        SetGridVisibility(DrawGrid);

    }
}

// Função chamada a cada frame
void APathfindingController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    // Verifica se o valor de DrawGrid foi alterado durante o jogo
    if (DrawGrid != bLastDrawGridValue)
    {
        // Atualiza a visibilidade do grid
        SetGridVisibility(DrawGrid);
        bLastDrawGridValue = DrawGrid; // Atualiza o valor anterior
    }
}

void APathfindingController::SetGridVisibility(bool bVisible)
{
    if (GridInstance)
    {
        GridInstance->DebugDraw = bVisible;
    }
}

// Marca os nós bloqueados no grid com base na posição dos cubos
void APathfindingController::MarkBlockedNodes()
{
    GridInstance->MarkBlockedNodes(GridObjArray);
}


// Visualiza o caminho calculado com linhas de depuração
void APathfindingController::VisualizePath(const TArray<FVector>& Path)
{
    if (!DrawPath) return;
    if (Path.Num() == 0) return;

    for (int32 i = 0; i < Path.Num() - 1; i++)
    {
        DrawDebugLine(GetWorld(), Path[i], Path[i + 1], FColor::Red, false, -1.f, 0, 5.f);

     UKismetSystemLibrary::DrawDebugBox(this, Path[i], FVector::OneVector * GridInstance->NodeSize / 2.0f, FLinearColor::Blue, FRotator::ZeroRotator, 0);
    }

}


void APathfindingController::SpawnCubes()
{
    for (int32 i = 0; i < NumberOfCubes; i++)
    {
        // Gera um novo ator do tipo AGridObject
        FVector SpawnLocation = GridInstance->GetRandomLocationWithinGrid();
        FRotator SpawnRotation = FRotator::ZeroRotator;

        AGridObject* NewCube = GetWorld()->SpawnActor<AGridObject>(GridObj, SpawnLocation, SpawnRotation);

        if (NewCube)
        {
            // Configura a tag única para o cubo
            FString CubeTag = FString::Printf(TEXT("Cube_%d"), i);
            NewCube->Tags.Add(FName(*CubeTag));

            // Adiciona o cubo ao array para referencia futura
            GridObjArray.Add(NewCube);
        }
    }
}



