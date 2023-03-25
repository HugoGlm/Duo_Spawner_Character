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

int ASpawner::GetTabMainCharacterSize()
{
	ADuo_SpawnerGameModeBase* _gm = GetWorld()->GetAuthGameMode<ADuo_SpawnerGameModeBase>();
	if (!_gm)
		return -1;
	return _gm->GetTabMainCharacter().Num();
}

void ASpawner::SpawnEntity()
{
	if (!spawnCharacter||!settings.spawnLocation)
		return;
	int _size = GetTabMainCharacterSize();
	if (_size < 0)
		return;
	if ( _size < settings.numberMaxEntity)
	{
		ADuo_SpawnerGameModeBase* _gm = GetWorld()->GetAuthGameMode<ADuo_SpawnerGameModeBase>();
		if (!_gm)
			return;
		_gm->SpawnCharacter(spawnCharacter, settings.spawnLocation->GetActorLocation());
	}
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
		if (settings.isLooping)
			settings.isStarted = true;
	}
}

void ASpawner::DrawDebug()
{
	DrawDebugSphere(GetWorld(), GetActorLocation(), 20, 10, FColor::Red);
	DrawDebugSphere(GetWorld(), settings.spawnLocation->GetActorLocation(), 20, 10, FColor::Red);
	DrawDebugLine(GetWorld(), GetActorLocation(), settings.spawnLocation->GetActorLocation(), FColor::Yellow);
}

void ASpawner::DrawDebugTimer()
{
	const FColor _lerpColor = UKismetMathLibrary::LinearColorLerp(FColor::Red.ReinterpretAsLinear(), FColor::Green.ReinterpretAsLinear(),settings.GetTimeProgress()).ToFColor(true);
	DrawDebugBox(GetWorld(), GetActorLocation() + GetActorUpVector() * 3, FVector(settings.GetTimeProgress() * 3), _lerpColor);
}

