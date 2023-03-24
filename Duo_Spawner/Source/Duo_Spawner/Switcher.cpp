// Fill out your copyright notice in the Description page of Project Settings.


#include "Switcher.h"

ASwitcher::ASwitcher()
{
	PrimaryActorTick.bCanEverTick = true;

}
void ASwitcher::BeginPlay()
{
	Super::BeginPlay();
	Init();
}
void ASwitcher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ASwitcher::Switch()
{
	if (!fpc || GetTabMainCharacterSpawn().Num() == 0)
		return;
	AMainCharacter* _next = GetTabMainCharacterSpawn()[currentIndexSwitch];
	if (!_next)
		return;
	if (currentChara)
		currentChara->SetController(false);
	fpc->Possess(_next);
	currentChara = _next;
	currentChara->SetController(true);
}

void ASwitcher::IncrementSwitch()
{
	currentIndexSwitch++;
	onIncrementSwitch.Broadcast();
}


void ASwitcher::Init()
{
	onIncrementSwitch.AddDynamic(this, &ASwitcher::Switch);
	fpc = GetWorld()->GetFirstPlayerController();
	if (!fpc)
		return;
	fpc->InputComponent->BindAction(input.switchChara, EInputEvent::IE_Pressed, this, &ASwitcher::IncrementSwitch);
	Switch();
}

TArray<AMainCharacter*> ASwitcher::GetTabMainCharacterSpawn()
{
	ADuo_SpawnerGameModeBase* _gm = GetWorld()->GetAuthGameMode<ADuo_SpawnerGameModeBase>();
	//if (!_gm)
	//	return ;
	return _gm->GetTabMainCharacter();
}
