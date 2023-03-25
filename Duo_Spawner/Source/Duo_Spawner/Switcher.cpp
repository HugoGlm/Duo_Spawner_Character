// Fill out your copyright notice in the Description page of Project Settings.


#include "Switcher.h"
#include"MainCharacter.h"
#include"Duo_SpawnerGameModeBase.h"

ASwitcher::ASwitcher()
{
	PrimaryActorTick.bCanEverTick = true;

}
void ASwitcher::BeginPlay()
{
	Super::BeginPlay();
}
void ASwitcher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebug();

}
void ASwitcher::DrawDebug()
{
	if (!currentChara)
		return;
	DrawDebugSphere(GetWorld(), currentChara->GetActorLocation() + currentChara->GetActorUpVector() * 100, 20, 25, FColor::Cyan);
}
void ASwitcher::Switch()
{
	if (!currentChara)
		return;
	GetWorld()->GetFirstPlayerController()->Possess(currentChara);
	currentChara->SetController(true);
}

void ASwitcher::IncrementSwitch()
{
	currentIndexSwitch++;
	if (currentIndexSwitch > GetTabMainCharacterSpawn().Num() - 1)
		currentIndexSwitch = 0;
	currentChara = GetTabMainCharacterSpawn()[currentIndexSwitch];
}

void ASwitcher::DecrementSwitch()
{
	currentIndexSwitch--;
	if (currentIndexSwitch < 0)
		currentIndexSwitch = GetTabMainCharacterSpawn().Num() - 1;
	currentChara = GetTabMainCharacterSpawn()[currentIndexSwitch];
}

TArray<AMainCharacter*> ASwitcher::GetTabMainCharacterSpawn()
{
	ADuo_SpawnerGameModeBase* _gm = GetWorld()->GetAuthGameMode<ADuo_SpawnerGameModeBase>();
	//if (!_gm)
	//	return ;
	return _gm->GetTabMainCharacter();
}
