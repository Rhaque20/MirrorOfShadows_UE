// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "BasePlayerState.generated.h"

/**
 * 
 */
UCLASS()
class MIRROROFSHADOWS_API ABasePlayerState : public APlayerState
{
	GENERATED_BODY()
	public:
		UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
		void CancelSlowMotion();// Used for counter edge or incase some game over condition is met.
	protected:
		UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool inCounterWindow = false;
};
