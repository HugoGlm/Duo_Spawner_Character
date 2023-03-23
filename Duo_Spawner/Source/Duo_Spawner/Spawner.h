// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class DUO_SPAWNER_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawner();

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
