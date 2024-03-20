// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCore.h"
#include "PlayerSkill.h"
#include "Containers/Array.h"


void UPlayerCore::NormalAttack()
{
    bIsAttacking = true;
    // SkeletalMesh->PlayAnimation(NormalAttacks[CurrentChain]->GetSkillAnimation(0),false);
    // CurrentChain = (CurrentChain + 1) % NormalAttacks.Num();
}

void UPlayerCore::Recover()
{
    bIsAttacking = false;
}