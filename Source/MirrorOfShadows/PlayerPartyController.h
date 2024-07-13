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
		int AliveMembers = 0;

	protected:
		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category =" Lock On System")
		bool IsLockedOn = false;
		UPROPERTY(BlueprintReadWrite, Category =" Lock On System")
		AActor* LockOnTarget;
		UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		int CurrentCharacter = 0;
	private:
		virtual void BeginPlay();
		UFUNCTION(BlueprintCallable)
		void SwapCharacterLeft();
		UFUNCTION(BlueprintCallable)
		void SwapCharacterRight();

		void SwapCharacter(int SwapToIndex);

	protected:
		UPROPERTY(BlueprintReadWrite)
		TArray<APlayerCharacters*> SummonedActorReferences;
};
