// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "StatComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),Blueprintable )
class MIRROROFSHADOWS_API UStatComponent : public UActorComponent
{
    GENERATED_BODY()

    public:	
        // Sets default values for this component's properties
        UStatComponent();

    public:
        virtual int DamageCalculation(float Modifier, enum class EStats ScaleStat, UStatComponent AttackerStat);
        virtual float FinalStat(enum class EStats ScaleStat);

    protected:
        UPROPERTY(EditAnywhere, Category = "CombatStats");
        int MaxHealth = 1;
        UPROPERTY(EditAnywhere, Category = "CombatStats");
        int Attack = 0;
        UPROPERTY(EditAnywhere, Category = "CombatStats");
        int Defense = 0;
        UPROPERTY(EditAnywhere, Category = "CombatStats");
        float Potency = 0.0f;
        UPROPERTY(EditAnywhere, Category = "CombatStats");
        float Resistance = 0.0f;
        UPROPERTY(EditAnywhere, Category = "CombatStats");
        float CritRate = 0.05f;
        UPROPERTY(EditAnywhere, Category = "CombatStats");
        float CritDMG = 0.5f;

        int CurrentHealth = 0;
    
};