// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatComponent.h"

#include "Components/SkeletalMeshComponent.h"
#include "Engine/EngineTypes.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/StatComponent.h"

// Sets default values for this component's properties
UCombatComponent::UCombatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	// SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));

	// ...
}

void UCombatComponent::Hit()
{

}

// void UCombatComponent::HitScan() 
// {
	
// }

// void UCombatComponent::ActiveHitScan() 
// {
	
// }

void UCombatComponent::InflictDamage(TArray<FHitResult> Results) 
{
	
}

void UCombatComponent::InflictDamageToSingle(FHitResult Result) 
{
	
}

void UCombatComponent::SkillSelect()
{
	
}

void UCombatComponent::SetSkeletalMeshVar(USkeletalMeshComponent* SkeletalMeshAddress)
{
	SkeletalMesh = SkeletalMeshAddress;
}

void UCombatComponent::SetStatComponent(UStatComponent* Stats) 
{
	StatComponent = Stats;
}

void UCombatComponent::Recover()
{
	
}

bool UCombatComponent::IsBehindTarget(AActor* Target) 
{
	FVector AttackerVector = GetOwner()->GetActorForwardVector();
	FVector TargetLocation = Target->GetActorForwardVector();

	double dotProduct = UKismetMathLibrary::Dot_VectorVector(AttackerVector,TargetLocation);
	UE_LOG(LogTemp, Display, TEXT("Dot product is %f"),dotProduct);

	return dotProduct > 0.7;
}

// Called when the game starts
void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UCombatComponent::SetUpAttackAnim()
{
	
}


// Called every frame
void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

