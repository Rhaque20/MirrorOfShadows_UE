#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

class UGameplayTagsManager;
/**
 * 
 */
struct MIRROROFSHADOWS_API FISGameplayTags
{
public:
	static const FISGameplayTags& Get() {return GameplayTags;}
	static void InitializeNativeTags();

public:
	FGameplayTag Input_Move;
	FGameplayTag Input_Look;

	FGameplayTag Ability_Input_WhileInputActive;
	FGameplayTag Ability_Input_OnInputTriggered;

	
protected:
	void AddAllTags(UGameplayTagsManager& Manager);
	void AddTag(FGameplayTag& OutTag, const ANSICHAR* TagName, const ANSICHAR* TagComment);
 
private:
	static FISGameplayTags GameplayTags;
};