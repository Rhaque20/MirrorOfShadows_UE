// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPartyController.h"
#include "PlayerData.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCharacters.h"
#include "Components/PrimitiveComponent.h"


APlayerPartyController::APlayerPartyController()
{
    
}

void APlayerPartyController::SetUpMembers(TArray<APlayerCharacters*> PartyList)
{
    SummonedActorReferences = PartyList;
    AliveMembers = SummonedActorReferences.Num();
}

void APlayerPartyController::BeginPlay()
{
    // UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerCharacters::StaticClass(), PartyMembers);
    // APlayerCharacters *Temp;

    // AGameModeBase *ActiveGameMode = UGameplayStatics::GetGameMode(this);
    // ActiveGameMode->DefaultPawnClass = PartyMembers[0]->GetCharacterClass();

    // for(int i = 1; i < AliveMembers;i++)
    // {
    //     Temp = GetWorld()->SpawnActor<APlayerCharacters>(PartyMembers[i]->GetCharacterClass(),FVector(0,0,0),FRotator(0,0,0));
    //     Temp->SetPlayerActive(false);
    //     SummonedActors->Add(Temp);
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

    SwapCharacter(SwapToIndex);
}

void APlayerPartyController::SwapCharacterRight()
{
    // int SwapToIndex = (CurrentCharacter + 1) % AliveMembers;

    // Possess(Cast<APawn>(PartyMembers[SwapToIndex]));

    // CurrentCharacter = SwapToIndex;
}

void APlayerPartyController::SwapCharacter(int SwapToIndex) 
{
    APawn* ActivePawn = GetPawn();

    FVector CurrentPos = ActivePawn->GetActorLocation();
    FRotator CurrentRot = ActivePawn->GetActorRotation();

    // APlayerCharacters* SwapToPlayer = GetWorld()->SpawnActor<APlayerCharacters>(PartyMembers[SwapToIndex]->GetCharacterClass(),CurrentPos,CurrentRot);

    APlayerCharacters* SwapToPlayer = SummonedActorReferences[SwapToIndex];

    FRotator CameraRot = ActivePawn->GetController()->GetControlRotation();

    Possess(Cast<APawn>(SwapToPlayer));

    SwapToPlayer->SetActorLocation(CurrentPos);
    SwapToPlayer->SetActorRotation(CurrentRot);

    // ActivePawn->Destroy();

    SwapToPlayer->GetController()->SetControlRotation(CameraRot);
    
     UE_LOG(LogTemp, Display, TEXT("Swapped party members and relocated camera"));

    
    
    // // Note camera rotation needs to be adjusted on the character swap
    // // Also create onswitch event to ensure normal attacks can still work.

    SummonedActorReferences[SwapToIndex]->SetPlayerActive(true);
    SummonedActorReferences[CurrentCharacter]->SetPlayerActive(false);

    SummonedActorReferences[SwapToIndex]->SwapIn();
    // PartyMembers[SwapToIndex]->SetActorLocation(CurrentPos);
    // PartyMembers[SwapToIndex]->SetActorRotation(CurrentRot);

    CurrentCharacter = SwapToIndex;
}




