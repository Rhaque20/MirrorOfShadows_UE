// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAttributeSet.h"


// void UBaseAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) 
// {
//     Super::PostGameplayEffectExecute(Data);

//     if(Data.EvaluatedData.Attribute == GetDamageAttribute())
//     {
//         const float LocalDamage = GetDamage();
//         SetDamage(0.0f);

//         if(LocalDamage > 0.f)
//         {
//             const float NewHealth = GetCurrentHP() - LocalDamage;
//             SetHealth(FMath::Clamp(NewHealth, 0.0f,GetHP()));
//         }
//     }
// }

// void UBaseAttributeSet::OnRep_CurrentHP(const FGameplayAttributeData& OldHP) 
// {
//     GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeSet,CurrentHP,OldHP);
// }

// void OnRep_HP(const FGameplayAttributeData& OldMaxHP)
// {
//     GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseAttributeSet,HP,OldMaxHP)
// }
