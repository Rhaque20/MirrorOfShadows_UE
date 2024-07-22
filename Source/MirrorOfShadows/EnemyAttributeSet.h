// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAttributeSet.h"
#include "EnemyAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class MIRROROFSHADOWS_API UEnemyAttributeSet : public UBaseAttributeSet
{
	GENERATED_BODY()

	public:
		UPROPERTY(BlueprintReadOnly, Category = "Stance Damage")
		FGameplayAttributeData StanceDMG;
		BASEGAS_ATTRIBUTE_ACCESSORS(UEnemyAttributeSet,StanceDMG);

		UPROPERTY(BlueprintReadOnly, Category = "Current Stance")
		FGameplayAttributeData CurrentStance;
		BASEGAS_ATTRIBUTE_ACCESSORS(UEnemyAttributeSet,CurrentStance);

		UPROPERTY(BlueprintReadOnly, Category = "Max Stance Mod")
		FGameplayAttributeData MaxStance;
		BASEGAS_ATTRIBUTE_ACCESSORS(UEnemyAttributeSet,MaxStance);

	public:
		virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
		// virtual void HandleEvaluatedData(const FGameplayEffectModCallbackData& Data, bool IsPostEffect);
		virtual void PoiseBreak(const FGameplayEffectModCallbackData& Data) override;

		void StanceBreak(const FGameplayEffectModCallbackData& Data);
	
};
