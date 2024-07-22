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
		float ResistInterruptMod = 1.f;

		UPROPERTY(EditDefaultsOnly,meta = (EditCondition = "HasDifferentPoiseDMG == false", EditConditionHides),Category="Stagger System")
		float PoiseDamage = 0.f;

		UPROPERTY(EditDefaultsOnly, meta = (EditCondition = "HasDifferentPoiseDMG == true", EditConditionHides),Category="Stagger System")
		TArray<float> PoiseDamageValues;

		UPROPERTY(EditDefaultsOnly,meta = (EditCondition = "HasDifferentStanceDMG == false", EditConditionHides),Category="Stagger System")
		float StanceDamage = 0.f;

		UPROPERTY(EditDefaultsOnly, meta = (EditCondition = "HasDifferentStanceDMG == true", EditConditionHides),Category="Stagger System")
		TArray<float> StanceDamageValues;

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

		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Multi-Hit Settings")
		bool HasDifferentStanceDMG = false;

		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Force Settings")
		UCurveFloat* LaunchCurve;

		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Force Settings")
		float LaunchForce = 100.f;

		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Force Settings")
		float KnockbackForce = 100.f;

		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Stagger System")
		bool IsParryable = true;
		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Stagger System")
		bool IsDodgeable = true;
	public:
		UFUNCTION(BlueprintCallable)
		UAnimMontage* GetAnimation(int index) const;
		UFUNCTION(BlueprintCallable)
		FVector GetHitBoxScale() const {return HitBoxScale;};

		UFUNCTION(BlueprintCallable)
		float ReturnSkillModifier(int index) const
		{
			if(SkillModifiers.Num() == 0 || !HasDifferentMods)
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
		float ReturnStanceDamage(int index) const
		{
			if (StanceDamageValues.Num() == 0 || !HasDifferentStanceDMG)
			{
				return StanceDamage;
			}

			return StanceDamageValues[index % StanceDamageValues.Num()];
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
