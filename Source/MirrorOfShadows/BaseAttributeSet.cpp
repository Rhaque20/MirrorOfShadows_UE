// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAttributeSet.h"
#include "GameplayEffect.h"
#include "PlayerCharacters.h"
#include "RPGCharacterBase.h"
#include "GameplayEffectExtension.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"


void UBaseAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) 
{
    Super::PostGameplayEffectExecute(Data);

	// Getting the spec of the gameplay effect being applied
	FGameplayEffectContextHandle Context = Data.EffectSpec.GetContext();

	// Getting the ability system and their tags from the actor that applied the ability
	UAbilitySystemComponent* Source = Context.GetOriginalInstigatorAbilitySystemComponent();
	const FGameplayTagContainer& SourceTags = *Data.EffectSpec.CapturedSourceTags.GetAggregatedTags();
	FGameplayTagContainer SpecAssetTags;
	// Get the asset tags from the gameplay effect
	Data.EffectSpec.GetAllAssetTags(SpecAssetTags);

	// Get the Target actor, which should be our owner
	AActor* TargetActor = nullptr;
	AController* TargetController = nullptr;
	ARPGCharacterBase* TargetCharacter = nullptr;
	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		TargetActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		TargetCharacter = Cast<ARPGCharacterBase>(TargetActor);
	}

	// Get the Source actor
	AActor* SourceActor = nullptr;
	AController* SourceController = nullptr;
	ARPGCharacterBase* SourceCharacter = nullptr;
	if (Source && Source->AbilityActorInfo.IsValid() && Source->AbilityActorInfo->AvatarActor.IsValid())
	{
		SourceActor = Source->AbilityActorInfo->AvatarActor.Get();
		SourceController = Source->AbilityActorInfo->PlayerController.Get();
		if (SourceController == nullptr && SourceActor != nullptr)
		{
			if (APawn* Pawn = Cast<APawn>(SourceActor))
			{
				SourceController = Pawn->GetController();
			}
		}

		// Use the controller to find the source pawn
		if (SourceController)
		{
			SourceCharacter = Cast<ARPGCharacterBase>(SourceController->GetPawn());
		}
		else
		{
			SourceCharacter = Cast<ARPGCharacterBase>(SourceActor);
		}

		// Set the causer actor based on context if it's set
		if (Context.GetEffectCauser())
		{
			SourceActor = Context.GetEffectCauser();
		}
	}

    if(Data.EvaluatedData.Attribute == GetDamageAttribute())
    {
        const float LocalDamage = GetDamage();
        SetDamage(0.0f);

        UE_LOG(LogTemp, Display, TEXT("%s took %f damage"),*(TargetCharacter->GetName()),LocalDamage);

        // Fix apply damage here
		if (TargetActor != nullptr && SourceController != nullptr)
		{
			UClass *DamageTypeClass = UDamageType::StaticClass();
			UGameplayStatics::ApplyDamage(TargetActor,LocalDamage,SourceController,SourceActor,DamageTypeClass);
		}

        if(LocalDamage > 0.f)
        {
            const float NewHealth = GetCurrentHP() - LocalDamage;
            SetCurrentHP(FMath::Clamp(NewHealth, 0.0f,GetTotalHP()));
			UE_LOG(LogTemp, Display, TEXT("%s has %f HP remaining"),*(TargetCharacter->GetName()),GetCurrentHP());
			HPRatio = GetCurrentHP()/GetTotalHP();
			if (HPRatio <= 0.0f)
			{
				UE_LOG(LogTemp, Display, TEXT("%s is dead"), *(TargetCharacter->GetName()));
				TargetCharacter->OnDeath();
			}
        }
    }
	else if(Data.EvaluatedData.Attribute == GetPoiseDMGAttribute())
	{
		const float LocalPoiseDMG = GetPoiseDMG();
        SetPoiseDMG(0.0f);
        UE_LOG(LogTemp, Display, TEXT("%s took %f poise damage"),*(TargetActor->GetName()),LocalPoiseDMG);

        if(LocalPoiseDMG > 0.0f)
        {
            const float NewPoiseDMG = GetCurrentPoise() + LocalPoiseDMG;
            SetCurrentPoise(FMath::Clamp(NewPoiseDMG, 0.0f,GetMaxPoise()));

			if (GetCurrentPoise() >= GetMaxPoise())
			{
				PoiseBreak(Data);
			}
        }
	}
	else if(Data.EvaluatedData.Attribute == GetCurrentPoiseAttribute())
	{
		SetCurrentPoise(FMath::Clamp(GetCurrentPoise(), 0.0f,GetMaxPoise()));
	} 
	else
		HandleEvaluatedData(Data,true);
}

void UBaseAttributeSet::HandleEvaluatedData(const FGameplayEffectModCallbackData& Data, bool IsPostEffect) 
{
	if (Data.EvaluatedData.Attribute == GetHPAttribute())
	{
		RecalculateTotalHP();
		SetCurrentHP(GetHP());
		UE_LOG(LogTemp, Display, TEXT("HP is now %f with max HP of %f"),GetCurrentHP(),GetHP());
	}
	else if(Data.EvaluatedData.Attribute == GetATKBonusPercentAttribute())
	{
		UE_LOG(LogTemp, Display, TEXT("Gained %f Percent ATK"),GetATKBonusPercent());
	}
	
}

void UBaseAttributeSet::PoiseBreak(const FGameplayEffectModCallbackData& Data) 
{
	
}

void UBaseAttributeSet::RecalculateTotalHP()
{
	SetTotalHP(GetHP());
}

// void UBaseAttributeSet::OnRep_CurrentHP(const FGameplayAttributeData& OldHP) 
// {
//     GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeSet,CurrentHP,OldHP);
// }

// void OnRep_HP(const FGameplayAttributeData& OldMaxHP)
// {
//     GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeSet,HP,OldMaxHP)
// }
