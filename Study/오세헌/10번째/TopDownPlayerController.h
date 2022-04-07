// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TopDownPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWN_API ATopDownPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATopDownPlayerController();

	virtual void SetupInputComponent() override;

	virtual void PlayerTick(float DeltaTime) override;

	UFUNCTION()
		void MoveForward(float AxisValue);

	UFUNCTION()
		void MoveRight(float AxisValue);

	UFUNCTION()
		void LookMouseCursor();

};
