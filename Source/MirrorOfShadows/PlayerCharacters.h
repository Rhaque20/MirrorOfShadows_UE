// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"
#include "GameplayTagAssetInterface.h"
#include "AbilitySystemInterface.h"

#include "PlayerCharacters.generated.h"

UCLASS()
class MIRROROFSHADOWS_API APlayerCharacters : public ACharacter, public IAbilitySystemInterface,public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacters();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAbilitySystemComponent* AbilitySystem;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Move(const struct FInputActionValue& InputValue);
	void Look(const struct FInputActionValue& InputValue);
	void Jump();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetPlayerActive(bool IsActive);

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

	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)
	void NormalAttackAbility();

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
	class UInputAction* NormalAttackAction;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Combat Component")
	class UPlayerCore* CharacterCore;

	UPROPERTY(VisibleAnywhere)
	class UBaseAttributeSet* AttributeSet;

	UPROPERTY(BlueprintReadWrite, Category = "Gameplay Tag")
	FGameplayTagContainer GameplayTagContainer;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Stat Component")
	class UPlayerStatComponent* Stats;

private:
	UPROPERTY(BlueprintReadWrite, Category = "Ground Variables",meta = (AllowPrivateAccess = "true"))
	bool CanMove = true;
	UPROPERTY(BlueprintReadWrite, Category = "Aerial Variables",meta = (AllowPrivateAccess = "true"))
	bool OnGround = true;
	UPROPERTY(BlueprintReadWrite, Category = "Aerial Variables",meta = (AllowPrivateAccess = "true"))
	float AerialVelocity = 0.f;

};
