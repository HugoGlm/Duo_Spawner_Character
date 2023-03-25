// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Switcher.generated.h"

USTRUCT()
struct FInputSwitcheur
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		FName switchChara = "Switch";
};

class AMainCharacter;
UCLASS()
class DUO_SPAWNER_API ASwitcher : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		TObjectPtr<AMainCharacter> currentChara = nullptr;
	UPROPERTY(EditAnywhere)
		FInputSwitcheur input;

	int currentIndexSwitch = 0;
public:	
	ASwitcher();
	TArray<AMainCharacter*> GetTabMainCharacterSpawn();
	void Switch();
	void IncrementSwitch();
	void DecrementSwitch();
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void DrawDebug();
};
