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

		UPROPERTY(EditDefaultsOnly, meta = (EditCondition = "HasDifferentMods == false", EditConditionHides))
		float SkillModifier = 1.f;

		UPROPERTY(EditDefaultsOnly, meta = (EditCondition = "HasDifferentMods == true", EditConditionHides))
		TArray<float> SkillModifiers;

		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
		float ResistInterruptMod = 0.f;

		UPROPERTY(EditDefaultsOnly,meta = (EditCondition = "HasDifferentPoiseDMG == false", EditConditionHides))
		float PoiseDamage = 0.f;

		UPROPERTY(EditDefaultsOnly, meta = (EditCondition = "HasDifferentPoiseDMG == true", EditConditionHides))
		TArray<float> PoiseDamageValues;

		UPROPERTY(EditDefaultsOnly)
		TArray<UAnimMontage*> AnimationMontages;

		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
		FVector HitBoxScale = FVector(1,1,1);

		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,meta = (EditCondition = "HasDifferentLocations == false", EditConditionHides))
		FVector HitBoxLocation = FVector(1,1,1);

		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,meta = (EditCondition = "HasDifferentLocations == true", EditConditionHides))
		TArray<FVector> HitBoxLocations;
		
		UPROPERTY(EditDefaultsOnly)
		bool IsProjectile = false;

		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Multi-Hit Settings")
		bool HasDifferentMods = false;

		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Multi-Hit Settings")
		bool HasDifferentLocations = false;

		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Multi-Hit Settings")
		bool HasDifferentPoiseDMG = false;

		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Force Settings")
		UCurveFloat* LaunchCurve;

		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Force Settings")
		float LaunchForce = 100.f;
	public:
		UFUNCTION(BlueprintCallable)
		UAnimMontage* GetAnimation(int index) const;
		UFUNCTION(BlueprintCallable)
		FVector GetHitBoxScale() const {return HitBoxScale;};
		UFUNCTION(BlueprintCallable)
		float ReturnModifier() const {return SkillModifier;};

		UFUNCTION(BlueprintCallable)
		float ReturnModfierAtSequence(int index) const
		{
			if(SkillModifiers.Num() == 0)
			{
				return SkillModifier;
			}

			return SkillModifiers[index % SkillModifiers.Num()];
		};

		UFUNCTION(BlueprintCallable)
		float ReturnPoiseDamage(int index) const
		{
			if (PoiseDamageValues.Num() == 0 || !HasDifferentPoiseDMG)
			{
				return PoiseDamage;
			}

			return PoiseDamageValues[index % PoiseDamageValues.Num()];
		};

		UFUNCTION(BlueprintCallable)
		FVector ReturnLocation() const {return HitBoxLocation;};

		UFUNCTION(BlueprintCallable)
		FVector ReturnLocationAtSequence(int index) const
		{
			if (HitBoxLocations.Num() == 0)
				return HitBoxLocation;
			
			return HitBoxLocations[index % HitBoxLocations.Num()];
		};
};
