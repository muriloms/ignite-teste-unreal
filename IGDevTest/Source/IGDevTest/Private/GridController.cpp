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

    // Adiciona o Input Mapping Context
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

    // Configura as ações de input
    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
    {
        // Configura o evento de clique do mouse
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
        // Verifica se estamos aguardando o clique no grid para mover o cubo
        if (bIsAwaitingTarget && SelectedCube)
        {
            TargetLocation = HitResult.ImpactPoint;
            MoveCubeToTarget(SelectedCube, TargetLocation);

            if (PathfindingController == nullptr)
                PathfindingController = Cast<APathfindingController>(UGameplayStatics::GetActorOfClass(GetWorld(), APathfindingController::StaticClass()));
            PathfindingController->MarkBlockedNodes();

            bIsCubeMoving = true; // O cubo está em movimento
            bIsAwaitingTarget = false; // Não aguardamos mais o clique no grid
        }
        // Clique em um cubo: Seleciona o cubo
        else if (UStaticMeshComponent* HitCube = Cast<UStaticMeshComponent>(HitResult.GetComponent()))
        {
            if (HitCube->ComponentTags.Num() > 0 && HitCube->ComponentTags[0].ToString().StartsWith("Cube"))
            {
                SelectCube(HitCube);

                // Inicia o timer para aguardar 1.5 segundos antes de permitir o clique no grid
                GetWorld()->GetTimerManager().SetTimer(AwaitingTargetTimerHandle, this, &AGridController::EnableAwaitingTarget, 1.5f, false);
            }
        }
    }
}

bool AGridController::GetHitResultOnGrid(FHitResult& OutHitResult)
{
    // Realiza o trace para obter a localização do hit no grid
    return GetHitResultUnderCursor(ECC_Visibility, true, OutHitResult);
}

void AGridController::UpdatePathAndMoveCube()
{
    if (PathfinderInstance && GridInstance)
    {
        // Calcula o caminho do início ao fim
        TArray<FVector> Path = PathfinderInstance->FindPathArray(StartLocation, EndLocation);

        // Opcionalmente: Visualiza o caminho
        for (int32 i = 0; i < Path.Num() - 1; i++)
        {
            DrawDebugLine(GetWorld(), Path[i], Path[i + 1], FColor::Blue, false, 5.0f, 0, 5.0f);
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
            CurrentPathIndex = 0;  // Reseta o índice do caminho
            bIsMoving = true;
            SelectedCube = Cube;   // Define o cubo selecionado para movimento
        }
    }
}

void AGridController::MoveAlongPath(float DeltaTime)
{
    if (CurrentPathIndex >= PathArray.Num())
    {
        // O cubo chegou ao final do caminho
        bIsMoving = false;
        bIsCubeMoving = false; // O cubo chegou ao destino
        ChangeCubeColor(SelectedCube, FLinearColor::Blue); // Muda a cor do cubo para azul
        SelectedCube = nullptr; // Limpa o cubo selecionado
        return;
    }

    ChangeCubeColor(SelectedCube, FLinearColor::Yellow); // Muda a cor do cubo enquanto se move

    FVector CurrentTarget = PathArray[CurrentPathIndex];
    FVector CurrentLocation = SelectedCube->GetComponentLocation();

    // Calcula a direção e a distância para o próximo nó
    FVector Direction = (CurrentTarget - CurrentLocation).GetSafeNormal();
    float DistanceToTarget = FVector::Dist(CurrentLocation, CurrentTarget);

    // Move o cubo em direção ao próximo nó
    FVector NewLocation = CurrentLocation + Direction * MoveSpeed * DeltaTime;

    // Se estamos perto o suficiente do próximo nó, avançamos para o próximo
    if (DistanceToTarget <= MoveSpeed * DeltaTime)
    {
        NewLocation = CurrentTarget;
        CurrentPathIndex++;
    }

    PathfindingController->VisualizePath(PathArray); // Visualiza o caminho
    SelectedCube->SetWorldLocation(NewLocation);

    // Desenha uma linha para visualizar o movimento
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
    bIsAwaitingTarget = true; // Agora podemos aguardar o segundo clique no grid
}
