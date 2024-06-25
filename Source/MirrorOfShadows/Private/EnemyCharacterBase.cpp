// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacterBase.h"
#include "AbilitySystemComponent.h"
#include "../EnemyAttributeSet.h"

// Sets default values
AEnemyCharacterBase::AEnemyCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystem");
	AttributeSet = CreateDefaultSubobject<UEnemyAttributeSet>("AttributeSet");

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

