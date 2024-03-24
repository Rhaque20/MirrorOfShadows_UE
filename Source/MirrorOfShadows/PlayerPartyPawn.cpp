// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPartyPawn.h"

// Sets default values
APlayerPartyPawn::APlayerPartyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void APlayerPartyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPartyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPartyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

