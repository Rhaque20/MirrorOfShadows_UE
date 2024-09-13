// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/StaggerComponent.h"
#include "RPGCharacterBase.h"
#include "AbilitySystemComponent.h"

// Sets default values for this component's properties
UStaggerComponent::UStaggerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStaggerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UStaggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UStaggerComponent::ApplyKnockback(FVector AttackerLocation, FVector2D KnockbackPower)
{
	ARPGCharacterBase* Character = Cast<ARPGCharacterBase>(GetOwner());

	UAbilitySystemComponent* ASC = Character->GetAbilitySystemComponent();

	if (!IsValid(ASC))
		return;

	if (ASC->HasMatchingGameplayTag(FGameplayTag::RequestGameplayTag("Effect.State.PoiseBroken")) ||
		ASC->HasMatchingGameplayTag(FGameplayTag::RequestGameplayTag("Effect.State.StanceBroken")))
	{
		FVector KnockbackDirection = (Character->GetActorLocation() - AttackerLocation);

		KnockbackDirection.Normalize();

		KnockbackDirection = FVector(KnockbackDirection.X * KnockbackPower.X, KnockbackDirection.Y * KnockbackPower.X, KnockbackPower.Y);

		Character->LaunchCharacter(KnockbackDirection, false,false);

		UE_LOG(LogTemp, Display, TEXT("StaggerComponentCPP: causing knockback on enemy with knockback direction %s"),*KnockbackDirection.ToString());
	}
}

