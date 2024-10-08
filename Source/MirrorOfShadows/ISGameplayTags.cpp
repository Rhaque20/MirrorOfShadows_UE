#include "ISGameplayTags.h"
#include "GameplayTagsManager.h"

FISGameplayTags FISGameplayTags::GameplayTags;

void FISGameplayTags::InitializeNativeTags()
{
	UGameplayTagsManager& Manager = UGameplayTagsManager::Get();

	GameplayTags.AddAllTags(Manager);

	Manager.DoneAddingNativeTags();
}

void FISGameplayTags::AddAllTags(UGameplayTagsManager& Manager)
{
	AddTag(Input_Move, "Input.Move", "Move input.");
	AddTag(Input_Look, "Input.Look", "Look input.");
	AddTag(Input_Jump, "Input.Jump", "Jump input.");

	AddTag(Ability_Input_OnInputTriggered, "Ability.Input.OnInputTriggered", "Test ability input.");
	AddTag(Ability_Input_WhileInputActive, "Ability.Input.WhileInputActive", "Test ability input.");
	AddTag(Ability_Input_NormalAttack,"Ability.Input.NormalAttack","Normal Attack Action");
}

void FISGameplayTags::AddTag(FGameplayTag& OutTag, const ANSICHAR* TagName, const ANSICHAR* TagComment)
{
	OutTag = UGameplayTagsManager::Get().AddNativeGameplayTag(FName(TagName), FString(TEXT("(Native) ")) + FString(TagComment));
}