// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"

AMainCharacter::AMainCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	springArm = CreateDefaultSubobject<USpringArmComponent>("springArm");
	camera = CreateDefaultSubobject<UCameraComponent>("camera");
	springArm->SetupAttachment(RootComponent);
	camera->SetupAttachment(springArm);
	bUseControllerRotationYaw = true;
}
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetFirstPlayerController()->SetPawn(this);
	GetWorld()->GetFirstPlayerController()->Possess(this);
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

