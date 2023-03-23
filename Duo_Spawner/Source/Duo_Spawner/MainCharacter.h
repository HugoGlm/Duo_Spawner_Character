// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "MainCharacter.generated.h"

USTRUCT()
struct FInput
{
	GENERATED_BODY()
	UPROPERTY()
		FName vertical = "Vertical";
	UPROPERTY()
		FName rotate = "Rotate";
};


UCLASS()
class DUO_SPAWNER_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()
		DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveForward, float, _axis);
	UPROPERTY(EditAnywhere)
		TObjectPtr<USpringArmComponent> springArm = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditAnywhere)
		FInput input;
	FOnMoveForward onMoveForward;
public:
	AMainCharacter();
	FORCEINLINE FOnMoveForward& OnMoveForward(){ return onMoveForward; }
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForward(float _axis);
	void Rotate(float _axis);
};
