// Fill out your copyright notice in the Description page of Project Settings.


#include "PathSystem.h"

APathSystem::APathSystem()
{
	PrimaryActorTick.bCanEverTick = true;

}

FPath APathSystem::RandomPath()
{
	const int _size = allPath.Num();
	const int _rand = FMath::RandHelper(_size);
	return allPath[_rand];
}

void APathSystem::BeginPlay()
{
	Super::BeginPlay();
	
}

void APathSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebug();
}

void APathSystem::DrawDebug()
{
	for (size_t i = 0; i < allPath.Num(); i++)
	{
		allPath[i].DrawPath(GetWorld());
	}
}

