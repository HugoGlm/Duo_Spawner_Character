// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PointOnPath.h"
#include "PathComponent.generated.h"

USTRUCT()
struct FPathSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		int numberPoints;
	UPROPERTY(EditAnywhere)
		FVector position;

};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUO_SPAWNER_API UPathComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		TArray<FVector> points;

	UPROPERTY(VisibleAnywhere)
		int index;

	UPROPERTY(EditAnywhere)
		FPathSettings settings;

	FVector point;

public:	
	UPathComponent();

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void IsValidPoint();
	void MoveOnPath();
	void InitPoints();
	void DrawDebug();
};
