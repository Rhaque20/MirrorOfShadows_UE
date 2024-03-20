// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill.h"

UAnimationAsset *USkill::GetSkillAnimation(int index)
{
    if (index >= AttackAnimations.Num())
        return nullptr;
    
    return AttackAnimations[index];
}
