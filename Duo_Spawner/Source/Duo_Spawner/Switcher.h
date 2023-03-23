// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Switcher.generated.h"

UCLASS()
class DUO_SPAWNER_API ASwitcher : public AActor
{
	GENERATED_BODY()
	
public:	
	ASwitcher();

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
