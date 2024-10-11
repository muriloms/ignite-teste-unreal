// Fill out your copyright notice in the Description page of Project Settings.


#include "GridController.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "PathfindingGrid.h"
#include "Pathfinder.h"
#include "PathfindingController.h"
#include "TopDownCameraPawn.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/StaticMeshActor.h"

AGridController::AGridController()
{
    SelectedCube = nullptr;

    CurrentPathIndex = 0;
    MoveSpeed = 200.0f; // Velocidade de movimento do cubo

    bIsAwaitingTarget = false; // Inicialmente, não estamos aguardando o clique no grid
    bIsCubeMoving = false;     // Inicialmente, nenhum cubo está se movendo
    bIsMoving = false;

}

void AGridController::BeginPlay()
{
    Super::BeginPlay();

    // Add Input Mapping Context
    if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        Subsystem->AddMappingContext(DefaultMappingContext, 0);
    }
}

void AGridController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Se o cubo estiver se movendo, continua o movimento
    if (bIsMoving && SelectedCube && PathArray.Num() > 0)
    {
        MoveAlongPath(DeltaTime);
    }
}


bool AGridController::GetHitResultUnderCursorForGrid(FHitResult& HitResult)
{
    return GetHitResultUnderCursor(ECC_Visibility, true, HitResult);
}

void AGridController::SetupInputComponent()
{
    Super::SetupInputComponent();

    // Set up action bindings
    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
    {
        // Setup mouse input event
        EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Triggered, this, &AGridController::OnLeftMouseClick);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("'%s' Failed to find an Enhanced Input Component!"), *GetNameSafe(this));
    }
}

void AGridController::OnLeftMouseClick()
{
    FHitResult HitResult;
    if (GetHitResultUnderCursorForGrid(HitResult))
    {
        //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("CLICK"));
        // Check if the hit is a cube
        UStaticMeshComponent* HitCube = Cast<UStaticMeshComponent>(HitResult.GetComponent());

        // Verifica se estamos aguardando o clique no grid para mover o cubo
        if (bIsAwaitingTarget &&  SelectedCube)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("GRID"));
            // Clique no grid após selecionar o cubo: Define o destino
            TargetLocation = HitResult.ImpactPoint;
            MoveCubeToTarget(SelectedCube, TargetLocation);

            if (PathfindingController == nullptr)
                PathfindingController = Cast<APathfindingController>(UGameplayStatics::GetActorOfClass(GetWorld(), APathfindingController::StaticClass()));
            PathfindingController->MarkBlockedNodes();

            bIsCubeMoving = true; // O cubo está em movimento

            bIsAwaitingTarget = false; // Não aguardamos mais o clique no grid
        }
        // Clique em um cubo: Seleciona o cubo
        else if (HitCube && !bIsAwaitingTarget && !bIsCubeMoving)
        {
            if (HitCube->ComponentTags.Num() > 0 && HitCube->ComponentTags[0].ToString().StartsWith("Cube"))
            {
                SelectCube(HitCube);

                ATopDownCameraPawn* PlayerPawn = Cast<ATopDownCameraPawn>(GetPawn());
                if (PlayerPawn)
                {
                    //PlayerPawn->SetCameraPivot(HitCube->GetOwner());
                }
                
                // Inicia o timer para aguardar 1.5 segundos antes de permitir o clique no grid
                GetWorld()->GetTimerManager().SetTimer(AwaitingTargetTimerHandle, this, &AGridController::EnableAwaitingTarget, 1.5f, false);
            }
        }
    }
}

bool AGridController::GetHitResultOnGrid(FHitResult& OutHitResult)
{
    // Perform a line trace under the mouse cursor to get the hit location on the grid
    return GetHitResultUnderCursor(ECC_Visibility, true, OutHitResult);
}

