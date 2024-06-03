// Fill out your copyright notice in the Description page of Project Settings.


#include "CecileCore.h"

#include "Engine/EngineTypes.h"

UCecileCore::UCecileCore()
{
    
}

void UCecileCore::InflictDamage(TArray<FHitResult> Results) 
{
    bool TriggeredShake = false;
    for(FHitResult Hit : Results)
    {
        if(IsBehindTarget(Hit.GetActor()))
        {
            UE_LOG(LogTemp, Display, TEXT("Struck behind %s"),*(Hit.GetActor()->GetName()));
        }
        else
        {
            UE_LOG(LogTemp, Display, TEXT("Struck %s"),*(Hit.GetActor()->GetName()));
        }

        if(HitCameraShakeClass && !TriggeredShake)
        {
            GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(HitCameraShakeClass);
            TriggeredShake = true;
        }
    }
}