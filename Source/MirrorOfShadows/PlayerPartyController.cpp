// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPartyController.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCharacters.h"
#include "Components/PrimitiveComponent.h"


APlayerPartyController::APlayerPartyController()
{
    
}

void APlayerPartyController::SetUpMembers(TArray<UPlayerData*> PartyList)
{
    PartyMembers = PartyList;
}

void APlayerPartyController::BeginPlay()
{
    // UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerCharacters::StaticClass(), PartyMembers);
    // AliveMembers = PartyMembers.Num();
    // for(int i = 1; i < AliveMembers;i++)
    // {
    //     Cast<APlayerCharacters>(PartyMembers[i])->SetPlayerActive(false);
    // }
    
}

void APlayerPartyController::SwapCharacterLeft()
{
    // Edit this accordingly once we deal with certain indices being unavailable
    int SwapToIndex = CurrentCharacter - 1;
    if (SwapToIndex < 0) SwapToIndex = AliveMembers - 1;

    // Possess(Cast<APawn>(PartyMembers[SwapToIndex]));
    
    // // Note camera rotation needs to be adjusted on the character swap
    // // Also create onswitch event to ensure normal attacks can still work.
    // FVector CurrentPos = PartyMembers[CurrentCharacter]->GetActorLocation();
    // FRotator CurrentRot = PartyMembers[CurrentCharacter]->GetActorRotation();

    // Cast<APlayerCharacters>(PartyMembers[SwapToIndex])->SetPlayerActive(true);
    // Cast<APlayerCharacters>(PartyMembers[CurrentCharacter])->SetPlayerActive(false);

    // PartyMembers[SwapToIndex]->SetActorLocation(CurrentPos);
    // PartyMembers[SwapToIndex]->SetActorRotation(CurrentRot);

    // CurrentCharacter = SwapToIndex;
}

void APlayerPartyController::SwapCharacterRight()
{
    // int SwapToIndex = (CurrentCharacter + 1) % AliveMembers;

    // Possess(Cast<APawn>(PartyMembers[SwapToIndex]));

    // CurrentCharacter = SwapToIndex;
}




