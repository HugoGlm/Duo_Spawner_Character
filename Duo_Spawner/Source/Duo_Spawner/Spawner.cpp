// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"

ASpawner::ASpawner()
{
	PrimaryActorTick.bCanEverTick = true;

}
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	
}
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

