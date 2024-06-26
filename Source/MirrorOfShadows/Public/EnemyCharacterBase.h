// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"

#include "EnemyCharacterBase.generated.h"

UCLASS()
class MIRROROFSHADOWS_API AEnemyCharacterBase : public ACharacter,public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacterBase();
	int GetLevel() const;
	UFUNCTION(BlueprintCallable)
	void Recover();

	UFUNCTION(BlueprintCallable)
	float GetHealth() const;
	UFUNCTION(BlueprintCallable)
	float GetCurrentHealth() const;

	UFUNCTION(BlueprintCallable)
	void DetectionFill();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAbilitySystemComponent* AbilitySystem;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Abilities")
	TSubclassOf<class UGameplayEffect> DefaultAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Abilities")
	TArray<TSubclassOf<class UCharacterGameplayAbility>> EnemyAbilities;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	bool IsAttacking = false;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	bool CanMove = true;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	bool DetectedTarget = false;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	float DetectionPercent = 0.0f;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	float DetectionFillRate = 0.1f;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Normal Attack")
	TArray<class UEnemySkill*> Moveset;

public:
	UPROPERTY(VisibleAnywhere)
	class UEnemyAttributeSet* AttributeSet;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override
	{
		return AbilitySystem;
	}

	void InitializeAttributes();

	UFUNCTION(BlueprintCallable)
	void SetSkillModifier(float modifier);

};
