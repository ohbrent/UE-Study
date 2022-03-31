// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "dcom5GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class DCOM5_API Adcom5GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "UMG_Game")
	void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);
	//TSubclassof : �������� ���� ���. <>�Ȱ� NewWidgetClass�� ��ġ�ϴ��� Ȯ��, ���ø� ���ڷ� ���� Ÿ���� ��ӹ��� Ÿ������ Ȯ��

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG_Game")
		TSubclassOf<UUserWidget> StartingWidgetClass;

	UPROPERTY()
		UUserWidget* CurrentWidget;
};
