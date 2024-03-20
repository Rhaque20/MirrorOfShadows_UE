// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Skill.h"
#include "PlayerSkill.generated.h"

/**
 * 
 */
UCLASS()
class MIRROROFSHADOWS_API UPlayerSkill : public USkill
{
	GENERATED_BODY()
	private:
		UPROPERTY(EditDefaultsOnly)
		float SPCost = 0.f;
		
		float CurrentSP = 0.f;
};
