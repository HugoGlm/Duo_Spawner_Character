// Fill out your copyright notice in the Description page of Project Settings.


#include "PathComponent.h"

UPathComponent::UPathComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}
void UPathComponent::BeginPlay()
{
	Super::BeginPlay();
	InitPoints();
	point = GetOwner()->GetActorLocation();
}
void UPathComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	MoveOnPath(); 
	DrawDebug();
}
void UPathComponent::IsValidPoint()
{

}
void UPathComponent::MoveOnPath()
{
	const FVector _spawn = point;
	DrawDebugBox(GetWorld(), _spawn, FVector(10), FColor::Red);
}
void UPathComponent::InitPoints()
{
	for (int i = 0; i < settings.numberPoints; i++)
	{
		point = GetOwner()->GetActorLocation() + settings.position * i;
		points.Add(point);
	}
}
void UPathComponent::DrawDebug()
{
	for (int i = 0; i < points.Num(); i++)
	{
		DrawDebugSphere(GetWorld(), settings.position * i, 20, 5, FColor::Magenta);
		DrawDebugLine(GetWorld(), GetOwner()->GetActorLocation(), settings.position * i, FColor::Blue);
	}
}
