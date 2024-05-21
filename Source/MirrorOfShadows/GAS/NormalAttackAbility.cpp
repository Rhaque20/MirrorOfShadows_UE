// Fill out your copyright notice in the Description page of Project Settings.


#include "NormalAttackAbility.h"
#include "AbilitySystemComponent.h"
#include "GameplayTagContainer.h"

#include "Abilities/Tasks/AbilityTask_WaitGameplayEvent.h"
#include "Abilities/GameplayAbilityTypes.h"


void UNormalAttackAbility::InputPressed(const FGameplayAbilitySpecHandle Handle,
    const FGameplayAbilityActorInfo * ActorInfo,
    const FGameplayAbilityActivationInfo ActivationInfo) 
{
    if(!Handle.IsValid())
        return;

}

void UNormalAttackAbility::DoAnimation(int i) 
{
    AActor* Owner = GetOwningActorFromActorInfo();
}

void UNormalAttackAbility::Recover() 
{
    
}

void UNormalAttackAbility::HitScan() 
{
    
}

void UNormalAttackAbility::SetCurrentChain(int i) 
{
    CurrentChain = i;
}