void AGridController::UpdatePathAndMoveCube()
{

    if (PathfinderInstance && GridInstance)
    {
        // Calculate the path from start to end
        TArray<FVector> Path = PathfinderInstance->FindPathArray(StartLocation, EndLocation);

        // Optionally: Visualize the path
        for (int32 i = 0; i < Path.Num() - 1; i++)
        {
            DrawDebugLine(GetWorld(), Path[i], Path[i + 1], FColor::Blue, false, 5.0f, 0, 5.0f);
        }

        // Move the cube along the path
        if (Path.Num() > 0)
        {
            // Logic to move the cube to the final position (implement your movement logic here)
            // You can interpolate along the path or just snap to the end point for simplicity
        }
    }
}

void AGridController::SelectCube(UStaticMeshComponent* Cube)
{
    SelectedCube = Cube;

    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("CUBE")));

    ChangeCubeColor(SelectedCube, FLinearColor::Red);
}

void AGridController::MoveCubeToTarget(UStaticMeshComponent* Cube, const FVector& Target)
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("GRID"));

    if (PathfinderInstance == nullptr)
        PathfinderInstance = Cast<APathfinder>(UGameplayStatics::GetActorOfClass(GetWorld(), APathfinder::StaticClass()));
    if (GridInstance == nullptr)
        GridInstance = Cast<APathfindingGrid>(UGameplayStatics::GetActorOfClass(GetWorld(), APathfindingGrid::StaticClass()));

    if (PathfinderInstance && GridInstance)
    {
        StartLocation = Cube->GetComponentLocation();

        // Desenha a posição inicial do cubo para depuração
        DrawDebugSphere(GetWorld(), StartLocation, 25.0f, 12, FColor::Red, false, 5.0f);

        // Calcula o caminho entre a posição inicial e o ponto alvo
        PathArray = PathfinderInstance->FindPathArray(StartLocation, Target);

        if (PathArray.Num() > 0)
        {
            // Reseta o índice de caminho e começa o movimento do cubo
            CurrentPathIndex = 0;
            bIsMoving = true;
            SelectedCube = Cube; // Define o cubo como o cubo selecionado para movimento
        }
    }
}

void AGridController::MoveAlongPath(float DeltaTime)
{
    if (CurrentPathIndex >= PathArray.Num())
    {
        // O cubo chegou ao final do caminho
        bIsMoving = false;
        bIsCubeMoving = false; // O cubo chegou ao destino e agora podemos selecionar outro cubo
        ChangeCubeColor(SelectedCube, FLinearColor::Blue); // Muda a cor do cubo para azul
        SelectedCube = nullptr; // Limpa o cubo selecionado
        return;
    }

    ChangeCubeColor(SelectedCube, FLinearColor::Yellow);

    FVector CurrentTarget = PathArray[CurrentPathIndex];
    FVector CurrentLocation = SelectedCube->GetComponentLocation();

    // Calcula a direção e a distância para o próximo nó
    FVector Direction = (CurrentTarget - CurrentLocation).GetSafeNormal();
    float DistanceToTarget = FVector::Dist(CurrentLocation, CurrentTarget);

    // Move o cubo em direção ao próximo nó
    FVector NewLocation = CurrentLocation + Direction * MoveSpeed * DeltaTime;

    // Se estamos muito perto do próximo nó, avança para o próximo nó
    if (DistanceToTarget <= MoveSpeed * DeltaTime)
    {
        // Move o cubo diretamente para o próximo nó
        NewLocation = CurrentTarget;
        CurrentPathIndex++;
    }
    PathfindingController->VisualizePath(PathArray);


    SelectedCube->SetWorldLocation(NewLocation);

    // Desenha uma linha para visualizar o caminho
    DrawDebugLine(GetWorld(), CurrentLocation, NewLocation, FColor::Red, false, 0.1f, 0, 5.0f);
}

void AGridController::ChangeCubeColor(UStaticMeshComponent* Cube, const FLinearColor& NewColor)
{
    UMaterialInterface* CurrentMaterial = Cube->GetMaterial(0);
    if (UMaterialInstanceDynamic* DynamicMaterial = Cube->CreateAndSetMaterialInstanceDynamicFromMaterial(0, CurrentMaterial))
    {
        DynamicMaterial->SetVectorParameterValue(TEXT("Color"), NewColor);
    }
}

void AGridController::EnableAwaitingTarget()
{
    bIsAwaitingTarget = true; // Agora podemos esperar o segundo clique no grid
}