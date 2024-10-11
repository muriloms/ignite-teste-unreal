

#include "TopDownCameraPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ATopDownCameraPawn::ATopDownCameraPawn()
{
    PrimaryActorTick.bCanEverTick = true;

    // Create a scene component to serve as the root
    Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    RootComponent = Root;

    // Create the top-down camera component
    TopDownCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
    TopDownCamera->SetupAttachment(RootComponent);

    // Set the camera location and rotation for top-down view
    TopDownCamera->SetRelativeLocation(FVector(0.0f, 0.0f, 2500.0f)); // 1500 units above the grid
    TopDownCamera->SetRelativeRotation(FRotator(-30.0f, 0.0f, 0.0f)); // Looking straight down
}

// Called when the game starts or when spawned
void ATopDownCameraPawn::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ATopDownCameraPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Atualiza a posição da câmera com base no TargetActor, se definido
    if (TargetActor)
    {
        FVector TargetLocation = TargetActor->GetActorLocation();

        // Ajusta a posição da câmera para que ela orbite o cubo a partir de um ângulo lateral (90º)
        FVector CameraPosition = TargetLocation + FVector(500.0f, 0.0f, 300.0f); // Ajuste conforme necessário para distância e altura
        TopDownCamera->SetWorldLocation(CameraPosition);

        // Rotaciona a câmera para olhar para o cubo
        FRotator CameraRotation = FRotator(0.0f, 90.0f, 0.0f); // 90º de yaw
        TopDownCamera->SetWorldRotation(CameraRotation);
    }
}

// Function to center the camera on the grid
void ATopDownCameraPawn::CenterCameraOnGrid(FVector GridCenterLocation)
{
    SetActorLocation(GridCenterLocation);
}

void ATopDownCameraPawn::SetCameraPivot(AActor* NewTarget)
{
    if (NewTarget)
    {
        // Define o novo ator alvo como o pivô da câmera
        TargetActor = NewTarget;
    }
}