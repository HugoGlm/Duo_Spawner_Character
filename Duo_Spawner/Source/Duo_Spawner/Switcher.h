// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include"Duo_SpawnerGameModeBase.h"
#include "Switcher.generated.h"

USTRUCT()
struct FInputSwitcheur
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		FName switchChara = "Switch";
};

UCLASS()
class DUO_SPAWNER_API ASwitcher : public AActor
{
	GENERATED_BODY()
		DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnIncrementSwitch);
	UPROPERTY(EditAnywhere)
		TObjectPtr<AMainCharacter> currentChara = nullptr;	
	UPROPERTY(EditAnywhere)
		TObjectPtr<AController> fpc = nullptr;
	UPROPERTY(EditAnywhere)
		FInputSwitcheur input;

	int currentIndexSwitch = 0;
	FOnIncrementSwitch onIncrementSwitch;
public:	
	ASwitcher();
	TArray<AMainCharacter*> GetTabMainCharacterSpawn();
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void Switch();
	void UnSwitch();
	void IncrementSwitch();
	void DecrementSwitch();
	void Init();
};
