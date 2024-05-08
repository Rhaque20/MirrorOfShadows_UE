// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Skill.generated.h"

/**
 * 
 */
class UAnimationAsset;
UCLASS(Blueprintable)
class MIRROROFSHADOWS_API USkill : public UDataAsset
{
	GENERATED_BODY()
	protected:
		UPROPERTY(EditDefaultsOnly)
		FString SkillName;

		UPROPERTY(EditDefaultsOnly)
		float SkillModifier = 1.f;

		UPROPERTY(EditDefaultsOnly)
		float ResistInterruptMod = 0.f;

		UPROPERTY(EditDefaultsOnly)
		float PoiseDamage = 0.f;

		UPROPERTY(EditDefaultsOnly)
		TArray<UAnimMontage*> AnimationMontages;

		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
		FVector HitBoxScale = FVector(1,1,1);
		
		UPROPERTY(EditDefaultsOnly)
		bool IsProjectile = false;
	public:
		UFUNCTION(BlueprintCallable)
		UAnimMontage* GetAnimation(int index) const;
		FVector GetHitBoxScale() const {return HitBoxScale;};
};
