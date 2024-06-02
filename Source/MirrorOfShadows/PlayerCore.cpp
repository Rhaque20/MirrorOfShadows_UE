// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCore.h"
#include "PlayerSkill.h"
#include "Containers/Array.h"
#include "AbilitySystemComponent.h"
#include "PlayerCharacters.h"

#include "Kismet/KismetSystemLibrary.h"

#define PlayerChannel ETraceTypeQuery::TraceTypeQuery13
#define EnemyChannel ETraceTypeQuery::TraceTypeQuery14


void UPlayerCore::NormalAttack()
{
    if (!bIsAttacking)
    {
        SetUpAttackAnim();
    }
    else if (CanBuffer)
    {
        HasBuffer = true;
    }
    
}

void UPlayerCore::Recover()
{
    CurrentChain++;

    EndOfChain = (CurrentChain >= NormalAttacks.Num());

    if (HasBuffer && !EndOfChain)
    {
        HasBuffer = false;
        SetUpAttackAnim();
    }
    else if (!EndOfChain)
    {
        bIsAttacking = false;
    }

    if(EndOfChain)
    {
        CurrentChain = 0;
    }
    
}

void UPlayerCore::Hit()
{
    FVector Location = GetOwner()->GetActorLocation();
    FVector ForwardVector = GetOwner()->GetActorForwardVector() * 50.f;
    FRotator Rotation = GetOwner()->GetActorRotation();

    const FVector BoxExtents = FVector(32,32,32) * NormalAttacks[CurrentChain]->GetHitBoxScale();
    TArray<AActor*> IgnoreActor;
    IgnoreActor.Init(GetOwner(),1);
    TArray<FHitResult> Results;



    UKismetSystemLibrary::BoxTraceMulti(this,Location + ForwardVector, Location + ForwardVector + FVector(0.1f,0.1f,0.1f)
    ,BoxExtents,Rotation,EnemyChannel,false,IgnoreActor ,EDrawDebugTrace::Type::ForDuration,Results,true);

    InflictDamage(Results);
}

void UPlayerCore::SetUpAttackAnim()
{
    bIsAttacking = true;

    UAnimMontage* AttackAnim = NormalAttacks[CurrentChain]->GetAnimation(0);
    if (AttackAnim != nullptr)
    {
        SkeletalMesh->GetAnimInstance()->Montage_Play(AttackAnim,1.f,EMontagePlayReturnType::Duration,0.f,true);
        // Deal with fact of chain going beyond the array
    }
}

