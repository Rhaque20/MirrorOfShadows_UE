// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCore.h"
#include "CecileCore.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),Blueprintable )
class MIRROROFSHADOWS_API UCecileCore : public UPlayerCore
{
	GENERATED_BODY()
	public:
		UCecileCore();
		virtual void InflictDamage(TArray<FHitResult> Results) override;
};
