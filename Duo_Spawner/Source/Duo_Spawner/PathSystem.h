// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include"PathPoint.h"
#include "PathSystem.generated.h"

USTRUCT()
struct FPath
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		TArray<APathPoint*> points;
	UPROPERTY(EditAnywhere)
		FColor color;
	FORCEINLINE void DrawPath(const UWorld* _world)
	{
		for (size_t i = 0; i < points.Num()-1; i++)
		{
			DrawDebugLine(_world, points[i]->GetActorLocation(), points[i + 1]->GetActorLocation(), color);
		}
	}
};
UCLASS()
class DUO_SPAWNER_API APathSystem : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		TArray<FPath> allPath;
	
public:
	APathSystem();
	FPath RandomPath();
public:	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void DrawDebug();
};
