// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingActor.h"

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
	
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	//Actor�� ������ġ�� ����Ÿ������ �������� �Լ�
	float DeltaX = (FMath::Sin(RunningTime.X + DeltaTime * FloatingSpeed.X) - FMath::Sin(RunningTime.X));
	float DeltaY = (FMath::Sin(RunningTime.Y + DeltaTime * FloatingSpeed.Y) - FMath::Sin(RunningTime.Y));
	float DeltaZ = (FMath::Sin(RunningTime.Z + DeltaTime * FloatingSpeed.Z) - FMath::Sin(RunningTime.Z));
	//sin�Լ��� ���Ʒ� �Դٰ��� �ϹǷ� �ε巯�� ������� ���Ʒ������� ���� �� �ִ�.
	NewLocation += FVector(DeltaX, DeltaY, DeltaZ) * 20.0f;

	RunningTime += DeltaTime * FloatingSpeed;
	//tick�Լ��� ����ǰ� ���� tick���� �ɸ��ð��� DeltaTime�̴�.

	SetActorLocation(NewLocation);
}

//���忡 ��ġ�� ������Ʈ�� �ν��Ͻ���� �θ���.
//������Ʈ �߰���ư���� �ν��Ͻ��� ���¸� ������ �� �ִ�. (�ܼ� ��ü�Ӹ� �ƴ϶� ����Ŀ, �������...)
//���� �������� �߰��� �� ������ �翬�� �ٸ� ���α׷����� ���� �͵� �� �� �ִ�.

//������ �гο��� ���ڸ� �ٲ۴ٰ� ���⼭ �ڵ尡 �ٲ����� �ʾҴ�.

//��� ���� ����
//�𸮾��� �Ϲ� c++ �ڵ�� �޸� ��� ���� ��ġ�� �߿��ϴ�.
//#include "FloatingActor.generated.h" ����� �߰��ؾ��Ѵ�.
//�������� �����ӵ������̶��
