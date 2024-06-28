// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "../Enumerator/ItemEnum.h"

#include "Item.generated.h"

/**
 * 
 */
UCLASS()
class MIRROROFSHADOWS_API UItem : public UDataAsset
{
	GENERATED_BODY()
	protected:
		UPROPERTY(BlueprintReadOnly,EditDefaultsOnly)
		FString ItemName;
		UPROPERTY(BlueprintReadWrite,EditDefaultsOnly)
		EGrade ItemRarity;
		UPROPERTY(BlueprintReadOnly,EditDefaultsOnly)
		class UTexture2D* ItemIcon;
};
