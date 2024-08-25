#include "RPGCharacterBase.h"
#include "GAS/CustomAbilitySystemComponent.h"


UAbilitySystemComponent* ARPGCharacterBase::GetAbilitySystemComponent() const 
{
    return AbilitySystem;
}

ARPGCharacterBase::ARPGCharacterBase() 
{
    HitBoxLocation = CreateDefaultSubobject<USceneComponent>("Hitbox Spot Visual");
    HitBoxLocation->SetupAttachment(RootComponent);
}