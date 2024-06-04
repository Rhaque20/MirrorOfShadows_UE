// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PlayerCharacters.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "AbilitySystemComponent.h"
#include "BaseAttributeSet.h"

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

	// bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;

}

// Called when the game starts or when spawned
void APlayerCharacters::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystem->InitAbilityActorInfo(this, this);

	// AttributeSet->SetCurrentHP(12);

	// 	auto Attribute = AttributeSet->GetCurrentHPAttribute();
	// 	auto& Delegate = AbilitySystem->GetGameplayAttributeValueChangeDelegate(Attribute);
		
	// 	Delegate.AddWeakLambda(this, [this](auto)
	// 	{
	// 		if (AttributeSet->GetCurrentHP() == 0)
	// 		{
	// 			UE_LOG(LogTemp, Display, TEXT("%s is dead."),*GetName());
	// 			Destroy();
	// 		}
	// 		else
	// 		{
	// 			UE_LOG(LogTemp, Display, TEXT("%s received damage!"),*GetName());
	// 		}
				

	// 	});

	

	
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

