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
		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Cooldown")
		float MaxCooldown = 0.f;
		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Cooldown")
		float StartCooldown = 0.f;
		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Cooldown")
		float InternalCooldown = 0.f;
		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Stance System")
		bool IsFrenzy = false;// if true, attack will NOT trigger an stance interrupt until the last hit.
};
