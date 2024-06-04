#include "StatComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "../EnumLib.h"
#include "../Skill.h"

int UStatComponent::DamageCalculation(float Modifier, EStats ScaleStat, UStatComponent AttackerStat) 
{
    switch (ScaleStat)
    {
        case EStats::Health:
            UE_LOG(LogTemp, Display, TEXT("Scaling off of health"));
        break;
    }
    return 2;
}

float UStatComponent::FinalStat(EStats ScaleStat) 
{
    return 0.0f;
}

UStatComponent::UStatComponent() 
{
    
}
