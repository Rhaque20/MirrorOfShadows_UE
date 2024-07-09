// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPartyController.h"
#include "PlayerData.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCharacters.h"
#include "Components/PrimitiveComponent.h"


APlayerPartyController::APlayerPartyController()
{
    
}

void APlayerPartyController::SetUpMembers(TArray<UPlayerData*> PartyList)
{
    PartyMembers = PartyList;
    AliveMembers = PartyMembers.Num();
}

void APlayerPartyController::BeginPlay()
{
    // UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerCharacters::StaticClass(), PartyMembers);
    AliveMembers = PartyMembers.Num();
    // for(int i = 1; i < AliveMembers;i++)
    // {
    //     Cast<APlayerCharacters>(PartyMembers[i])->SetPlayerActive(false);
    // }
    
}

void APlayerPartyController::SwapCharacterLeft()
{
    // Edit this accordingly once we deal with certain indices being unavailable
    if (AliveMembers == 0)
    {
         UE_LOG(LogTemp, Error, TEXT("Party Member TArray is empty"));
         return;
    }
    else
    {
         UE_LOG(LogTemp, Display, TEXT("Party Member Array count is %d"),AliveMembers);
    }
    int SwapToIndex = CurrentCharacter - 1;
    if (SwapToIndex < 0) SwapToIndex = AliveMembers - 1;

    APawn* ActivePawn = GetPawn();

    FVector CurrentPos = ActivePawn->GetActorLocation();
    FRotator CurrentRot = ActivePawn->GetActorRotation();

    APlayerCharacters* SwapToPlayer = GetWorld()->SpawnActor<APlayerCharacters>(PartyMembers[SwapToIndex]->GetCharacterClass(),CurrentPos,CurrentRot);

    FRotator CameraRot = ActivePawn->GetController()->GetControlRotation();

    Possess(Cast<APawn>(SwapToPlayer));

    SwapToPlayer->SetActorLocation(CurrentPos);
    SwapToPlayer->SetActorRotation(CurrentRot);

    ActivePawn->Destroy();

    SwapToPlayer->GetController()->SetControlRotation(CameraRot);
    
     UE_LOG(LogTemp, Display, TEXT("Swapped party members and relocated camera"));

    
    
    // // Note camera rotation needs to be adjusted on the character swap
    // // Also create onswitch event to ensure normal attacks can still work.

    // Cast<APlayerCharacters>(PartyMembers[SwapToIndex])->SetPlayerActive(true);
    // Cast<APlayerCharacters>(PartyMembers[CurrentCharacter])->SetPlayerActive(false);

    // PartyMembers[SwapToIndex]->SetActorLocation(CurrentPos);
    // PartyMembers[SwapToIndex]->SetActorRotation(CurrentRot);

    CurrentCharacter = SwapToIndex;
}

void APlayerPartyController::SwapCharacterRight()
{
    // int SwapToIndex = (CurrentCharacter + 1) % AliveMembers;

    // Possess(Cast<APawn>(PartyMembers[SwapToIndex]));

    // CurrentCharacter = SwapToIndex;
}




