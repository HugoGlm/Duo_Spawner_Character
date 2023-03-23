// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include"MainCharacter.h"
#include "Spawner.generated.h"

USTRUCT()
struct FSpawnSettings
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, meta = (UIMin = 1, ClampMin = 1, UIMax = 10, ClampMax = 10))
		int numberMaxEntity = 2;
	UPROPERTY(EditAnywhere)
		FVector locationSpawnObject;
	UPROPERTY(EditAnywhere, Category = Timer, meta = (ClampMin = 1))
		float maxTime = 3;
	UPROPERTY(EditAnywhere, Category = Timer);
		bool isStarted = false;
	float time = 0;
	FORCEINLINE float GetTimeProgress() const { return time / maxTime * 100; }
};

UCLASS()
class DUO_SPAWNER_API ASpawner : public AActor
{
	GENERATED_BODY()
		DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTimerEnd);
	UPROPERTY(EditAnywhere)
		TSubclassOf<AMainCharacter> spawnCharacter = nullptr;
	UPROPERTY(EditAnywhere)
		FSpawnSettings settings;
	FOnTimerEnd onTimerEnd;
public:	
	ASpawner();
	FORCEINLINE FOnTimerEnd& OnTimerEnd() { return onTimerEnd; }
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	UFUNCTION() void SpawnEntity();
	void UpdateTimer(float& _timer, const float& _maxTime);
	void DrawDebug();
	void DrawDebugTimer();
};
