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
	private:
		class APlayerPartyController* MainController;
		UPROPERTY(EditAnywhere)
		TArray<class UPlayerData*> PartyMembers;
	
};
