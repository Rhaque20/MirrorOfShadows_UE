// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GEC_AttackScale.generated.h"

/**
 * 
 */
UCLASS()
class MIRROROFSHADOWS_API UGEC_AttackScale : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
	public:
		UGEC_AttackScale();
		// Does the calculation for the effect
		virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
	
};


