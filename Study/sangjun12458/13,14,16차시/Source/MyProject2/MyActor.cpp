﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include <Kismet/KismetSystemLibrary.h>

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<APawn> BpClass(TEXT("/Game/StarterContent/BP_TestClass"));
	if (BpClass.Succeeded() && BpClass.Class != NULL)
	{
		
	}

	UStaticMeshComponent* MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone"));
	if (MeshAsset.Succeeded() && MeshAsset.Object != NULL)
	{
		MeshComponent->SetStaticMesh(MeshAsset.Object);
	}

	korean = TEXT("나는 한글");
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Hello 2"));
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Hello 3"), true, true, FLinearColor::Green, 2.0f);
}

