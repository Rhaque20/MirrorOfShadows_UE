#pragma once

#include "UObject/Interface.h"

#include "AttackableInterface.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UAttackableInterface : public UInterface
{
    GENERATED_BODY()
};

class MIRROROFSHADOWS_API IAttackableInterface
{    
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "AttackableInterface")
    int GetCurrentHealth();
    UFUNCTION(BlueprintCallable,BlueprintImplementableEvent, Category = "AttackableInterface")
    int GetMaxHealth();
    UFUNCTION(BlueprintCallable,BlueprintImplementableEvent, Category = "AttackableInterface")
    bool Heal();
    UFUNCTION(BlueprintCallable,BlueprintImplementableEvent, Category = "AttackableInterface")
    bool TakeDamage(int damage);
    /** Add interface function declarations here */
};

/**
UCLASS(Blueprintable, BlueprintType)
class UBPI_TestInterface : public UInterface
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable)
	void GetMaxHealth(int32& MaxHealth);

	UFUNCTION(BlueprintCallable, Category="Default")
	void GetCurrentHealth(int32& CurrentHealth);

	UFUNCTION(BlueprintCallable)
	void Heal(bool& IsHealed);

	UFUNCTION(BlueprintCallable)
	void TakeDamage(int32 DamageReceived, bool& IsDamaged);
};

*/