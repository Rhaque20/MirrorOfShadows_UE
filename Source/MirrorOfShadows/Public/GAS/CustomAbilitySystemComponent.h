// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "CustomAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class MIRROROFSHADOWS_API UCustomAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

	public:
		FActiveGameplayEffect* GetActiveGameplayEffect_Mutable(FActiveGameplayEffectHandle Handle);
 
		/** Returns all active gameplay effect handles */
		TArray<FActiveGameplayEffectHandle> GetAllActiveEffectHandles() const;
	
		/** Checks the active effect duration and runs any logic, checks to see if the GE is expired and removes it. */
		void CheckActiveEffectDuration(const FActiveGameplayEffectHandle& Handle);
	
};

