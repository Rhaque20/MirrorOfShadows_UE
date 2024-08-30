#include "RPGCharacterBase.h"
#include "GAS/CustomAbilitySystemComponent.h"


UAbilitySystemComponent* ARPGCharacterBase::GetAbilitySystemComponent() const 
{
    return AbilitySystem;
}

void ARPGCharacterBase::AutoTarget()
{
}

ARPGCharacterBase::ARPGCharacterBase() 
{
    HitBoxLocation = CreateDefaultSubobject<USceneComponent>("Hitbox Spot Visual");
    HitBoxLocation->SetupAttachment(RootComponent);
}