// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include"Duo_SpawnerGameModeBase.h"
#include"PathSystem.h"

AMainCharacter::AMainCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	springArm = CreateDefaultSubobject<USpringArmComponent>("springArm");
	camera = CreateDefaultSubobject<UCameraComponent>("camera");
	movePath = CreateDefaultSubobject<UMovePathComponent>("movePath");
	springArm->SetupAttachment(RootComponent);
	camera->SetupAttachment(springArm);
	AddOwnedComponent(movePath);
	bUseControllerRotationYaw = true;
}
void AMainCharacter::InitPath(FPath _path)
{
	if (!movePath)
		return;
	movePath->InitPoints(_path);
}
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	//GetWorld()->GetFirstPlayerController()->SetPawn(this);
	//GetWorld()->GetFirstPlayerController()->Possess(this);
}
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(input.vertical, this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis(input.rotate, this, &AMainCharacter::Rotate);
}

void AMainCharacter::MoveForward(float _axis)
{
	AddMovementInput(GetActorForwardVector() * _axis);
	onMoveForward.Broadcast(_axis);
}

void AMainCharacter::Rotate(float _axis)
{
	AddControllerYawInput(_axis);
}

TArray<AMainCharacter*> AMainCharacter::GetTabMainCharacterSpawn()
{
	ADuo_SpawnerGameModeBase* _gm = GetWorld()->GetAuthGameMode<ADuo_SpawnerGameModeBase>();
	//if (!_gm)
	//	return;
	return _gm->GetTabMainCharacter();
}

void AMainCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	for (size_t i = 0; i < GetTabMainCharacterSpawn().Num(); i++)
	{
		GetTabMainCharacterSpawn().RemoveAt(i);
	}
}
