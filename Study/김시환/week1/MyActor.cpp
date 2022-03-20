// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	//������ �⺻���� �����ϴµ� ����ϴ� �Լ�(�׳� �������ε�?)
	TotalDamage = 200;
	DamageTimeInSeconds = 1.0f;
	CharacterName = TEXT("����");
	bAttackable = true;
	PrimaryActorTick.bCanEverTick = true; // Tick�Լ��� ����ϴ��� ����
	str = TEXT("Test");
	UE_LOG(LogTemp, Log, TEXT("constructor"));

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	//Actor�� ��ġ�� ���忡�� ������ ���۵ǰų� ���忡 �����Ǿ�����, �ѹ� ȣ��Ǵ� �Լ��� ������ �ʱ�ȭ�ϴµ� ���
	Super::BeginPlay();
	CallFromCPP2();
	UE_LOG(LogTemp, Log, TEXT("BeginPlay"));
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	//�� �����Ӹ��� ȣ��Ǵ� �Լ�(�׷��� �̸��� Tick�ΰ� ����)
	Super::Tick(DeltaTime); //DeltaTime�� �ֱٿ� ��������Ǿ����� Ȯ���ؼ� ����
	//Actor�� Ȱ��ȭ �Ǿ��ִµ��� ��� ����Ǳ⶧���� ����ó�� �ʿ���ٸ� ���ּ� ���� ���� ����.

	UE_LOG(LogTemp, Log, TEXT("Tick"));
}

void AMyActor::CalculateDPS() {
	DamagePerSecond = TotalDamage / DamageTimeInSeconds;
}

void AMyActor::CallFromCpp2_Implementation()
{
	str.Append(TEXT("_Implementation"));
}

void AMyActor::PostInitProperties()
{
	Super::PostInitProperties();
	CalculateDPS();
}

/*void AMyActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	CalculateDPS();
	Super::PostEditChangeChainProperty(PropertyChangedEvent);
}
*/