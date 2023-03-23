// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MainCharacter.h"
#include "Switcher.generated.h"

UCLASS()
class DUO_SPAWNER_API ASwitcher : public AActor
{
	GENERATED_BODY()
		DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnIncrementSwitch);

	UPROPERTY(EditAnywhere)
		TArray<AMainCharacter*> character;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AMainCharacter> current = nullptr;
	
	bool isControlled = false;

	FOnIncrementSwitch onIncrementSwitch;
public:	
	ASwitcher();

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void Switch();
	void IncrementSwitch();
};
