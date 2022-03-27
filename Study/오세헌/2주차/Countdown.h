// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//"Countdown.generated.h"������ ����
#include <Engine/Classes/Components/TextRenderComponent.h>
#include "Countdown.generated.h"

UCLASS()
class DCOM_API ACountdown : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACountdown();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:		
	//set time
	UPROPERTY(EditAnywhere)
	int32 CountdownTime;

	UTextRenderComponent* CountdownText;

	void UpdateTimeDisplay();

	void AdvanceTimer(); //timer�� ���ư��鼭 ȣ�� �� �Լ�

	//AdvanceTime�� ������ ��ŭ �۵��� �ڿ� ������ ó���� �ϱ����� �Լ�
	UFUNCTION(BlueprintNativeEvent)
	void CountdownHasFinished(); 
	virtual void CountdownHasFinished_Implementation();

	FTimerHandle CountdownTimerHandle; //timer�� ��Ʈ���ϱ����� ����ü
};
