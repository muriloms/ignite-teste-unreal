

#include "TopDownCameraPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/PlayerController.h"

// Sets default values
ATopDownCameraPawn::ATopDownCameraPawn():
    TargetActor(nullptr)
{
    PrimaryActorTick.bCanEverTick = true;


    // Inicializar o braço de mola (SpringArm) e a câmera
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 2500.0f; // Distância da câmera ao alvo
    SpringArm->SetRelativeRotation(FRotator(-30.0f, 0.0f, 0.0f)); // Inclina a câmera em -30º
    SpringArm->bEnableCameraLag = true;
    SpringArm->CameraLagSpeed = 3.0f;

    // Create the top-down camera component
    TopDownCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
    TopDownCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

    // Set the camera location and rotation for top-down view
    //TopDownCamera->SetRelativeLocation(FVector(0.0f, 0.0f, 2500.0f)); // 1500 units above the grid
    //TopDownCamera->SetRelativeRotation(FRotator(-30.0f, 0.0f, 0.0f)); // Looking straight down
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

}

// Function to center the camera on the grid
void ATopDownCameraPawn::CenterCameraOnGrid(FVector GridCenterLocation)
{
    SetActorLocation(GridCenterLocation);
}

void ATopDownCameraPawn::SetCameraPivot(AActor* NewTargetActor)
{
    if (NewTargetActor)
    {
        // Atualiza o ator que a câmera vai seguir
        TargetActor = NewTargetActor;

        // Anexa o SpringArm ao cubo (TargetActor)
        SpringArm->AttachToComponent(TargetActor->GetRootComponent(), FAttachmentTransformRules::KeepWorldTransform);

        // Reposiciona o SpringArm no local correto em relação ao novo TargetActor
        SpringArm->SetWorldLocation(TargetActor->GetActorLocation());

        // Garantir que a câmera esteja na posição correta imediatamente
        SpringArm->bDoCollisionTest = false;  // Desativa o teste de colisão, se necessário
    }
}
void ATopDownCameraPawn::MoveSpringArm(FVector2D LookAxisVector)
{
    if (SpringArm)
    {
        // Ajusta a rotação do SpringArm com base no input de Yaw e Pitch
        FRotator NewRotation = SpringArm->GetRelativeRotation();

        // Aplica o input de Yaw (eixo X)
        if (LookAxisVector.X != 0.f)
        {
            NewRotation.Yaw += LookAxisVector.X * LookSensitivity;  // Sensibilidade
        }

        // Aplica o input de Pitch (eixo Y), limitando o ângulo
        if (LookAxisVector.Y != 0.f)
        {
            NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch + LookAxisVector.Y * LookSensitivity, -80.0f, -15.0f);
        }

        // Atualiza a rotação do SpringArm
        SpringArm->SetRelativeRotation(NewRotation);
    }
}


