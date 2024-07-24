// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/GEC_AttackScale.h"
#include "../BaseAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/KismetMathLibrary.h"
#include "RPGCharacterBase.h"

struct FDamageStatics
{
    DECLARE_ATTRIBUTE_CAPTUREDEF(DEF);
    DECLARE_ATTRIBUTE_CAPTUREDEF(ATK);
    DECLARE_ATTRIBUTE_CAPTUREDEF(HP);
    DECLARE_ATTRIBUTE_CAPTUREDEF(ATKBonusPercent);
    DECLARE_ATTRIBUTE_CAPTUREDEF(SkillModifier);
    DECLARE_ATTRIBUTE_CAPTUREDEF(DMGRes);
    DECLARE_ATTRIBUTE_CAPTUREDEF(BlockPower);
    DECLARE_ATTRIBUTE_CAPTUREDEF(Damage);
    DECLARE_ATTRIBUTE_CAPTUREDEF(CritRate);
    DECLARE_ATTRIBUTE_CAPTUREDEF(CritDMG);

    FDamageStatics()
    {
        DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet,HP, Source,false);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet,ATK, Source,false);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet,CritRate, Source,false);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet,CritDMG, Source,false);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet,SkillModifier, Source,false);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet,ATKBonusPercent,Source,false);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet,DMGRes,Target,false);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet,BlockPower,Target,false);
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
    RelevantAttributesToCapture.Add(DamageStatics().DMGResDef);
    RelevantAttributesToCapture.Add(DamageStatics().BlockPowerDef);
    RelevantAttributesToCapture.Add(DamageStatics().ATKBonusPercentDef);
    RelevantAttributesToCapture.Add(DamageStatics().CritRateDef);
    RelevantAttributesToCapture.Add(DamageStatics().CritDMGDef);
}

bool UGEC_AttackScale::IsBlocked(AActor* Target, AActor* Attacker) const
{
    FVector AttackerVector = Attacker->GetActorForwardVector();
	FVector TargetLocation = Target->GetActorForwardVector();

	double dotProduct = UKismetMathLibrary::Dot_VectorVector(TargetLocation,AttackerVector);
	return dotProduct <= -0.7f;
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
    float FinalDMGRes = 0.0f;
    float BlockPower = 0.0f;
    float CriticalChance = 0.05f;
    float CriticalDMG = 0.0f;
    int DidHit = 0;// -1 = Missed, 0 = Hit, 1 = Critical Hit

    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().ATKDef, EvaluationParameters, FinalAttack);
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().ATKBonusPercentDef, EvaluationParameters, ATKBonusPercent);
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().DEFDef, EvaluationParameters, FinalDefense);
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().DMGResDef, EvaluationParameters, FinalDMGRes);
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().CritRateDef, EvaluationParameters, CriticalChance);

    if (IsBlocked(TargetActor,OwningActor) && TargetASC->HasMatchingGameplayTag(FGameplayTag::RequestGameplayTag("Effect.Defensive.Block")))
    {
        ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().BlockPowerDef, EvaluationParameters, BlockPower);
    }

    if(FMath::RandRange(1.0f, 100.0f) < CriticalChance)
    {
        UE_LOG(LogTemp, Display, TEXT("CRITICAL HIT!"));
        ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().CritDMGDef, EvaluationParameters, CriticalDMG);
        CriticalDMG = FMath::Max(CriticalDMG, 1.5f);
        DidHit = 1;
    }

    FinalDMGRes = FMath::Clamp(FinalDMGRes,-1.0f,0.75f);

    UE_LOG(LogTemp, Display, TEXT("Attacker's Attack: %f and Defender's Defense: %f"),FinalAttack,FinalDefense);

    FinalAttack *= (1 + ATKBonusPercent);

    UE_LOG(LogTemp, Display, TEXT("Attacker's Attack with ATK Bonus: %f"),FinalAttack);

    FinalDamage = (FinalAttack * SkillModifier)/(FinalDefense/300 + 1);
    FinalDamage *= (1 - FinalDMGRes) * (1 - BlockPower) * (1 + CriticalDMG);

    FinalDamage = FMath::Floor(FinalDamage);

    UE_LOG(LogTemp, Display, TEXT("Final Damage calculated: %f"),FinalDamage);

    OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(DamageStatics().DamageProperty, EGameplayModOp::Override, FinalDamage));

    Cast<ARPGCharacterBase>(TargetActor)->DisplayDamageNumber(*SourceTags,FinalDamage,DidHit);

}
