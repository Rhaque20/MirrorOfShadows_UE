// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAttributeSet.h"
#include "EnemyCharacterBase.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaggerComponent.h"

void UEnemyAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) 
{
    Super::PostGameplayEffectExecute(Data);

    AActor* TargetActor = nullptr;
	AController* TargetController = nullptr;
	// APlayerCharacters* TargetCharacter = nullptr;
	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		TargetActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		// TargetCharacter = Cast<APlayerCharacters>(TargetActor);
	}

    if(Data.EvaluatedData.Attribute == GetStanceDMGAttribute())
    {
        const float LocalStanceDMG = GetStanceDMG();
        SetStanceDMG(0.0f);
        UE_LOG(LogTemp, Display, TEXT("%s took %f stance damage"),*(TargetActor->GetName()),LocalStanceDMG);

        if(LocalStanceDMG > 0.0f)
        {
            const float NewStanceDMG = GetCurrentStance() + LocalStanceDMG;
            SetCurrentStance(FMath::Clamp(NewStanceDMG, 0.0f,GetMaxStance()));
            if (GetCurrentStance() >= GetMaxStance())
            {
                StanceBreak(Data);
            }
        }

    }
}

// void UEnemyAttributeSet::HandleEvaluatedData(const FGameplayEffectModCallbackData& Data, bool IsPostEffect) 
// {
//     AActor* TargetActor = nullptr;

//     if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
// 	{
// 		TargetActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
//     }
    
//     if(Data.EvaluatedData.Attribute == GetPoiseDMGAttribute())
// 	{
// 		const float LocalPoiseDMG = GetPoiseDMG();
//         SetPoiseDMG(0.0f);
//         UE_LOG(LogTemp, Display, TEXT("%s took %f poise damage"),*(TargetActor->GetName()),LocalPoiseDMG);

//         if(LocalPoiseDMG > 0.0f)
//         {
//             const float NewPoiseDMG = GetCurrentPoise() + LocalStanceDMG;
//             SetCurrentPoise(FMath::Clamp(NewPoiseDMG, 0.0f,GetMaxPoise()));
//         }
// 	}   
// }

void UEnemyAttributeSet::PoiseBreak(const FGameplayEffectModCallbackData& Data) 
{
    AActor* TargetActor = nullptr;
	AEnemyCharacterBase* TargetCharacter = nullptr;
	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		TargetActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		TargetCharacter = Cast<AEnemyCharacterBase>(TargetActor);
	}

    UE_LOG(LogTemp, Display, TEXT("Enemy got poise broken!"));

    TargetCharacter->ReturnStaggerComponent()->OnPoiseBreak();

}

void UEnemyAttributeSet::StanceBreak(const FGameplayEffectModCallbackData& Data) 
{
    AActor* TargetActor = nullptr;
	AEnemyCharacterBase* TargetCharacter = nullptr;
	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		TargetActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		TargetCharacter = Cast<AEnemyCharacterBase>(TargetActor);
	}

    UE_LOG(LogTemp, Display, TEXT("Enemy got stance broken!"));

    TargetCharacter->ReturnStaggerComponent()->OnStanceBreak();
}
