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
    }
    
}

void UPlayerCore::SetUpAttackAnim()
{
    bIsAttacking = true;
    //SkeletalMesh->PlayAnimation(NormalAttacks[CurrentChain]->GetSkillAnimation(0),false);
    UAnimMontage* AttackAnim = Cast<UAnimMontage>(NormalAttacks[CurrentChain]->GetSkillAnimation(0));
    SkeletalMesh->GetAnimInstance()->Montage_Play(AttackAnim,1.f,EMontagePlayReturnType::Duration,0.f,true);
    CurrentChain = (CurrentChain + 1) % NormalAttacks.Num();
    EndOfChain = (CurrentChain == 0);
    if (EndOfChain)
    {
        UE_LOG(LogTemp, Warning, TEXT("Hit End of Chain!"));
    }
}
