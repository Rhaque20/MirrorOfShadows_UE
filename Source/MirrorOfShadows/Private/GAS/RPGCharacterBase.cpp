#include "RPGCharacterBase.h"
#include "GAS/CustomAbilitySystemComponent.h"
#include "../BaseAttributeSet.h"
#include "../Skill.h"
#include "GameFramework/CharacterMovementComponent.h"


UAbilitySystemComponent* ARPGCharacterBase::GetAbilitySystemComponent() const 
{
    return AbilitySystem;
}

void ARPGCharacterBase::StartDodge()
{
	StopDodgeTimeLine();
}

void ARPGCharacterBase::ActivateSkill()
{

}

void ARPGCharacterBase::AutoTarget()
{
}

void ARPGCharacterBase::AttackForceUpdate(float val)
{
	float HorizontalCurveVal = 0.0f, VerticalForce = GetCharacterMovement()->Velocity.Z;
	FVector AttackDirection;
	if (ActiveSkill)
	{
		HorizontalCurveVal = ActiveSkill->GetLaunchCurve()->GetFloatValue(val);
		/*if (ActiveSkill->ReturnHasVerticalForce())
		{
			VerticalForce = ActiveSkill->GetVerticalLaunchCurve()->GetFloatValue(val) * ActiveSkill->GetVerticalLaunchForce();
			UE_LOG(LogTemp, Display, TEXT("Use Vertical force of %f "), VerticalForce);
		}*/
		AttackDirection = FVector(ActiveSkill->GetLaunchForce() * GetActorForwardVector() * HorizontalCurveVal);
		GetCharacterMovement()->Velocity = FVector(AttackDirection.X,AttackDirection.Y,VerticalForce);

	}
}

void ARPGCharacterBase::TriggerAirTime()
{
	if (GetWorld()->GetTimerManager().IsTimerActive(AirTimerHandle))
	{
		GetWorld()->GetTimerManager().ClearTimer(AirTimerHandle);
		UE_LOG(LogTemp, Display, TEXT("Cleared air timer"));
	}

	GetWorld()->GetTimerManager().SetTimer(
		AirTimerHandle, // handle to cancel timer at a later time
		this, // the owning object
		&ARPGCharacterBase::EndAirTime, // function to call on elapsed
		2.0f, // float delay until elapsed
		false); // looping?
}

void ARPGCharacterBase::EndAirTime()
{
	if (GetWorld()->GetTimerManager().IsTimerActive(AirTimerHandle))
	{
		GetWorld()->GetTimerManager().ClearTimer(AirTimerHandle);
	}
}

void ARPGCharacterBase::SetSkillModifier(float modifier)
{
	if (AttributeSet)
	{
		AttributeSet->SetSkillModifier(modifier);
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("%s attribute set is null"), *GetName());
	}
}

void ARPGCharacterBase::SetActiveSkill(USkill* SkillRef)
{
	ActiveSkill = SkillRef;
}

void ARPGCharacterBase::StopLaunchTimeLine()
{
	if (AttackForceTimeline.IsPlaying())
		AttackForceTimeline.Stop();
}

void ARPGCharacterBase::StopDodgeTimeLine()
{
	if (DodgeTimeline.IsPlaying())
		DodgeTimeline.Stop();
}

void ARPGCharacterBase::DodgeFunction(float val)
{
	FVector FacingDir = GetActorForwardVector() * 1500.f * val;
	float ZVelocity = GetCharacterMovement()->Velocity.Z;

	GetCharacterMovement()->Velocity = FVector(FacingDir.X, FacingDir.Y, ZVelocity);

}

void ARPGCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Display, TEXT("Calling RPGCharacterBase BeginPlay"));

	InterpFunction.BindUFunction(this, "AttackForceUpdate");

	DodgeInterpFunction.BindUFunction(this, "DodgeFunction");

	DodgeTimeline.AddInterpFloat(DodgeCurve, DodgeInterpFunction);
	
	AttackForceTimeline.AddInterpFloat(DefaultTimeCurve, InterpFunction);
	DodgeTimeline.SetTimelineLength(0.6f);
}

void ARPGCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AttackForceTimeline.TickTimeline(DeltaTime);
	DodgeTimeline.TickTimeline(DeltaTime);
}

ARPGCharacterBase::ARPGCharacterBase() 
{
    HitBoxLocation = CreateDefaultSubobject<USceneComponent>("Hitbox Spot Visual");
    HitBoxLocation->SetupAttachment(RootComponent);
	AttributeSet = CreateDefaultSubobject<UBaseAttributeSet>("BaseAttributeComponent");
}