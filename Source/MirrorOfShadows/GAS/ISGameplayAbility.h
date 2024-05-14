// Copyright 2023 Michał Ogiński.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "ISGameplayAbility.generated.h"

/**
 * Defines how ability is meant to activate
 */
UENUM(BlueprintType)
enum class EISAbilityActivationPolicy : uint8
{
	// Try to activate the ability when the input is triggered.
	OnInputTriggered,
	
	// Continually try to activate the ability while the input is active.
	WhileInputActive
};

UENUM(BlueprintType)
enum class AbilityInputType : uint8
{
	OnePress,
	RepeatPress
};
/**
 * 
 */
UCLASS()
class MIRROROFSHADOWS_API UISGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	EISAbilityActivationPolicy GetActivationPolicy() const {return ActivationPolicy;}
	AbilityInputType GetInputCategory() const {return InputCategory;}
	void EndAbilityModified();
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "InputSystem|Ability Activation")
	EISAbilityActivationPolicy ActivationPolicy;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "InputSystem|Ability Activation")
	AbilityInputType InputCategory;
	UPROPERTY()
	FTimerHandle DelayTimerHandle;

protected:
	virtual void InputPressed
(
    const FGameplayAbilitySpecHandle Handle,
    const FGameplayAbilityActorInfo * ActorInfo,
    const FGameplayAbilityActivationInfo ActivationInfo
) override;

virtual void InputReleased
(
    const FGameplayAbilitySpecHandle Handle,
    const FGameplayAbilityActorInfo * ActorInfo,
    const FGameplayAbilityActivationInfo ActivationInfo
) override;
	
};
