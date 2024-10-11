// Fill out your copyright notice in the Description page of Project Settings.


#include "PathfindGameModeBase.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/PlayerController.h"
#include "TopDownCameraPawn.h"

APathfindGameModeBase::APathfindGameModeBase()
{
    // Definir o pawn padrão para ser o TopDownCameraPawn
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_TopDownCameraPawn")); // Caminho para o BP do TopDownCameraPawn
    if (PlayerPawnBPClass.Class != nullptr)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }

    // Opcional: Definir o PlayerController se necessário
    PlayerControllerClass = APlayerController::StaticClass();
}
