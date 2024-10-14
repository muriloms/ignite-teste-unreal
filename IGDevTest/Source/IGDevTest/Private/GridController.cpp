// Fill out your copyright notice in the Description page of Project Settings.


#include "GridController.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "PathfindingGrid.h"
#include "Pathfinder.h"
#include "PathfindingController.h"
#include "GridObject.h"
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

        // Liga o movimento de olhar para o InputAction AI_Look
        EnhancedInputComponent->BindAction(AI_Look, ETriggerEvent::Triggered, this, &AGridController::Look);

        // Liga o botão direito do mouse
        EnhancedInputComponent->BindAction(AI_RightClick, ETriggerEvent::Started, this, &AGridController::OnRightMouseDown);
        EnhancedInputComponent->BindAction(AI_RightClick, ETriggerEvent::Completed, this, &AGridController::OnRightMouseUp);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("'%s' Failed to find an Enhanced Input Component!"), *GetNameSafe(this));
    }
}

void AGridController::Look(const FInputActionValue& Value)
{
    // Verifica se o botão direito do mouse está pressionado
    if (!bIsRightMouseButtonDown)
    {
        return; // Não faz nada se o botão direito não estiver pressionado
    }

    const FVector2D LookAxisVector = Value.Get<FVector2D>();

    // Verifica se o Pawn controlado é do tipo ATopDownCameraPawn
    ATopDownCameraPawn* CameraPawn = Cast<ATopDownCameraPawn>(GetPawn());
    if (CameraPawn)
    {
        // Passa os valores de input para a função MoveSpringArm no CameraPawn
        CameraPawn->MoveSpringArm(LookAxisVector);
    }
}

void AGridController::OnRightMouseDown(const FInputActionValue& Value)
{
    bIsRightMouseButtonDown = true;
}

void AGridController::OnRightMouseUp(const FInputActionValue& Value)
{
    bIsRightMouseButtonDown = false;
}

void AGridController::OnLeftMouseClick()
{
    if (bIsCubeMoving) return;
    FHitResult HitResult;
    if (GetHitResultUnderCursorForGrid(HitResult))
    {
        // Verifica se estamos aguardando o clique no grid para mover o cubo
        if (bIsAwaitingTarget && SelectedCube)
        {
            TargetLocation = HitResult.ImpactPoint;
            MoveCubeToTarget(SelectedCube, TargetLocation);

            bIsCubeMoving = true; // O cubo está em movimento
            bIsAwaitingTarget = false; // Não aguardamos mais o clique no grid
        }
        // Clique em um cubo: Seleciona o cubo
        else if (UStaticMeshComponent* HitMeshComponent = Cast<UStaticMeshComponent>(HitResult.GetComponent()))
        {
            // Obtém o AGridObject associado ao componente clicado
            AGridObject* HitGridObject = Cast<AGridObject>(HitMeshComponent->GetOwner());

            if (HitGridObject)
            {
                SelectCube(HitGridObject);

                // Agora o cubo clicado é um AGridObject
                ATopDownCameraPawn* PlayerPawn = Cast<ATopDownCameraPawn>(GetPawn());
                if (PlayerPawn)
                {
                    // Atualiza o pivô da câmera para o cubo clicado (AGridObject)
                    PlayerPawn->SetCameraPivot(HitGridObject);
                }

                // Inicia o timer para aguardar 1.5 segundos antes de permitir o clique no grid
                GetWorld()->GetTimerManager().SetTimer(AwaitingTargetTimerHandle, this, &AGridController::EnableAwaitingTarget, 1.5f, false);

                if (PathfindingController == nullptr)
                    PathfindingController = Cast<APathfindingController>(UGameplayStatics::GetActorOfClass(GetWorld(), APathfindingController::StaticClass()));
                PathfindingController->MarkBlockedNodes();
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
        TArray<FVector> Path = PathfinderInstance->FindPath(StartLocation, EndLocation);

        // Opcionalmente: Visualiza o caminho
        for (int32 i = 0; i < Path.Num() - 1; i++)
        {
            DrawDebugLine(GetWorld(), Path[i], Path[i + 1], FColor::Blue, false, 5.0f, 0, 5.0f);
        }
    }
}

void AGridController::SelectCube(AGridObject* Cube)
{
    SelectedCube = Cube;

    //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("CUBE")));

    ChangeCubeColor(Cube->GetCubeMesh(), FLinearColor::Red);
}

void AGridController::MoveCubeToTarget(AGridObject* Cube, const FVector& Target)
{
    if (PathfinderInstance == nullptr)
        PathfinderInstance = Cast<APathfinder>(UGameplayStatics::GetActorOfClass(GetWorld(), APathfinder::StaticClass()));
    if (GridInstance == nullptr)
        GridInstance = Cast<APathfindingGrid>(UGameplayStatics::GetActorOfClass(GetWorld(), APathfindingGrid::StaticClass()));

    if (PathfinderInstance && GridInstance)
    {
        StartLocation = Cube->GetCubeMesh()->GetComponentLocation();

        // Desenha a posição inicial do cubo para depuração
        DrawDebugSphere(GetWorld(), StartLocation, 25.0f, 12, FColor::Red, false, 5.0f);

        // Calcula o caminho entre a posição inicial e o ponto alvo
        PathArray = PathfinderInstance->FindPath(StartLocation, Target);

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
        ChangeCubeColor(SelectedCube->GetCubeMesh(), FLinearColor::Blue); // Muda a cor do cubo para azul
        SelectedCube = nullptr; // Limpa o cubo selecionado
        return;
    }

    ChangeCubeColor(SelectedCube->GetCubeMesh(), FLinearColor::Yellow); // Muda a cor do cubo enquanto se move

    FVector CurrentTarget = PathArray[CurrentPathIndex];
    FVector CurrentLocation = SelectedCube->GetCubeMesh()->GetComponentLocation();

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
    SelectedCube->SetActorLocation(NewLocation);

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
    bIsAwaitingTarget = true; // aguardar o segundo clique no grid
}
