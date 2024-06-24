// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Skill.h"
#include "EnemySkill.generated.h"

/**
 * 
 */
UCLASS()
class MIRROROFSHADOWS_API UEnemySkill : public USkill
{
	GENERATED_BODY()
	protected:
		UPROPERTY(EditDefaultsOnly)
		float MaxCooldown = 0.f;
		UPROPERTY(EditDefaultsOnly)
		float StartCooldown = 0.f;
};
