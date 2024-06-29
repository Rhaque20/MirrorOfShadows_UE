// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/GEC_AttackScale.h"
#include "../BaseAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Math/UnrealMathUtility.h"

struct FDamageStatics
{
    DECLARE_ATTRIBUTE_CAPTUREDEF(DEF);
    DECLARE_ATTRIBUTE_CAPTUREDEF(ATK);
    DECLARE_ATTRIBUTE_CAPTUREDEF(HP);
    DECLARE_ATTRIBUTE_CAPTUREDEF(ATKBonusPercent);
    DECLARE_ATTRIBUTE_CAPTUREDEF(SkillModifier);
    DECLARE_ATTRIBUTE_CAPTUREDEF(Damage);

    FDamageStatics()
    {
        DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet,HP, Source,false);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet,ATK, Source,false);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet,SkillModifier, Source,false);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet,ATKBonusPercent,Source,false);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet,Damage, Target,false);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet,DEF, Target,false);
    }
};

static const FDamageStatics DamageStatics()
{
    static FDamageStatics DMGStatics;
    return DMGStatics;
}

UGEC_AttackScale::UGEC_AttackScale() 
{
	RelevantAttributesToCapture.Add(DamageStatics().DEFDef);
    RelevantAttributesToCapture.Add(DamageStatics().ATKDef);
    RelevantAttributesToCapture.Add(DamageStatics().HPDef);
    RelevantAttributesToCapture.Add(DamageStatics().DamageDef);
    RelevantAttributesToCapture.Add(DamageStatics().SkillModifierDef);
    RelevantAttributesToCapture.Add(DamageStatics().ATKBonusPercentDef);
}

void UGEC_AttackScale::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const 
{
	UAbilitySystemComponent* SourceASC = ExecutionParams.GetSourceAbilitySystemComponent();
    UAbilitySystemComponent* TargetASC = ExecutionParams.GetTargetAbilitySystemComponent();
    AActor* TargetActor = TargetASC ? TargetASC->GetAvatarActor() : nullptr;
    AActor* OwningActor = SourceASC ? SourceASC->GetAvatarActor() : nullptr;

    const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();
    const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
    const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags. GetAggregatedTags();

    FAggregatorEvaluateParameters EvaluationParameters;
    EvaluationParameters.SourceTags = SourceTags;
    EvaluationParameters.TargetTags = TargetTags;

    // Retrieve the InDamage value passed to Assign Tag Set By Caller Magnitude (On output of Make Outgoing Spec)
    float SkillModifier = 0.0f;

    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().SkillModifierDef, EvaluationParameters, SkillModifier);

    FGameplayEffectSpec* MutableSpec = ExecutionParams.GetOwningSpecForPreExecuteMod();

    float FinalAttack = 0.0f;
    float FinalDefense = 0.0f;
    float FinalDamage = 0.0f;
    float ATKBonusPercent = 0.0f;

    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().ATKDef, EvaluationParameters, FinalAttack);
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().ATKBonusPercentDef, EvaluationParameters, ATKBonusPercent);
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().DEFDef, EvaluationParameters, FinalDefense);

    UE_LOG(LogTemp, Display, TEXT("Attacker's Attack: %f and Defender's Defense: %f"),FinalAttack,FinalDefense);

    FinalAttack *= (1 + ATKBonusPercent);

    UE_LOG(LogTemp, Display, TEXT("Attacker's Attack with ATK Bonus: %f"),FinalAttack);

    FinalDamage = (FinalAttack * SkillModifier)/(FinalDefense/300 + 1);

    FinalDamage = FMath::Floor(FinalDamage);

    UE_LOG(LogTemp, Display, TEXT("Final Damage calculated: %f"),FinalDamage);

    OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(DamageStatics().DamageProperty, EGameplayModOp::Override, FinalDamage));

}
