#pragma once

#include "CoreMinimal.h"
#include "ItemEnum.generated.h"

UENUM(BlueprintType)
enum class EGrade
{
    Common UMETA(DisplayName = "Common"),
    Uncommon UMETA(DisplayName = "Uncommon"),
    Rare UMETA(DisplayName ="Rare"),
    Elite UMETA(DisplayName="Elite"),
    Epic UMETA(DisplayName = "Epic"),
    Mythical UMETA(DisplayName = "Mythical")
};