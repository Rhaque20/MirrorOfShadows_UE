// Copyright 2023 Michał Ogiński.


#include "ISGameplayAbility.h"
#include "TimerManager.h"
#include "../Skill.h"


void UISGameplayAbility::InputReleased(const FGameplayAbilitySpecHandle Handle,
    const FGameplayAbilityActorInfo * ActorInfo,
    const FGameplayAbilityActivationInfo ActivationInfo)   
{
    if(!Handle.IsValid())
        return;

    if (GetWorld()->GetTimerManager().IsTimerActive(DelayTimerHandle))
    {
        GetWorld()->GetTimerManager().ClearTimer(DelayTimerHandle);
        UE_LOG(LogTemp, Display, TEXT("Continue Chain"));
    }
    else
    {
        UE_LOG(LogTemp,Display,TEXT("Starting Chain"));
    }
    
    GetWorld()->GetTimerManager().SetTimer(
    DelayTimerHandle, // handle to cancel timer at a later time
    this, // the owning object
    &UISGameplayAbility::EndAbilityModified, // function to call on elapsed
    2.f, // float delay until elapsed
    false); // looping?
}

void UISGameplayAbility::DoAnimation(int i) 
{
    
}

void UISGameplayAbility::InputPressed(const FGameplayAbilitySpecHandle Handle,
    const FGameplayAbilityActorInfo * ActorInfo,
    const FGameplayAbilityActivationInfo ActivationInfo) 
{
    
}

void UISGameplayAbility::EndAbilityModified() 
{
    UE_LOG(LogTemp, Display, TEXT("End Combo chain"));

    EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
}
