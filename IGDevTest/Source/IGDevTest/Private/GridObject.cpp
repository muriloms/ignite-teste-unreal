// Fill out your copyright notice in the Description page of Project Settings.


#include "GridObject.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AGridObject::AGridObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Inicializa o componente Static Mesh (Cubo)
    CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
    RootComponent = CubeMesh; // Define o CubeMesh como o componente raiz

}

// Called when the game starts or when spawned
void AGridObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGridObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

