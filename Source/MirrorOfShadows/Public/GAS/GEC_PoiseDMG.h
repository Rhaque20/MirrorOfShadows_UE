// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GEC_PoiseDMG.generated.h"

/**
 * 
 */
UCLASS()
class MIRROROFSHADOWS_API UGEC_PoiseDMG : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};

