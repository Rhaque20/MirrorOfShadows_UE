// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "GameplayTagAssetInterface.h"

#include "EquipmentComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),Blueprintable )
class MIRROROFSHADOWS_API UEquipmentComponent : public UActorComponent,public IGameplayTagAssetInterface
{
    GENERATED_BODY()
    protected:
        UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Equipment")
	    TArray<class UArmor*> EquippedGear;

        UPROPERTY(BlueprintReadWrite, Category = "Gameplay Tag")
	    FGameplayTagContainer GameplayTagContainer;

    public:
        UFUNCTION(BlueprintCallable)
        void CheckSetBonus();

        virtual void GetOwnedGameplayTags(FGameplayTagContainer& OwnedTags) const override
        {
            OwnedTags = GameplayTagContainer; 
            return;
        }
};
