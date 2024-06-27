// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Equipment.h"

#include "Armor.generated.h"

/**
 * 
 */
UCLASS()
class MIRROROFSHADOWS_API UArmor : public UEquipment
{
    GENERATED_BODY()

    protected:
        UPROPERTY(BlueprintReadWrite,EditDefaultsOnly,Category = "EquipSlot Tags")
        FGameplayTag EquipSlot;
};