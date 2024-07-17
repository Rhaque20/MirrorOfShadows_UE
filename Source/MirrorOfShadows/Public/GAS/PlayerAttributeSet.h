// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../BaseAttributeSet.h"
#include "PlayerAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class MIRROROFSHADOWS_API UPlayerAttributeSet : public UBaseAttributeSet
{
	GENERATED_BODY()
	public:
		UPROPERTY(BlueprintReadOnly, Category = "SPGain")
		FGameplayAttributeData SPGain;
		BASEGAS_ATTRIBUTE_ACCESSORS(UPlayerAttributeSet, SPGain);

        UPROPERTY(BlueprintReadOnly, Category = "HPBonusFlat")
		FGameplayAttributeData HPBonusFlat;
		BASEGAS_ATTRIBUTE_ACCESSORS(UPlayerAttributeSet, HPBonusFlat);

        UPROPERTY(BlueprintReadOnly, Category = "ATKBonusFlat")
		FGameplayAttributeData ATKBonusFlat;
		BASEGAS_ATTRIBUTE_ACCESSORS(UPlayerAttributeSet, ATKBonusFlat);

        UPROPERTY(BlueprintReadOnly, Category = "DEFBonusFlat")
		FGameplayAttributeData DEFBonusFlat;
		BASEGAS_ATTRIBUTE_ACCESSORS(UPlayerAttributeSet, DEFBonusFlat);

        UPROPERTY(BlueprintReadOnly, Category = "Special Stats")
		FGameplayAttributeData SPUseDown;
		BASEGAS_ATTRIBUTE_ACCESSORS(UPlayerAttributeSet, SPUseDown);

        UPROPERTY(BlueprintReadOnly, Category = "Special Stats")
		FGameplayAttributeData FuryPunisher;
		BASEGAS_ATTRIBUTE_ACCESSORS(UPlayerAttributeSet, FuryPunisher);

        UPROPERTY(BlueprintReadOnly, Category = "Special Stats")
		FGameplayAttributeData BreakPunisher;
		BASEGAS_ATTRIBUTE_ACCESSORS(UPlayerAttributeSet, BreakPunisher);

        UPROPERTY(BlueprintReadOnly, Category = "Special Stats")
		FGameplayAttributeData ComboStar;
		BASEGAS_ATTRIBUTE_ACCESSORS(UPlayerAttributeSet, ComboStar);

        UPROPERTY(BlueprintReadOnly, Category = "Special Stats")
		FGameplayAttributeData DeadlyHeal;
		BASEGAS_ATTRIBUTE_ACCESSORS(UPlayerAttributeSet, DeadlyHeal);

    protected:
        virtual void RecalculateTotalHP() override;
        virtual void HandleEvaluatedData(const FGameplayEffectModCallbackData& Data, bool IsPostEffect) override;
		virtual void PoiseBreak(const FGameplayEffectModCallbackData& Data) override;
};




