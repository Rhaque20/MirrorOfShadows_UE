#include "StatComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "EnumLib.h"

UStatComponent::UStatComponent() 
{
    
}

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
