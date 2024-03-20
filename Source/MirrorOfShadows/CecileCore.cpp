// Fill out your copyright notice in the Description page of Project Settings.


#include "CecileCore.h"

UCecileCore::UCecileCore()
{
    
}

void UCecileCore::NormalAttack()
{
	Super::NormalAttack();
	UE_LOG(LogTemp, Display, TEXT("Attack event triggered"));
}