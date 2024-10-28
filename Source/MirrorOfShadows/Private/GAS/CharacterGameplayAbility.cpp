// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/CharacterGameplayAbility.h"
#include "GAS/PlayerAbilitySystemComponent.h"

UCharacterGameplayAbility::UCharacterGameplayAbility() 
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerExecution;
    
    // ActivationBlockedTags.AddTag(FGameplayTag::RequestGameplayTag(FName("State.Dead")));
    // ActivationBlockedTags.AddTag(FGameplayTag::RequestGameplayTag(FName("Stat")))
}

void UCharacterGameplayAbility::OnAvatarSet(const FGameplayAbilityActorInfo *ActorInfo, const FGameplayAbilitySpec& Spec) 
{
	Super:: OnAvatarSet(ActorInfo,Spec);

    if(ActivateAbilityOnGranted)
    {
        ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle,false);
    }
}