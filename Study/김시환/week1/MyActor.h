// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class FIRST_STUDY_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Damage") //���� ����
	int32 TotalDamage;
	UPROPERTY(EditAnywhere/*��ŰŸ�԰� ������ ��ġ�� �ν��Ͻ� ���� ����� ������Ƽâ���� ��������*/, BlueprintReadWrite/*�������Ʈ���� �б⾲�� ����*/, Category = "Damage"/*��������� ī�װ��� ������*/)
	float DamageTimeInSeconds;
	UPROPERTY(BlueprintReadOnly/*�������Ʈ���� �б⸸ ����*/, VisibleAnywhere/*�����Ұ�*/, Transient/*�ֹ߼��ƴ�*/, Category = "Damage") //���� ����
	float DamagePerSecond;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CharacterName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
	bool bAttackable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Damage")
	FString str;
	/*
	int8 i8; //����
	int16 i16;
	int32 i32;
	int64 i64;
	 
	uint8 ui8; //�����
	uint16 ui16;
	uint32 ui32;
	uint64 ui64;

	float f;
	double d;

	FString str; // TEXT ��ũ�� ���

	bool b;
	*/

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = "Damage")//�������Ʈ���� ��밡��
	void CalculateDPS();
	/*UFUNCTION(BlueprintImplementableEvent, Category = "Damage")//�������Ʈ���� �Լ��� ������ ���� ����
	void CallFromCpp();*/
	UFUNCTION(BlueprintNativeEvent, Category = "Damage")//�������Ʈ���� ������ �ȵǾ��� ��� cpp�Լ��� ������
	void CallFromCPP2();
	virtual void CallFromCpp2_Implementation();

	virtual void PostInitProperties() override; 
	//virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override; //�� ��������...
};
