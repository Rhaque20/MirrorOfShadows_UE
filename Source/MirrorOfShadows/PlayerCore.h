// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatComponent.h"
#include "Public/Enumerator/AttackCategoryEnum.h"

#include "PlayerCore.generated.h"

/**
 * 
 */

class UPlayerSkill;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),Blueprintable )
class MIRROROFSHADOWS_API UPlayerCore : public UCombatComponent
{
	GENERATED_BODY()
	public:
		UPlayerCore();
		virtual void NormalAttack();
		UFUNCTION(BlueprintCallable)
		virtual void Recover() override;
		UFUNCTION(BlueprintCallable)
		virtual void Hit() override;
		UFUNCTION(BlueprintCallable)
		virtual void ResetAttackState();
		virtual void SetUpAttackAnim() override;

		UFUNCTION(BlueprintCallable)
		void SetSkillRef(int index);

		UFUNCTION(BlueprintCallable)
		void SetCanBuffer(bool val) { CanBuffer = val; }
		UFUNCTION(BlueprintCallable)
		void SetHasBuffer(bool val) {
			if (val)
			{
				UE_LOG(LogTemp, Display, TEXT("Setting the buffer"));
			}
			else
			{
				UE_LOG(LogTemp, Display, TEXT("Removing the buffer"));
			}

			HasBuffer = val;
		}

		UFUNCTION(BlueprintCallable)
		bool ReturnCanBuffer() const { return CanBuffer; }
		UFUNCTION(BlueprintCallable)
		bool ReturnHasBuffer() const { return HasBuffer; }

		UPlayerSkill* ReturnActiveSkill(EAttackCategory AttackType);

		int GetCurrentChain()
		{
			return CurrentChain;
		}

		int GetMaxAttackChain(bool onAir)
		{
			return onAir ? AerialAttacks.Num() : NormalAttacks.Num();
		}

	protected:
		UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Normal Attack")
		TArray<UPlayerSkill*> NormalAttacks;

		UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Normal Attack")
		TArray<UPlayerSkill*> AerialAttacks;

		UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Normal Attack")
		UPlayerSkill* HeavyAttack;

		UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Skill Data")
		TArray<UPlayerSkill*> Skills;

		class APlayerCharacters* OwningPlayer;

		UPROPERTY(BlueprintReadWrite)
		int CurrentChain = 0;
		UPROPERTY(BlueprintReadWrite)
		bool CanBuffer = false;
		UPROPERTY(BlueprintReadWrite)
		bool HasBuffer = false;
		UPROPERTY(BlueprintReadOnly)
		bool EndOfChain = false;
	
};
