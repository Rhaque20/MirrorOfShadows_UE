// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EntityData.h"
#include "PlayerData.generated.h"

/**
 * 
 */
class APlayerCharacters;
UCLASS()
class MIRROROFSHADOWS_API UPlayerData : public UEntityData
{
	GENERATED_BODY()
	public:
		TSubclassOf<APlayerCharacters> GetCharacterClass() const { return CharacterClass; }
	private:
		UPROPERTY(EditDefaultsOnly)
		TSubclassOf<APlayerCharacters> CharacterClass;
};
