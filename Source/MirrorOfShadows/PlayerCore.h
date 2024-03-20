// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatComponent.h"
#include "PlayerCore.generated.h"

/**
 * 
 */

class UPlayerSkill;
UCLASS()
class MIRROROFSHADOWS_API UPlayerCore : public UCombatComponent
{
	GENERATED_BODY()
	public:
		virtual void NormalAttack();
		virtual void Recover() override;

	protected:
		UPROPERTY(EditDefaultsOnly,Category = "Normal Attack")
		TArray<UPlayerSkill*> NormalAttacks;
		UPROPERTY(BlueprintReadWrite)
		int CurrentChain = 0;
	
};
