// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "../Enumerator/ItemEnum.h"
#include "../Enumerator/ItemCategoryEnum.h"

#include "RPGItem.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class MIRROROFSHADOWS_API URPGItem : public UDataAsset
{
	GENERATED_BODY()
	protected:
		UPROPERTY(BlueprintReadOnly,EditDefaultsOnly)
		FString ItemName;
		UPROPERTY(BlueprintReadWrite,EditDefaultsOnly)
		EGrade ItemRarity;
		UPROPERTY(BlueprintReadWrite,EditDefaultsOnly)
		EItemCategory ItemCategory;

		UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Icon")
		class UPaperSprite* Icon;

};
