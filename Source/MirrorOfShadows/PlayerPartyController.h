// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerPartyController.generated.h"

/**
 * 
 */
UCLASS()
class MIRROROFSHADOWS_API APlayerPartyController : public APlayerController
{
	GENERATED_BODY()
	public:
		APlayerPartyController();
	private:
		TArray<AActor*> PartyMembers;
		int CurrentCharacter = 0;
		int AliveMembers = 0;
	private:
		virtual void BeginPlay();
		UFUNCTION(BlueprintCallable)
		void SwapCharacterLeft();
		UFUNCTION(BlueprintCallable)
		void SwapCharacterRight();
};
