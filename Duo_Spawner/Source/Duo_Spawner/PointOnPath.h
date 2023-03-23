// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PointOnPath.generated.h"

UCLASS()
class DUO_SPAWNER_API APointOnPath : public AActor
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
public:	
	APointOnPath();

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
