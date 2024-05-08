// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"

class USkeletalMeshComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MIRROROFSHADOWS_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void SetUpAttackAnim();

protected:
	UPROPERTY(VisibleAnywhere,Category ="SkeletalMeshRef")
	USkeletalMeshComponent* SkeletalMesh;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	bool bIsAttacking = false;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void Hit();
	virtual void InflictDamage(TArray<FHitResult> Results);
	virtual void SkillSelect();
	void SetSkeletalMeshVar(USkeletalMeshComponent* SkeletalMeshAddress);
	virtual void Recover();
	virtual bool IsBehindTarget(AActor* Target);

		
};
