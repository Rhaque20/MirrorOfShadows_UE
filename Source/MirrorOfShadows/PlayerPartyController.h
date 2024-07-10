// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerPartyController.generated.h"

/**
 * 
 */
class UPlayerData;
class APlayerCharacters;

UCLASS()
class MIRROROFSHADOWS_API APlayerPartyController : public APlayerController
{
	GENERATED_BODY()
	public:
		APlayerPartyController();
		void SetUpMembers(TArray<APlayerCharacters*> PartyList);
	private:
		int CurrentCharacter = 0;
		int AliveMembers = 0;
	private:
		virtual void BeginPlay();
		UFUNCTION(BlueprintCallable)
		void SwapCharacterLeft();
		UFUNCTION(BlueprintCallable)
		void SwapCharacterRight();

		void SwapCharacter(int SwapToIndex);

	protected:
		TArray<APlayerCharacters*> SummonedActorReferences;
};
