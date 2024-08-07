// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StaggerComponent.generated.h"

class USkill;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),Blueprintable)
class MIRROROFSHADOWS_API UStaggerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStaggerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

protected:
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere)
	USkill* SkillData;
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere)
	AActor* AttackingActor;
	
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly, Category="Hit Reaction")
	UAnimMontage* LightStaggerAnim;

	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly, Category="Hit Reaction")
	UAnimMontage* BlockingAnim;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)
	void OnPoiseBreak();

	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)
	void OnStanceBreak();

	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)
	void OnInterrupt();

	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)
	void OnHit(bool& HitResult);

	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)
	void OnParry(bool& ParryResult);

	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)
	void OnGetParried();

	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)
	void OnBlocking(bool DidBlock);

	UFUNCTION(BlueprintCallable)
	void SetUpAttackedData(USkill* ReceivingSkill, AActor* Attacker)
	{
		SkillData = ReceivingSkill;
		AttackingActor = Attacker;
	};

		
};
