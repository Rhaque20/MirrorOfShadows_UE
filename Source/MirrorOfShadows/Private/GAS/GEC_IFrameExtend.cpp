// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/GEC_IFrameExtend.h"
#include "GAS/CustomAbilitySystemComponent.h"
#include "../BaseAttributeSet.h"


struct FIFrameDurationStatics
{
    //Target
    DECLARE_ATTRIBUTE_CAPTUREDEF(IFrameExtender);
    //FGameplayEffectAttributeCaptureDefinition IFrameExtenderDef;
 
    FIFrameDurationStatics()
    {
        //Source captures
        //IFrameExtenderDef = FGameplayEffectAttributeCaptureDefinition(UBaseAttributeSet::GetIFrameExtenderAttribute(), EGameplayEffectAttributeCaptureSource::Source, true);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet,IFrameExtender, Source,true);
    }
};
 
static FIFrameDurationStatics& IFrameStatics()
{
    static FIFrameDurationStatics Statics;
    return Statics;
}

UGEC_IFrameExtend::UGEC_IFrameExtend() 
{
	RelevantAttributesToCapture.Add(IFrameStatics().IFrameExtenderDef);
}

void UGEC_IFrameExtend::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const 
{
	UCustomAbilitySystemComponent* TargetASC = Cast<UCustomAbilitySystemComponent>(ExecutionParams.GetTargetAbilitySystemComponent());
 
    //Used to hold the evaluate params for the loop.
    FAggregatorEvaluateParameters EvaluateParameters;
 
    //Get all active effect handles.
    TArray<FActiveGameplayEffectHandle> Handles = TargetASC->GetAllActiveEffectHandles();
 
    //Loop over all active Effect handles.
    for (const FActiveGameplayEffectHandle Handle : Handles)
    {
        FActiveGameplayEffect* ActiveGE = TargetASC->GetActiveGameplayEffect_Mutable(Handle);
        //Didn't find an active GE or GE is not duration based, skip it. Only works on duration based GE's.
        // Perform a tag check
        if (!ActiveGE || ActiveGE->Spec.Def->DurationPolicy != EGameplayEffectDurationType::HasDuration)
        {
            // if(ActiveGE->Spec.Def->ApplicationTagRequirements)
            continue;
        }

        const FGameplayTagContainer GrantedTags = ActiveGE->Spec.Def->GetGrantedTags();

        if (GrantedTags.HasTag(FGameplayTag::RequestGameplayTag("Effect.Defensive.Evade")))
        {
            //Our new duration (calculated from AttemptCalculateCapturedAttributeMagnitudeWithBase)
            float NewDuration = 0.f;
    
            //We get the current iterated GE's asset tags and use this in the calculation
            FGameplayTagContainer Tags;
            ActiveGE->Spec.GetAllAssetTags(Tags);
    
            //Set the evalute params target tags to the current iterated GE's asset tags.
            EvaluateParameters.TargetTags = &Tags;
    
            //Here we run the calculation to get the new duration, passing in the current iterated GE's duration as a base value, before it gets manipulated.
            ExecutionParams.AttemptCalculateCapturedAttributeMagnitudeWithBase(FIFrameDurationStatics().IFrameExtenderDef, EvaluateParameters, ActiveGE->GetDuration(), NewDuration);

            UE_LOG(LogTemp, Display, TEXT("Extended IFrames of Dodge to %f"),NewDuration);
    
            //We set the GE's new duration, but clamp it so it is never 0.
            ActiveGE->Spec.Duration = FMath::Max(NewDuration, 0.01);
    
            //This will remove the GE if it has expired and update the timers if necessary
            TargetASC->CheckActiveEffectDuration(Handle);

            break;
        }
    }
}