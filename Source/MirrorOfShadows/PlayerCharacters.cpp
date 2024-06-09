// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PlayerCharacters.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "AbilitySystemComponent.h"
#include "BaseAttributeSet.h"
#include "Components/PlayerStatComponent.h"
#include "PlayerCore.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/NavMovementComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/CapsuleComponent.h"

// Sets default values
APlayerCharacters::APlayerCharacters()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);

	AbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystem");
	AttributeSet = CreateDefaultSubobject<UBaseAttributeSet>("AttributeSet");

	Stats = CreateDefaultSubobject<UPlayerStatComponent>("Stats");
	
	CharacterCore = CreateDefaultSubobject<UPlayerCore>(TEXT("PlayerCore"));

	// bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;

}

float APlayerCharacters::GetHealth() const
{
	if (AttributeSet)
	{
		return AttributeSet->GetHP();
	}

	return 0.0f;
}

float APlayerCharacters::GetCurrentHealth() const
{
	if (AttributeSet)
	{
		return AttributeSet->GetCurrentHP();
	}

	return 0.0f;
}

int APlayerCharacters::GetLevel() const
{
	if (AttributeSet)
	{
		return AttributeSet->GetLevel();
	}

	return 1;
}

void APlayerCharacters::SetSkillModifier(float modifier) 
{
	if(AttributeSet)
	{
		AttributeSet->SetSkillModifier(modifier);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Attribute set is null"));
	}
}

float APlayerCharacters::GetDamage() const
{
	if (AttributeSet)
	{
		return AttributeSet->GetDamage();
	}

	return 0.0f;
}

// Called when the game starts or when spawned
void APlayerCharacters::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystem->InitAbilityActorInfo(this, this);
	InitializeAttributes();	
}

// Called every frame
void APlayerCharacters::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerCharacters::SetPlayerActive(bool IsActive)
{
	SetActorHiddenInGame(!IsActive);
	SetActorEnableCollision(IsActive);
}

// Called to bind functionality to input
void APlayerCharacters::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if(APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if(UEnhancedInputLocalPlayerSubsystem* Subsystem 
		= ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMapping,0);
		}
	}

	if(UEnhancedInputComponent* Input = 
	CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		Input->BindAction(MoveAction,ETriggerEvent::Triggered,this,&APlayerCharacters::Move);
		Input->BindAction(LookAction,ETriggerEvent::Triggered,this,&APlayerCharacters::Look);
		Input->BindAction(JumpAction,ETriggerEvent::Triggered,this,&APlayerCharacters::Jump);
	}
}

void APlayerCharacters::InitializeAttributes() 
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

void APlayerCharacters::Move(const FInputActionValue& InputValue)
{
	FVector2D InputVector = InputValue.Get<FVector2D>();

	if (IsValid(Controller) && CanMove)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation = FRotator(0.f,Rotation.Yaw,0.f);
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(ForwardDirection, InputVector.Y);
		AddMovementInput(RightDirection, InputVector.X);
	}
}

void APlayerCharacters::Look(const FInputActionValue& InputValue)
{
	FVector2D InputVector = InputValue.Get<FVector2D>();
	if (IsValid(Controller))
	{
		AddControllerYawInput(InputVector.X);
		AddControllerPitchInput(InputVector.Y);
	}
}

void APlayerCharacters::Jump()
{
	ACharacter::Jump();
}

