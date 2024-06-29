#include "GAS/PlayerAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Math/UnrealMathUtility.h"

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


    if(IsPostEffect)
    {
        if (Data.EvaluatedData.Attribute == GetHPAttribute() || 
        Data.EvaluatedData.Attribute == GetHPBonusFlatAttribute() ||
        Data.EvaluatedData.Attribute == GetHPBonusPercentAttribute())
        {
            RecalculateTotalHP();
        }
    }
}

void UPlayerAttributeSet::RecalculateTotalHP()
{
    float HPBonusfromPercent = (float)FMath::RoundToInt(GetHP() * GetHPBonusPercent());
    float HPBonusfromFlat = GetHPBonusFlat();
    float FinalHP = GetHP() + HPBonusfromPercent + HPBonusfromFlat;
    SetTotalHP(FinalHP);
    UE_LOG(LogTemp, Display, TEXT("Recalculated HP is %f using base HP of %f, HP Bonus %f, and HP Flat Bonus %f"),FinalHP,
    GetHP(),HPBonusfromPercent,HPBonusfromFlat);
}