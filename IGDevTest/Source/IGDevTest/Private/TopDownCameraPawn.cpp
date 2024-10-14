

#include "TopDownCameraPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/PlayerController.h"

// Sets default values
ATopDownCameraPawn::ATopDownCameraPawn():
    TargetActor(nullptr)
{
    PrimaryActorTick.bCanEverTick = true;


    // Inicializar o bra�o de mola (SpringArm) e a c�mera
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 2500.0f; // Dist�ncia da c�mera ao alvo
    SpringArm->SetRelativeRotation(FRotator(-30.0f, 0.0f, 0.0f)); // Inclina a c�mera em -30�
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
        // Atualiza o ator que a c�mera vai seguir
        TargetActor = NewTargetActor;

        // Anexa o SpringArm ao cubo (TargetActor)
        SpringArm->AttachToComponent(TargetActor->GetRootComponent(), FAttachmentTransformRules::KeepWorldTransform);

        // Reposiciona o SpringArm no local correto em rela��o ao novo TargetActor
        SpringArm->SetWorldLocation(TargetActor->GetActorLocation());

        // Garantir que a c�mera esteja na posi��o correta imediatamente
        SpringArm->bDoCollisionTest = false;  // Desativa o teste de colis�o, se necess�rio
    }
}
void ATopDownCameraPawn::MoveSpringArm(FVector2D LookAxisVector)
{
    if (SpringArm)
    {
        // Ajusta a rota��o do SpringArm com base no input de Yaw e Pitch
        FRotator NewRotation = SpringArm->GetRelativeRotation();

        // Aplica o input de Yaw (eixo X)
        if (LookAxisVector.X != 0.f)
        {
            NewRotation.Yaw += LookAxisVector.X * LookSensitivity;  // Sensibilidade
        }

        // Aplica o input de Pitch (eixo Y), limitando o �ngulo
        if (LookAxisVector.Y != 0.f)
        {
            NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch + LookAxisVector.Y * LookSensitivity, -80.0f, -15.0f);
        }

        // Atualiza a rota��o do SpringArm
        SpringArm->SetRelativeRotation(NewRotation);
    }
}


