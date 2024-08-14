#include "RPGCharacterBase.h"
#include "GAS/CustomAbilitySystemComponent.h"


UAbilitySystemComponent* ARPGCharacterBase::GetAbilitySystemComponent() const 
{
    return AbilitySystem;
}