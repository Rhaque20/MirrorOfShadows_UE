#pragma once

#include "CoreMinimal.h"
#include "ItemCategoryEnum.generated.h"

UENUM(BlueprintType)
enum class EItemCategory
{
    CraftingMaterial UMETA(DisplayName = "Crafting Material"),
    Armor UMETA(DisplayName = "Armor"),
    Weapon UMETA(DisplayName ="Weapon")
};