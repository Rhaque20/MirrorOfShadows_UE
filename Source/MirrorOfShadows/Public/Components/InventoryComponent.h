// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class URPGItem;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class MIRROROFSHADOWS_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
protected:
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly)
	TArray<URPGItem*> Inventory;
	// Used to index items and keep dupes in same spot
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly)
	TMap<URPGItem*, int> IndexedItemStorage;

	// Used to index gear, namely armor and weapons since easy differing factor will be GUID
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly)
	TMap<FGuid,class UEquipment*> IndexedEquipmentStorage;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
