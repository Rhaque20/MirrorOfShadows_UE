#include "RPGCharacterBase.h"
#include "GAS/CustomAbilitySystemComponent.h"
#include "../BaseAttributeSet.h"


UAbilitySystemComponent* ARPGCharacterBase::GetAbilitySystemComponent() const 
{
    return AbilitySystem;
}

void ARPGCharacterBase::AutoTarget()
{
}

void ARPGCharacterBase::SetSkillModifier(float modifier)
{
	if (AttributeSet)
	{
		AttributeSet->SetSkillModifier(modifier);
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("%s attribute set is null"), *GetName());
	}
}

ARPGCharacterBase::ARPGCharacterBase() 
{
    HitBoxLocation = CreateDefaultSubobject<USceneComponent>("Hitbox Spot Visual");
    HitBoxLocation->SetupAttachment(RootComponent);
	AttributeSet = CreateDefaultSubobject<UBaseAttributeSet>("BaseAttributeComponent");
}