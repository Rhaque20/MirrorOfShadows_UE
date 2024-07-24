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
	public:
		UPROPERTY(BlueprintReadOnly, Category = "Level")
		FGameplayAttributeData Level;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Level);

		UPROPERTY(BlueprintReadOnly, Category = "Current Health")
		FGameplayAttributeData CurrentHP;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet, CurrentHP);

		UPROPERTY(BlueprintReadOnly, Category = "Max Health")
		FGameplayAttributeData HP;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet, HP);

		UPROPERTY(BlueprintReadOnly, Category = "Total Health")
		FGameplayAttributeData TotalHP;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet, TotalHP);

		UPROPERTY(BlueprintReadOnly, Category = "Attack")
		FGameplayAttributeData ATK;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet, ATK);

		UPROPERTY(BlueprintReadOnly, Category = "Defense")
		FGameplayAttributeData DEF;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet, DEF);

		UPROPERTY(BlueprintReadOnly, Category = "Potency")
		FGameplayAttributeData POTENCY;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet, POTENCY);

		UPROPERTY(BlueprintReadOnly, Category = "Resistance")
		FGameplayAttributeData RESISTANCE;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet, RESISTANCE);

		UPROPERTY(BlueprintReadOnly, Category = "Critical Rate")
		FGameplayAttributeData CritRate;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet, CritRate);

		UPROPERTY(BlueprintReadOnly, Category = "Critical Damage")
		FGameplayAttributeData CritDMG;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet, CritDMG);

		UPROPERTY(BlueprintReadOnly, Category = "Damage")
		FGameplayAttributeData Damage;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Damage);

		UPROPERTY(BlueprintReadOnly, Category = "PoiseDMG")
		FGameplayAttributeData PoiseDMG;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet, PoiseDMG);

		UPROPERTY(BlueprintReadOnly, Category = "HP Bonus %")
		FGameplayAttributeData HPBonusPercent;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet, HPBonusPercent);

		UPROPERTY(BlueprintReadOnly, Category = "ATK Bonus %")
		FGameplayAttributeData ATKBonusPercent;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet, ATKBonusPercent);

		UPROPERTY(BlueprintReadOnly, Category = "DEF Bonus %")
		FGameplayAttributeData DEFBonusPercent;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet, DEFBonusPercent);

		UPROPERTY(BlueprintReadWrite, Category = "Skill Modifier")
		FGameplayAttributeData SkillModifier;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet, SkillModifier);

		UPROPERTY(BlueprintReadOnly, Category = "DMG Resistance")
		FGameplayAttributeData DMGRes;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet, DMGRes);

		UPROPERTY(BlueprintReadOnly, Category = "BlockPower")
		FGameplayAttributeData BlockPower;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet, BlockPower);
		
		UPROPERTY(BlueprintReadOnly, Category = "Poise Mod")
		FGameplayAttributeData PoiseMod;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet,PoiseMod);

		UPROPERTY(BlueprintReadOnly, Category = "Current Poise")
		FGameplayAttributeData CurrentPoise;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet,CurrentPoise);

		UPROPERTY(BlueprintReadOnly, Category = "Max Poise")
		FGameplayAttributeData MaxPoise;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet,MaxPoise);

		UPROPERTY(BlueprintReadOnly, Category = "Attack Speed")
		FGameplayAttributeData AttackSpeed;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet,AttackSpeed);

		UPROPERTY(BlueprintReadOnly, Category = "Charge Rate")
		FGameplayAttributeData ChargeRate;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet,ChargeRate);

		UPROPERTY(BlueprintReadOnly, Category = "Total DMG Boost")
		FGameplayAttributeData TotalDMGBoost;
		BASEGAS_ATTRIBUTE_ACCESSORS(UBaseAttributeSet,TotalDMGBoost);

	public:
		virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	protected:
		float HPRatio = 1.0f;
		virtual void HandleEvaluatedData(const FGameplayEffectModCallbackData& Data, bool IsPostEffect);
		virtual void PoiseBreak(const FGameplayEffectModCallbackData& Data);
	protected:
		UFUNCTION(BlueprintCallable)
		virtual void RecalculateTotalHP();

};
