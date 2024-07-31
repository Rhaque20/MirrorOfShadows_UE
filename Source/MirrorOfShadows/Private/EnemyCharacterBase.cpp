// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacterBase.h"
#include "AbilitySystemComponent.h"
#include "../EnemyAttributeSet.h"
#include "Components/StaggerComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AEnemyCharacterBase::AEnemyCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystem");
	AttributeSet = CreateDefaultSubobject<UEnemyAttributeSet>("AttributeSet");
	// StaggerComponent = CreateDefaultSubobject<UStaggerComponent>(TEXT("Stagger Component"));

}

// Called when the game starts or when spawned
void AEnemyCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	InitializeAttributes();
}

// Called every frame
void AEnemyCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int AEnemyCharacterBase::GetLevel() const
{
	if (AttributeSet)
		{
			return AttributeSet->GetLevel();
		}

	return 1;
}

// Called to bind functionality to input
void AEnemyCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AEnemyCharacterBase::GetHealth() const
{
	if (AttributeSet)
	{
		return AttributeSet->GetHP();
	}

	return 0.0f;
}

float AEnemyCharacterBase::GetCurrentHealth() const
{
	if (AttributeSet)
	{
		return AttributeSet->GetCurrentHP();
	}
	return 0.0f;
}

void AEnemyCharacterBase::InitializeAttributes() 
{
	if (!IsValid(AbilitySystem))
	{
		return;
	}
	if(!DefaultAttributes)
	{
		UE_LOG(LogTemp, Error, TEXT("%s is missing an attribute ability! Set it in the blueprint!"),*GetName());
	}

	FGameplayEffectContextHandle EffectContext = AbilitySystem->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	FGameplayEffectSpecHandle NewHandle = AbilitySystem->MakeOutgoingSpec(DefaultAttributes,GetLevel(),EffectContext);

	if (NewHandle.IsValid())
	{
		FActiveGameplayEffectHandle ActiveGEHandle = AbilitySystem->ApplyGameplayEffectSpecToTarget(*NewHandle.Data.Get(),AbilitySystem);
		AttributeSet->SetCurrentHP(AttributeSet->GetHP());
		UE_LOG(LogTemp, Error, TEXT("Base stats have been applied"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Gameplay Effect handle is invalid"));
	}
}

void AEnemyCharacterBase::Recover() 
{
	IsAttacking = false;
	CanMove = true;
}

void AEnemyCharacterBase::DetectionFill() 
{
	
}

void AEnemyCharacterBase::SetSkillModifier(float modifier) 
{
	if(AttributeSet)
	{
		AttributeSet->SetSkillModifier(modifier);
	}
}

void AEnemyCharacterBase::GetConditionParameters(APawn *TargetPawn, float& Distance, float& Angle, float& Height) const
{
	FVector TargetLocation = TargetPawn->GetActorLocation();
	// Distance between attacker (this) and the target (not necessarily the player)
	Distance = FVector::Dist(this->GetActorLocation(),TargetLocation);
	// Height difference between the attacker (this) and the target
	// Maybe should replace location with eye height location in the future.
	Height = TargetLocation.Z - this->GetActorLocation().Z;

	FVector AttackerVector = this->GetActorForwardVector();

	double DotProduct = UKismetMathLibrary::Dot_VectorVector(AttackerVector,TargetLocation);

	// Calculate the angle in radians
	float AngleInRadians = FMath::Acos(DotProduct);

	// Convert the angle to degrees between the actor
	Angle = FMath::RadiansToDegrees(AngleInRadians);
}

