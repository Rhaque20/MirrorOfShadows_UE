// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacters.h"
#include "CecilePlayable.generated.h"

/**
 * 
 */
UCLASS()
class MIRROROFSHADOWS_API ACecilePlayable : public APlayerCharacters
{
	GENERATED_BODY()
	public:
		ACecilePlayable();

	private:
		UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Combat Component", meta = (AllowPrivateAccess = "true"))
		class UCecileCore* CecilePassive;
	
	public:
		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
