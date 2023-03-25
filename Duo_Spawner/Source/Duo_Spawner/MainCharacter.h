// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include"MovePathComponent.h"
#include "MainCharacter.generated.h"

USTRUCT()
struct FInput
{
	GENERATED_BODY()
	UPROPERTY()
		FName vertical = "Vertical";
	UPROPERTY()
		FName rotate = "Rotate";
	UPROPERTY()
		FName unPosses = "UnPosses";
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
		TObjectPtr<UMovePathComponent> movePath = nullptr;
	UPROPERTY(EditAnywhere)
		FInput input;
	FOnMoveForward onMoveForward;
	bool isControlled = false;
public:
	AMainCharacter();
	FORCEINLINE FOnMoveForward& OnMoveForward(){ return onMoveForward; }
	FORCEINLINE void SetController(const bool& _value) { isControlled = _value; }
	FORCEINLINE bool GetController() { return isControlled; }
	void InitPath(FPath _path);
	FORCEINLINE FVector GetOffset() { return FVector(0, 0, GetCapsuleComponent()->GetScaledCapsuleHalfHeight()); }
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForward(float _axis);
	void Rotate(float _axis);
	void UnPossesChara();
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
