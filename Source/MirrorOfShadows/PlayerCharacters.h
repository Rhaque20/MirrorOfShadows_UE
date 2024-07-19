// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"
#include "GameplayTagAssetInterface.h"
#include "AbilitySystemInterface.h"

#include "PlayerCharacters.generated.h"

class UStaggerComponent;
UCLASS()
class MIRROROFSHADOWS_API APlayerCharacters : public ACharacter, public IAbilitySystemInterface,public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacters();

	UFUNCTION(BlueprintCallable)
	float GetHealth() const;
	UFUNCTION(BlueprintCallable)
	float GetCurrentHealth() const;
	int GetLevel() const;
	UFUNCTION(BlueprintCallable)
	float GetDamage() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Move(const struct FInputActionValue& InputValue);
	void Look(const struct FInputActionValue& InputValue);
	void LookUpRate(const struct FInputActionValue& InputValue);
	void Jump();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetPlayerActive(bool IsActive);
	void SwapIn();
	void SwapOut();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override
	{
		return AbilitySystem;
	}

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& OwnedTags) const override
	{
		OwnedTags = GameplayTagContainer; 
		return;
	}

	UStaggerComponent* ReturnStaggerComponent() const
	{
		return StaggerComponent;
	}

	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)
	void NormalAttackAbility();

	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)
	void CounterEdgeAbility();// To be used for when performing a switch counter edge

	UFUNCTION(BlueprintCallable)
	void InitializeAttributes();

	UFUNCTION(BlueprintCallable)
	void SetSkillModifier(float modifier);

	UFUNCTION(BlueprintCallable)
	void SetUpLockOn(bool LockOnToggle, AActor* Target);

	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)
	void PlayerRecover();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Camera Component")
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, Category = "Camera Component")
	class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	class UInputMappingContext* InputMapping;
	
	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	class UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	class UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	class UInputAction* LookUpRateAction;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	class UInputAction* NormalAttackAction;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Combat Component")
	class UPlayerCore* CharacterCore;

	UPROPERTY(EditAnywhere)
	class UPlayerAttributeSet* AttributeSet;

	UPROPERTY(BlueprintReadWrite, Category = "Gameplay Tag")
	FGameplayTagContainer GameplayTagContainer;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "StaggerComponent")
	UStaggerComponent* StaggerComponent;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Abilities")
	TSubclassOf<class UGameplayEffect> DefaultAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Abilities")
	TArray<TSubclassOf<class UCharacterGameplayAbility>> CharacterAbilities;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Equipment")
	class UEquipmentComponent* EquipmentComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAbilitySystemComponent* AbilitySystem;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Lock On System")
	bool HasLockOn = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Lock On System")
	AActor* LockOnTarget;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Defense Action")
	UAnimMontage* ForwardRollMontage;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Defense Action")
	UAnimMontage* BackRollMontage;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Defense Action")
	UAnimMontage* ParryAnimation;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Defense Action")
	bool CanBlock = false;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Defense Action")
	bool CanEvade = false;

	// Maybe add start up effect?
	UPROPERTY(BlueprintReadWrite, Category = "Ground Variables")
	bool CanMove = true;
	UPROPERTY(BlueprintReadWrite, Category = "Aerial Variables")
	bool OnGround = true;
	UPROPERTY(BlueprintReadWrite, Category = "Aerial Variables")
	float AerialVelocity = 0.f;
	UPROPERTY(EditAnywhere)
	float RotationRate = 10.f;

};