// Fill out your copyright notice in the Description page of Project Settings.


#include "PathPoint.h"

APathPoint::APathPoint()
{
	PrimaryActorTick.bCanEverTick = true;

}

void APathPoint::BeginPlay()
{
	Super::BeginPlay();
	
}


void APathPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebug();
}

void APathPoint::DrawDebug()
{
	DrawDebugSphere(GetWorld(), GetActorLocation(), 20, 25, FColor::Magenta);
}

