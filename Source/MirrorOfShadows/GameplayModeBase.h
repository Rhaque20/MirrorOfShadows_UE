// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameplayModeBase.generated.h"

/**
 * 
 */
UCLASS()
class MIRROROFSHADOWS_API AGameplayModeBase : public AGameModeBase
{
	GENERATED_BODY()

	public:
		void StartGame();
		virtual void BeginPlay() override;
	protected:
		TArray<class APlayerCharacters*> SummonedActors;
	
		class APlayerPartyController* PlayerPartyController;
		
		UPROPERTY(EditAnywhere,BlueprintReadWrite)
		TArray<class UPlayerData*> PartyMembers;
	
};
