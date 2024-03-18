// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCore.h"
#include "CecileCore.generated.h"

/**
 * 
 */
UCLASS()
class MIRROROFSHADOWS_API UCecileCore : public UPlayerCore
{
	GENERATED_BODY()
	public:
		UCecileCore();
		virtual void NormalAttack() override;
};
