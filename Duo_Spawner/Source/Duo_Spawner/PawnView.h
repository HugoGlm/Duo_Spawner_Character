// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnView.generated.h"

USTRUCT()
struct FInputPawn
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		FName possess = "Possess";
	UPROPERTY(EditAnywhere)
		FName decrementIndex = "Decrement_Index";
	UPROPERTY(EditAnywhere)
		FName incrementIndex = "Increment_Index";
};
UCLASS()
class DUO_SPAWNER_API APawnView : public APawn
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		FInputPawn input;

public:
	APawnView();

private:
	void InitPawn();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void Possess();
	void IncrementIndex();
	void DecrementIndex();
};
