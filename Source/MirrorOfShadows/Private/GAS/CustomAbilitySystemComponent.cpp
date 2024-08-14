// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/CustomAbilitySystemComponent.h"

FActiveGameplayEffect* UCustomAbilitySystemComponent::GetActiveGameplayEffect_Mutable(FActiveGameplayEffectHandle Handle) 
{
	return ActiveGameplayEffects.GetActiveGameplayEffect(Handle);
}

TArray<FActiveGameplayEffectHandle> UCustomAbilitySystemComponent::GetAllActiveEffectHandles() const
{
	return ActiveGameplayEffects.GetAllActiveEffectHandles();
}

void UCustomAbilitySystemComponent::CheckActiveEffectDuration(const FActiveGameplayEffectHandle& Handle) 
{
	ActiveGameplayEffects.CheckDuration(Handle);
}