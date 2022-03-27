// Fill out your copyright notice in the Description page of Project Settings.


#include "Logpratice.h"
#include "dcom.h"

// Sets default values
ALogpratice::ALogpratice()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALogpratice::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp,Log,TEXT("Log Message,BeginPlay"));
	//�α׻󼼼��� : ��µ� �α��� �߿䵵�� �ǹ�.
	//Fatal			�α׷� �׻� �ܼ� �� �α����Ͽ� ��µ�. �αװ� ��Ȱ��ȭ�� ���׿����� ��� �۵��� �ߴ�
	//Error			�ܼ� �� �α����Ͽ� ���. ������
	//Warning		�ܼ� �� �α����Ͽ� ���. �����
	//DisPlay		�ܼ� �� �α����Ͽ� ���
	//Log			���ӳ� �ܼ���� x , �α�����,�𸮾󿡵����� ��·α� O
	//Verbose		�α����Ͽ��� ���. ���ӳ��� �ֿܼ��� ��µ�������. �ڼ��� �α� �� ����� ��
	//VeryVerbose	Verbose�� ����. �뷮�� �α׸� ����ϴ� ���� �α��

	//�α� ī�װ�: ��µ� �αװ� � �ý��ۿ��� �߻��� �� �˷���
	//LogTemp		Ư���� ī������ ������ �ʰ� �ӽ÷� ������ �α�
	//�� �� 90�������� ������ �� �߿��� ���ϴ� ���� ���� ��� ���� ���� �� �� �ִ�.
	//DECLARE_LOG_CATEGORY_EXTERN ��� ��ɾ�� DEFINE_LOG_CATEGORY�� �� �̿��غ���.

	UE_LOG(LogTemp, Error, TEXT("Log Message,BeginPlay"));
	UE_LOG(LogTemp, Display, TEXT("Display Massage"));

	UE_LOG(MyLogCategory, Log, TEXT("My Category Log"));

	FString CharacterName = TEXT("Hiwer");
	UE_LOG(LogTemp, Log, TEXT("Character Name = %s"), *CharacterName);
	bool isAttackable = true;
	UE_LOG(LogTemp, Log, TEXT("Is Attackable = %s"), isAttackable ? TEXT("true") : TEXT("false"));
	int hp = 100;
	UE_LOG(LogTemp, Log, TEXT("Hp = %d"), hp);
	float AttackSpeed = 1.0f;
	UE_LOG(LogTemp, Log, TEXT("Attack Speed = %f"), AttackSpeed);
	FVector CP = GetActorLocation();
	UE_LOG(LogTemp, Log, TEXT("Psoition = %s"), *CP.ToString());
	UE_LOG(LogTemp, Log, TEXT("%s, &d, %f"), *CharacterName, hp, AttackSpeed);


}

// Called every frame
void ALogpratice::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

