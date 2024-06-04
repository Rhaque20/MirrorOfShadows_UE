// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StatComponent.h"

#include "PlayerStatComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),Blueprintable )
class MIRROROFSHADOWS_API UPlayerStatComponent : public UStatComponent
{
    GENERATED_BODY()
    
    protected:
        float SPGain = 1.0f;
};