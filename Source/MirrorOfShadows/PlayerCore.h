// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatComponent.h"
#include "PlayerCore.generated.h"

/**
 * 
 */

class UPlayerSkill;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),Blueprintable )
class MIRROROFSHADOWS_API UPlayerCore : public UCombatComponent
{
	GENERATED_BODY()
	public:
		virtual void NormalAttack();
		UFUNCTION(BlueprintCallable)
		virtual void Recover() override;
		UFUNCTION(BlueprintCallable)
		virtual void Hit() override;
		UFUNCTION(BlueprintCallable)
		virtual void ResetAttackState();
		virtual void SetUpAttackAnim() override;

	protected:
		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Normal Attack")
		TArray<UPlayerSkill*> NormalAttacks;

		UPROPERTY(BlueprintReadWrite)
		int CurrentChain = 0;
		UPROPERTY(BlueprintReadWrite)
		bool CanBuffer = false;
		UPROPERTY(BlueprintReadWrite)
		bool HasBuffer = false;
		UPROPERTY(BlueprintReadOnly)
		bool EndOfChain = false;
	
};
