// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCore.h"
#include "PlayerSkill.h"
#include "Containers/Array.h"


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
    if (HasBuffer && !EndOfChain)
    {
        HasBuffer = false;
        SetUpAttackAnim();
    }
    else
    {
        bIsAttacking = false;  
    }

    if(EndOfChain)
    {
        EndOfChain = false;
        CurrentChain = 0;
    }
    
}

void UPlayerCore::SetUpAttackAnim()
{
    bIsAttacking = true;
    UAnimMontage* AttackAnim = Cast<UAnimMontage>(NormalAttacks[CurrentChain]->GetSkillAnimation(0));
    SkeletalMesh->GetAnimInstance()->Montage_Play(AttackAnim,1.f,EMontagePlayReturnType::Duration,0.f,true);
    CurrentChain++;
    EndOfChain = (CurrentChain == NormalAttacks.Num());
}
