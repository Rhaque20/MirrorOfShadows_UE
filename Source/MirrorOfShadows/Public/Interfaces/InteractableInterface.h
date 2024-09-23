#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractableInterface.generated.h"

/*
This class does not need to be modified.
Empty class for reflection system visibility.
Uses the UINTERFACE macro.
Inherits from UInterface.
*/
UINTERFACE(MinimalAPI, Blueprintable)
class UInteractableInterface : public UInterface
{
	GENERATED_BODY()
};

/* Actual Interface declaration. */
class IInteractableInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:
		UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
		void OnView();
		UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
		void Interact();
	// Add interface function declarations here
};