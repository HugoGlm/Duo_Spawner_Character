// Fill out your copyright notice in the Description page of Project Settings.


#include "Switcher.h"

ASwitcher::ASwitcher()
{
	PrimaryActorTick.bCanEverTick = true;

}
void ASwitcher::BeginPlay()
{
	Super::BeginPlay();
	Switch();
}
void ASwitcher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ASwitcher::Switch()
{
	if (isControlled)
		return;
	GetWorld()->GetFirstPlayerController()->InputComponent->BindAction("Switch", IE_Pressed, this, &ASwitcher::IncrementSwitch);
}
void ASwitcher::IncrementSwitch()
{

}

