// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/GEC_PoiseDMG.h"
#include "../BaseAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Math/UnrealMathUtility.h"

// struct FDamageStatics
// {
//     DECLARE_ATTRIBUTE_CAPTUREDEF(PoiseDMG);
//     DECLARE_ATTRIBUTE_CAPTUREDEF(PoiseMod);

//     FDamageStatics()
//     {
//         DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet,PoiseDMG, Source,false);
//         DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet,PoiseMod, Target,false);
//     }
// };

// static const FDamageStatics DamageStatics()
// {
//     static FDamageStatics DMGStatics;
//     return DMGStatics;
// }

void UGEC_PoiseDMG::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const 
{
	
}