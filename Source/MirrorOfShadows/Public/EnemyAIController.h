// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class MIRROROFSHADOWS_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

	public:
		// virtual void Tick(float DeltaSeconds) override;
		UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
		bool IsDead() const;

		AEnemyAIController(const FObjectInitializer& ObjectInitializer = FObjectInitializer :: Get());

	protected:
		UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
		APawn* PlayerPawn;
		UPROPERTY(EditAnywhere)
		float AcceptanceRadius = 200.f;
		UPROPERTY(EditAnywhere,BlueprintReadOnly)
		class UBehaviorTree* AIBehavior;
	
};
