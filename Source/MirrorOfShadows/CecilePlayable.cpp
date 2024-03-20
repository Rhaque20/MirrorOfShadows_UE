// Fill out your copyright notice in the Description page of Project Settings.


#include "CecilePlayable.h"
#include "CecileCore.h"

#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"

ACecilePlayable::ACecilePlayable()
{
    CecilePassive = CreateDefaultSubobject<UCecileCore>(TEXT("Cecile Core Mechanics"));
	CecilePassive->SetSkeletalMeshVar(GetMesh());
	CharacterCore = CecilePassive;
}

void ACecilePlayable::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if(UEnhancedInputComponent* Input = 
	CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		Input->BindAction(NormalAttackAction,ETriggerEvent::Started,CecilePassive,&UCecileCore::NormalAttack);
	}
}