// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PathPoint.generated.h"

UCLASS()
class DUO_SPAWNER_API APathPoint : public AActor
{
	GENERATED_BODY()
	
public:
	APathPoint();

private:	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void DrawDebug();
};
