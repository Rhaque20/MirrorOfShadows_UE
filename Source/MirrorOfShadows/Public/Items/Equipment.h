// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RPGItem.h"
#include "GameplayTagContainer.h"

#include "Equipment.generated.h"

/**
 * 
 */
UCLASS()
class MIRROROFSHADOWS_API UEquipment : public URPGItem
{
    GENERATED_BODY()
    protected:
        UPROPERTY(BlueprintReadWrite,EditDefaultsOnly,Category = "MainStat")
        FGameplayTag MainStat;
        UPROPERTY(BlueprintReadWrite, EditDefaultsOnly,Category = "MainStat")
        float MainStatValue = 0;

        UPROPERTY(BlueprintReadWrite, EditDefaultsOnly,Category = "Substats")
        TMap<FGameplayTag,float> SubStats;
        
};