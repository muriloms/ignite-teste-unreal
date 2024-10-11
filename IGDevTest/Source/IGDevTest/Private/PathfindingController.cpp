

#include "PathfindingController.h"
#include "PathfindingGrid.h"
#include "Pathfinder.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"

// Sets default values
APathfindingController::APathfindingController()
{
    PrimaryActorTick.bCanEverTick = true;

    DebugDraw = false;


    // Create StartPointCube and TargetPointCube
    StartPointCube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StartPointCube"));
    TargetPointCube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TargetPointCube"));

    // Attach to Root
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    StartPointCube->SetupAttachment(RootComponent);
    TargetPointCube->SetupAttachment(RootComponent);

    // Assign default static mesh for cubes (assuming the mesh is in your project's assets)
    //static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

}

// Called when the game starts or when spawned
void APathfindingController::BeginPlay()
{
    Super::BeginPlay();

    // Spawn PathfindingGrid
    if (PathfindingGridClass)
    {
        GridInstance = GetWorld()->SpawnActor<APathfindingGrid>(PathfindingGridClass, FVector::ZeroVector, FRotator::ZeroRotator);
    }

    // Spawn Pathfinder
    if (PathfinderClass)
    {
        PathfinderInstance = GetWorld()->SpawnActor<APathfinder>(PathfinderClass, FVector::ZeroVector, FRotator::ZeroRotator);
    }

    if (GridInstance == nullptr || PathfinderInstance == nullptr || CubeMesh == nullptr)
    {
        UE_LOG(LogTemp, Error, TEXT("Missing GridInstance, PathfinderInstance, or CubeMesh in the PathfindingController"));
        return;
    }

    // Calcula a posição inicial do grid com base na posição do PathfindingController
    FVector StartLocation = GetActorLocation();
    GridInstance->SetActorLocation(StartLocation);

    // Spawn cubes in the grid
    SpawnCubes();

    // Marca os nós bloqueados no grid
    MarkBlockedNodes();

    // Set initial positions of Start and Target points
    //StartPointCube->SetStaticMesh(CubeMesh);
    //TargetPointCube->SetStaticMesh(CubeMesh);
    //StartPointCube->SetWorldLocation(GridInstance->GetRandomLocationWithinGrid());
    //TargetPointCube->SetWorldLocation(GridInstance->GetRandomLocationWithinGrid());


    UpdatePathfinding(); // Calculate the initial path
}

// Called every frame
void APathfindingController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Update the pathfinding in real time if the start or target points move
    //UpdatePathfinding();
}

void APathfindingController::MarkBlockedNodes()
{
    GridInstance->MarkBlockedNodes(CubeArray);
}

// Function to update pathfinding when cubes are moved
void APathfindingController::UpdatePathfinding()
{
    if (PathfinderInstance != nullptr && GridInstance != nullptr)
    {
        FVector StartLocation = StartPointCube->GetComponentLocation();
        FVector TargetLocation = TargetPointCube->GetComponentLocation();

        // Get the path from the Pathfinder
        CurrentPath = PathfinderInstance->FindPathArray(StartLocation, TargetLocation);

        // Visualize the path
        VisualizePath(CurrentPath);
    }
}

// Visualize the path with debug lines
void APathfindingController::VisualizePath(const TArray<FVector>& Path)
{
    if (Path.Num() == 0) return;

    for (int32 i = 0; i < Path.Num() - 1; i++)
    {
        DrawDebugLine(GetWorld(), Path[i], Path[i + 1], FColor::Red, false, -1.f, 0, 5.f);
    }
}

// Spawn cubes in the grid at random locations
void APathfindingController::SpawnCubes()
{
    for (int32 i = 0; i < NumberOfCubes; i++)
    {
        UStaticMeshComponent* NewCube = NewObject<UStaticMeshComponent>(this);

        // Atribui uma tag única ao cubo
        FString CubeTag = FString::Printf(TEXT("Cube"));
        NewCube->ComponentTags.Add(FName(*CubeTag));

        NewCube->SetStaticMesh(CubeMesh);
        NewCube->SetWorldLocation(GridInstance->GetRandomLocationWithinGrid());
        NewCube->RegisterComponent();
        NewCube->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

        CubeArray.Add(NewCube);
    }
}

// Draw grid on the editor viewport
void APathfindingController::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);
    

    if (DebugDraw)
    {
        // Pega o tamanho do grid a partir de um FVector definido no BP (exemplo: GridDimensions)
        FVector GridDimensions = FVector(50.f, 50.f, 0.0f); // Supondo que GridDimensions já esteja configurado no BP

        // Calcula os vértices do quadrado usando a localização do PathfindingController e o GridDimensions
        FVector TopLeft = GetActorLocation();
        FVector TopRight = TopLeft + FVector(GridDimensions.X, 0, 0);
        FVector BottomLeft = TopLeft + FVector(0, GridDimensions.Y, 0);
        FVector BottomRight = TopLeft + FVector(GridDimensions.X, GridDimensions.Y, 0);

        // Desenha as quatro arestas do quadrado
        DrawDebugLine(GetWorld(), TopLeft, TopRight, FColor::Blue, false, -1.0f, 0, 5.0f);
        DrawDebugLine(GetWorld(), TopRight, BottomRight, FColor::Blue, false, -1.0f, 0, 5.0f);
        DrawDebugLine(GetWorld(), BottomRight, BottomLeft, FColor::Blue, false, -1.0f, 0, 5.0f);
        DrawDebugLine(GetWorld(), BottomLeft, TopLeft, FColor::Blue, false, -1.0f, 0, 5.0f);

    }

    
}