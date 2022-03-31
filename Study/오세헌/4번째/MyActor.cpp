// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//�����ȣ �ȿ��� �������Ʈ�� �θ�Ŭ������ ���
	static ConstructorHelpers::FClassFinder<APawn> BpClass(TEXT("/Game/StarterContent/Blueprints"));
	
	// �������Ʈ�� ���������� �Ҿ�Դ��� Ȯ���ϴ� �Լ�
	if (BpClass.Succeeded() && BpClass.Class != NULL) {
		//���� ���ϴ� �۾� ����
	}

	//������ ���� �������Ʈ �Ӹ� �ƴ϶� ���ҽ��� ������ �� �ִ�.
	UStaticMeshComponent* MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone"));
	if (MeshAsset.Succeeded() && MeshAsset.Object != NULL) {
		MeshComponent->SetStaticMesh(MeshAsset.Object);
	}
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

}

//��ũ��Ʈ�� �ٸ��̸����� ���� ��ư�� ������ ���ڵ��Ͽ� ������ ������. �״��� �����ڵ带 �����Ͽ� �ѱ��� �ȱ����� �� �� �ִ�.
//�ٵ� �׳� ����� �ϴ°� ����. ȥ���� ������

//ó�� ������ ������Ʈ�� �⺻������ Core, CoreUObject, Engine, InputCore ��� ����� ����ϰ� �ִ�.
//���ǿ����� UMG, Slatecore, Slate ��� ����� �߰��ϰ� �� ����

