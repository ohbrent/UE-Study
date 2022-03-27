// Fill out your copyright notice in the Description page of Project Settings.


#include "Countdown.h"

// Sets default values
ACountdown::ACountdown()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false; //tick�Լ��� ������� ���� �� false�� �����س����� �ȴ�.


	CountdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Countdown text")); //�ʱ�ȭ, �𸮾󿡼� ������Ʈ �ʱ�ȭ�� ���� ���̹Ƿ� �� ����صξ����
	CountdownText->SetHorizontalAlignment(EHTA_Center); // ��� ����
	CountdownText->SetWorldSize(150.0f);//�ؽ�Ʈ ũ�� ����
	RootComponent = CountdownText;// �� ������ ��Ʈ ������Ʈ�� ����

	CountdownTime = 3;
}

// Called when the game starts or when spawned
void ACountdown::BeginPlay()
{
	Super::BeginPlay();

	UpdateTimeDisplay();
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ACountdown::AdvanceTimer, 1.0f, true);
}

void ACountdown::UpdateTimeDisplay()
{
	CountdownText->SetText(FString::FromInt(FMath::Max(CountdownTime, 0)));
}

void ACountdown::AdvanceTimer()
{
	--CountdownTime;
	UpdateTimeDisplay();

	if (CountdownTime < 1) {
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		CountdownHasFinished();
	}
}

void ACountdown::CountdownHasFinished_Implementation()
{
	CountdownText->SetText(TEXT("Go!"));
}
//Ÿ�̸� : ����ڰ� ������ �ð����� ����ڰ� ������ ������ ����ǵ��� �ϴ� ���̴�.
//		   Ư���� �������� ��� ����ǰų�, ���ӽð��� 1�ʰ� �Ѵ°�� ����ϴ� ���̴�.