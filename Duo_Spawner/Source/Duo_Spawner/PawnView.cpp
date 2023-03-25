// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnView.h"
#include"Duo_SpawnerGameModeBase.h"

APawnView::APawnView()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("root");
}

void APawnView::InitPawn()
{
	GetWorld()->GetFirstPlayerController()->SetPawn(this);
	GetWorld()->GetFirstPlayerController()->Possess(this);
}

void APawnView::BeginPlay()
{
	Super::BeginPlay();
	InitPawn();
}

void APawnView::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APawnView::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction(input.possess, EInputEvent::IE_Pressed, this, &APawnView::Possess);
	PlayerInputComponent->BindAction(input.incrementIndex, EInputEvent::IE_Pressed, this, &APawnView::IncrementIndex);
	PlayerInputComponent->BindAction(input.decrementIndex, EInputEvent::IE_Pressed, this, &APawnView::DecrementIndex);
}

void APawnView::Possess()
{
	ADuo_SpawnerGameModeBase* _gm = GetWorld()->GetAuthGameMode<ADuo_SpawnerGameModeBase>();
	if (!_gm)
		return;
	_gm->GetSwitcher()->Switch();
}

void APawnView::IncrementIndex()
{
	ADuo_SpawnerGameModeBase* _gm = GetWorld()->GetAuthGameMode<ADuo_SpawnerGameModeBase>();
	if (!_gm)
		return;
	_gm->GetSwitcher()->IncrementSwitch();
}

void APawnView::DecrementIndex()
{
	ADuo_SpawnerGameModeBase* _gm = GetWorld()->GetAuthGameMode<ADuo_SpawnerGameModeBase>();
	if (!_gm)
		return;
	_gm->GetSwitcher()->DecrementSwitch();
}

