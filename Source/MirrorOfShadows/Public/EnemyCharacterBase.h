// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RPGCharacterBase.h"
#include "AbilitySystemInterface.h"

#include "EnemyCharacterBase.generated.h"


class UStaggerComponent;
UCLASS()
class MIRROROFSHADOWS_API AEnemyCharacterBase : public ARPGCharacterBase
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

	UFUNCTION(BlueprintCallable)
	void GetConditionParameters(APawn *TargetPawn, float& Distance, float& Angle, float& Height) const;

	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)
	void SelectAttack(float Distance, float Angle, float Height, bool& Selected);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Abilities")
	TSubclassOf<class UGameplayEffect> DefaultAttributes;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	bool IsAttacking = false;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	bool DetectedTarget = false;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	float DetectionPercent = 0.0f;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	float DetectionFillRate = 0.1f;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Normal Attack")
	TArray<class UEnemySkill*> Moveset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MaxStatusDisplayDistance = 1200;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	AActor* AttackTarget;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void InitializeAttributes();

};

