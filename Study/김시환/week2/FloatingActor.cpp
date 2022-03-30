// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingActor.h"
#include "week2.h"
// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	FloatingSpeed = FVector(1.0f,1.0f,1.0f);
}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(MyLogCategory, Log, TEXT("Log Message")); //���θ��� ī�װ������� �α����
	FString Character = TEXT("ABC");
	int hp = 100;
	float Attack = 1.0f;
	UE_LOG(LogTemp, Log, TEXT("asdfasdf %s"), *Character); //������ ���ļ� ����ϱ�
	FVector CharacterPosition = GetActorLocation();
	UE_LOG(LogTemp, Log, TEXT("name = %s, HP= %d, Attack Speed = %f"), *Character, hp, Attack);

}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation(); // ���� actor�� ��ġ �ޱ�  FVector�� �ӵ��� ��ġ �޴� ����Ÿ��
	/*
	float DeltaHeight = FMath::Sin(runningtime + DeltaTime*FloatingSpeed) - FMath::Sin(runningtime); //�󸶳� ���������ϴ��� ���
	NewLocation.Z += DeltaHeight * 20.0f;
	runningtime += DeltaTime*FloatingSpeed;*/  // Z�࿡���� ����

	float DeltaX= FMath::Sin(runningtime.X + DeltaTime * FloatingSpeed.X) - FMath::Sin(runningtime.X);
	float DeltaY = FMath::Sin(runningtime.Y + DeltaTime * FloatingSpeed.Y) - FMath::Sin(runningtime.Y);
	float DeltaZ = FMath::Sin(runningtime.Z + DeltaTime * FloatingSpeed.Z) - FMath::Sin(runningtime.Z);
	NewLocation += FVector(DeltaX,DeltaY,DeltaZ) * 20.0f;
	runningtime += DeltaTime * FloatingSpeed;
	SetActorLocation(NewLocation);
}

