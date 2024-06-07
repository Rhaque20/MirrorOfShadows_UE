// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/PlayerAbilitySystemComponent.h"

void UPlayerAbilitySystemComponent::ReceiveDamage(UPlayerAbilitySystemComponent* SourceASC, float UnmitigatedDamage, float MitigatedDamage) 
{
	ReceivedDamage.Broadcast(SourceASC,UnmitigatedDamage,MitigatedDamage);
}