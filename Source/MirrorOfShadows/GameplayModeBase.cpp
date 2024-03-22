// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayModeBase.h"
#include "PlayerPartyController.h"
#include "PlayerData.h"

#include "Kismet/GameplayStatics.h"


void AGameplayModeBase::BeginPlay()
{
    Super::BeginPlay();
    StartGame();
}

void AGameplayModeBase::StartGame()
{
    
    
}
