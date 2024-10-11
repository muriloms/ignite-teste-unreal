

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

    DebugDraw = false;  // Depuração desabilitada por padrão

    // Cria os cubos que representam os pontos de início e destino
    StartPointCube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StartPointCube"));
    TargetPointCube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TargetPointCube"));

    // Anexa os cubos ao componente raiz
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    StartPointCube->SetupAttachment(RootComponent);
    TargetPointCube->SetupAttachment(RootComponent);
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
    if (GridInstance == nullptr || PathfinderInstance == nullptr || CubeMesh == nullptr)
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

    // Calcula o caminho inicial
    UpdatePathfinding();
}

// Função chamada a cada frame
void APathfindingController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    // Atualiza o sistema de pathfinding em tempo real, se os pontos de início ou destino se moverem (comentado por enquanto)
    // UpdatePathfinding();
}

// Marca os nós bloqueados no grid com base na posição dos cubos
void APathfindingController::MarkBlockedNodes()
{
    GridInstance->MarkBlockedNodes(CubeArray);
}

// Atualiza o sistema de pathfinding quando os cubos são movidos
void APathfindingController::UpdatePathfinding()
{
    if (PathfinderInstance != nullptr && GridInstance != nullptr)
    {
        FVector StartLocation = StartPointCube->GetComponentLocation();
        FVector TargetLocation = TargetPointCube->GetComponentLocation();

        // Obtém o caminho calculado pelo pathfinder
        CurrentPath = PathfinderInstance->FindPathArray(StartLocation, TargetLocation);

        // Visualiza o caminho calculado
        VisualizePath(CurrentPath);
    }
}

// Visualiza o caminho calculado com linhas de depuração
void APathfindingController::VisualizePath(const TArray<FVector>& Path)
{
    if (Path.Num() == 0) return;

    for (int32 i = 0; i < Path.Num() - 1; i++)
    {
        DrawDebugLine(GetWorld(), Path[i], Path[i + 1], FColor::Red, false, -1.f, 0, 5.f);
    }
}

// Gera cubos em locais aleatórios dentro da grade
void APathfindingController::SpawnCubes()
{
    for (int32 i = 0; i < NumberOfCubes; i++)
    {
        UStaticMeshComponent* NewCube = NewObject<UStaticMeshComponent>(this);

        // Atribui uma tag única ao cubo
        FString CubeTag = FString::Printf(TEXT("Cube"));
        NewCube->ComponentTags.Add(FName(*CubeTag));

        // Define a malha e a localização do cubo
        NewCube->SetStaticMesh(CubeMesh);
        NewCube->SetWorldLocation(GridInstance->GetRandomLocationWithinGrid());
        NewCube->RegisterComponent();
        NewCube->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

        // Adiciona o cubo ao array
        CubeArray.Add(NewCube);
    }
}

// Desenha a grade no editor durante a construção do ator
void APathfindingController::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);

    if (DebugDraw)
    {
        // Define o tamanho do grid (exemplo retirado do blueprint)
        FVector GridDimensions = FVector(50.f, 50.f, 0.0f);

        // Calcula os vértices do quadrado que representa o grid
        FVector TopLeft = GetActorLocation();
        FVector TopRight = TopLeft + FVector(GridDimensions.X, 0, 0);
        FVector BottomLeft = TopLeft + FVector(0, GridDimensions.Y, 0);
        FVector BottomRight = TopLeft + FVector(GridDimensions.X, GridDimensions.Y, 0);

        // Desenha as arestas do grid
        DrawDebugLine(GetWorld(), TopLeft, TopRight, FColor::Blue, false, -1.0f, 0, 5.0f);
        DrawDebugLine(GetWorld(), TopRight, BottomRight, FColor::Blue, false, -1.0f, 0, 5.0f);
        DrawDebugLine(GetWorld(), BottomRight, BottomLeft, FColor::Blue, false, -1.0f, 0, 5.0f);
        DrawDebugLine(GetWorld(), BottomLeft, TopLeft, FColor::Blue, false, -1.0f, 0, 5.0f);
    }
}
