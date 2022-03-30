// Copyright Epic Games, Inc. All Rights Reserved.


#include "dcom5GameModeBase.h"
#include <Blueprint/UserWidget.h> //UUserWidget Ŭ������ ����ϱ� ����

void Adcom5GameModeBase::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}

	//�𸮾��� ������ �÷��� �ý��� ���� ������ ������ ���� ������ų �ʿ�� ����.
	if (NewWidgetClass != nullptr) {
		CurrentWidget = CreateWidget(GetWorld(), NewWidgetClass);
		if (CurrentWidget != nullptr) {
			CurrentWidget->AddToViewport();
		}
	}

}

void Adcom5GameModeBase::BeginPlay()
{
	Super::BeginPlay();						// ���������� �� �κп� �� �ܲ� �߰��ϱ� ���� ù �ٿ� ȣ��
	ChangeMenuWidget(StartingWidgetClass);	// ������ ���۵� �� UI�� ǥ���ϵ��� ����� ��
}
