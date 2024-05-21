// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ISGameplayAbility.h"
#include "NormalAttackAbility.generated.h"

/**
 * 
 */
UCLASS()
class MIRROROFSHADOWS_API UNormalAttackAbility : public UISGameplayAbility
{
	GENERATED_BODY()

	protected:
		virtual void InputPressed
	(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo * ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo
	) override;

		virtual void DoAnimation(int i);

		virtual void Recover();
		virtual void HitScan() override;

	protected:
		int CurrentChain = 0;

	public:
		UFUNCTION(BlueprintCallable)
		void SetCurrentChain(int i);
	
};
