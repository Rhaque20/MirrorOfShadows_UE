// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Components/StaggerComponent.h"

#include "RPGCharacterBase.generated.h"


class UStaggerComponent;
UCLASS()
class MIRROROFSHADOWS_API ARPGCharacterBase : public ACharacter,public IAbilitySystemInterface
{
    GENERATED_BODY()
    public:
        ARPGCharacterBase();
        virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

        UStaggerComponent* ReturnStaggerComponent() const
        {
            return StaggerComponent;
        }

        UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
        void PerformDodge();

        UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
        void CancelDodge();

        UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
        void OnDeath();

        UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
        void DisplayDamageNumber(const struct FGameplayTagContainer& Container, float Damage, int DidHit);

        UFUNCTION(BlueprintCallable)
        virtual void AutoTarget();

    protected:
        UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
        class UCustomAbilitySystemComponent* AbilitySystem;

        UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "StaggerComponent")
	    UStaggerComponent* StaggerComponent;

        UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Mobility")
        bool CanMove = true;

        UPROPERTY(BlueprintReadWrite, Category = "Aerial Variables")
        bool OnGround = true;
        UPROPERTY(BlueprintReadWrite, Category = "Aerial Variables")
        float AerialVelocity = 0.f;
        UPROPERTY(BlueprintReadWrite, Category = "CurrentSkill")
        class USkill* ActiveSkill;

        UPROPERTY(BlueprintReadOnly, EditAnywhere,Category = "Hit System")
        USceneComponent* HitBoxLocation;

        UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Abilities")
        TArray<TSubclassOf<class UCharacterGameplayAbility>> Abilities;
};



