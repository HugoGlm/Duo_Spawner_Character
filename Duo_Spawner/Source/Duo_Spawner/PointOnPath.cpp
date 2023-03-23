// Fill out your copyright notice in the Description page of Project Settings.


#include "PointOnPath.h"

APointOnPath::APointOnPath()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = mesh;
}
void APointOnPath::BeginPlay()
{
	Super::BeginPlay();
	
}
void APointOnPath::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

