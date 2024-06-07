// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "PlayerAbilitySystemComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FReceivedDamageDelegate, UPlayerAbilitySystemComponent*, SourceASC,float, UnmitigatedDamage, float, MitigatedDamage);
/**
 * 
 */
UCLASS()
class MIRROROFSHADOWS_API UPlayerAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

	public:
		bool CharacterAbilitiesGiven = false;
		bool StartupEffectsApplied = false;

		FReceivedDamageDelegate ReceivedDamage;

		virtual void ReceiveDamage(UPlayerAbilitySystemComponent* SourceASC, float UnmitigatedDamage, float MitigatedDamage);
	
};
