// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"

#include "BaseAttributeSet.generated.h"

#define BASEGAS_ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
        GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
        GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
        GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
        GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class MIRROROFSHADOWS_API UBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

	// public:
	// 	void OnRep_CurrentHP(const FGameplayAttributeData& OldHP);
	// 	void OnRep_HP(const FGameplayAttributeData& OldMaxHP);

	public:
		UPROPERTY(EditAnywhere)
		FGameplayAttributeData CurrentHP;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet, CurrentHP);

		UPROPERTY()
		FGameplayAttributeData HP;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet, HP);

		UPROPERTY()
		FGameplayAttributeData ATK;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet, ATK);

		UPROPERTY()
		FGameplayAttributeData DEF;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet, DEF);

		UPROPERTY()
		FGameplayAttributeData Damage;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Damage);

	public:
		//virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

};
