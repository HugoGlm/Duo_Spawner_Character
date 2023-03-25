// Fill out your copyright notice in the Description page of Project Settings.


#include "MovePathComponent.h"
#include"MainCharacter.h"
#include"PathSystem.h"
#include"Kismet/KismetMathLibrary.h"

UMovePathComponent::UMovePathComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMovePathComponent::InitPoints(FPath _path)
{
	for (size_t i = 0; i < _path.points.Num(); i++)
	{
		allPoints.Add(_path.points[i]);
	}
}

void UMovePathComponent::BeginPlay()
{
	Super::BeginPlay();
	Init();
}


void UMovePathComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	MoveForPoints();
}

void UMovePathComponent::Init()
{
	AMainCharacter* _owner = Cast<AMainCharacter>(GetOwner());
	owner = _owner;
}

void UMovePathComponent::MoveForPoints()
{
	if (!owner||owner->GetController())
		return;
	const FVector _offset = owner->GetOffset();
	const FVector _newLocation = FMath::VInterpConstantTo(owner->GetActorLocation(), allPoints[index]->GetActorLocation() + _offset, GetWorld()->DeltaTimeSeconds, speed);
	const FRotator _newRota = UKismetMathLibrary::FindLookAtRotation(_newLocation, allPoints[index]->GetActorLocation() + _offset);
	owner->SetActorLocation(_newLocation);
	owner->SetActorRotation(_newRota);
	if (FVector::Distance(owner->GetActorLocation(), allPoints[index]->GetActorLocation()+_offset) < 15)
	{
		index++;
		if (index == allPoints.Num())
			GetOwner()->Destroy();
	}
}

