// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GEC_IFrameExtend.generated.h"

/**
 * 
 */
UCLASS()
class MIRROROFSHADOWS_API UGEC_IFrameExtend : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
	public:
		UGEC_IFrameExtend();
		virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};


