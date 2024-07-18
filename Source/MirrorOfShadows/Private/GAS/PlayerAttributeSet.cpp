#include "GAS/PlayerAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Math/UnrealMathUtility.h"
#include "../PlayerCharacters.h"
#include "Components/StaggerComponent.h"

void UPlayerAttributeSet::HandleEvaluatedData(const FGameplayEffectModCallbackData& Data, bool IsPostEffect) 
{
    // if (Data.EvaluatedData.Attribute == GetHPAttribute())
	// {
	// 	UE_LOG(LogTemp, Display, TEXT("HP is now %f with max HP of %f"),GetCurrentHP(),GetHP());
	// }
	// else if(Data.EvaluatedData.Attribute == GetATKBonusPercentAttribute())
	// {
	// 	UE_LOG(LogTemp, Display, TEXT("Gained %f Percent ATK"),GetATKBonusPercent());
	// }

    // Super::HandleEvaluatedData(Data,IsPostEffect);


    if(IsPostEffect)
    {
        if (Data.EvaluatedData.Attribute == GetHPAttribute() || 
        Data.EvaluatedData.Attribute == GetHPBonusFlatAttribute() ||
        Data.EvaluatedData.Attribute == GetHPBonusPercentAttribute())
        {
            RecalculateTotalHP();
        }
        else if(Data.EvaluatedData.Attribute == GetCurrentHPAttribute())
        {
            RecalculateTotalHP();
            UE_LOG(LogTemp, Display, TEXT("Setting Ratio of current HP"));
            HPRatio = GetCurrentHP()/GetTotalHP();
        }
    }
}

void UPlayerAttributeSet::RecalculateTotalHP()
{
    float HPBonusfromPercent = (float)FMath::RoundToInt(GetHP() * GetHPBonusPercent());
    float HPBonusfromFlat = GetHPBonusFlat();
    float FinalHP = GetHP() + HPBonusfromPercent + HPBonusfromFlat;
    SetTotalHP(FinalHP);
    SetCurrentHP(FinalHP * HPRatio);
    UE_LOG(LogTemp, Display, TEXT("HP Ratio is %f"),HPRatio);
    UE_LOG(LogTemp, Display, TEXT("Recalculated HP is %f using base HP of %f, HP Bonus %f, and HP Flat Bonus %f"),FinalHP,
    GetHP(),HPBonusfromPercent,HPBonusfromFlat);
}

void UPlayerAttributeSet::PoiseBreak(const FGameplayEffectModCallbackData& Data) 
{
	AActor* TargetActor = nullptr;
	APlayerCharacters* TargetCharacter = nullptr;
	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		TargetActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		TargetCharacter = Cast<APlayerCharacters>(TargetActor);

        TargetCharacter->ReturnStaggerComponent()->OnPoiseBreak();
	}
}