// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayModeBase.h"
#include "PlayerPartyController.h"
#include "PlayerData.h"
#include "PlayerCharacters.h"

#include "Kismet/GameplayStatics.h"


void AGameplayModeBase::BeginPlay()
{
    Super::BeginPlay();
    StartGame();
}

void AGameplayModeBase::StartGame()
{
    PlayerPartyController = Cast<APlayerPartyController>(UGameplayStatics::GetPlayerController(this,0));


    // Remove GetPawn and find another way to get current player in the world
    APawn* Pawn = UGameplayStatics::GetPlayerPawn(this,0);
    FVector CurrentPos = Pawn->GetActorLocation();
    FRotator CurrentRot = Pawn->GetActorRotation();
    if (PartyMembers[0] != nullptr && PlayerPartyController != nullptr)
    {
        APlayerCharacters* CurrentPlayer = GetWorld()->SpawnActor<APlayerCharacters>(PartyMembers[0]->GetCharacterClass(),CurrentPos,CurrentRot);
        PlayerPartyController->Possess(Cast<APawn>(CurrentPlayer));

        PlayerPartyController->SetUpMembers(PartyMembers);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Party Member not initialized or controller is null"));
    }

    
}
