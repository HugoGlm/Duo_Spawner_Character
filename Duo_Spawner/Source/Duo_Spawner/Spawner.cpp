// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"
#include <Kismet/KismetMathLibrary.h>

ASpawner::ASpawner()
{
	PrimaryActorTick.bCanEverTick = true;

}
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	onTimerEnd.AddDynamic(this, &ASpawner::SpawnEntity);
}
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateTimer(settings.time, settings.maxTime);
	DrawDebug();
	DrawDebugTimer();
}

void ASpawner::SpawnEntity()
{
	if (!spawnCharacter)
		return;
	GetWorld()->SpawnActor<AMainCharacter>(spawnCharacter, GetActorLocation() + settings.locationSpawnObject, FRotator::ZeroRotator);
}

void ASpawner::UpdateTimer(float& _timer, const float& _maxTime)
{
	if (!settings.isStarted)
		return;
	_timer += GetWorld()->DeltaTimeSeconds;
	if (_timer > _maxTime)
	{
		onTimerEnd.Broadcast();
		_timer = 0;
		settings.isStarted = false;
	}
}

void ASpawner::DrawDebug()
{
	DrawDebugSphere(GetWorld(), GetActorLocation(), 20, 10, FColor::Red);
}

void ASpawner::DrawDebugTimer()
{
	const FColor _lerpColor = UKismetMathLibrary::LinearColorLerp(FColor::Red.ReinterpretAsLinear(), FColor::Green.ReinterpretAsLinear(),settings.GetTimeProgress()).ToFColor(true);
	DrawDebugBox(GetWorld(), GetActorLocation() + GetActorUpVector() * 3, FVector(settings.GetTimeProgress() * 3), _lerpColor);
}

