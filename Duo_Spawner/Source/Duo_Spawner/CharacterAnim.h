// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MainCharacter.h"
#include "CharacterAnim.generated.h"


UCLASS()
class DUO_SPAWNER_API UCharacterAnim : public UAnimInstance
{
	GENERATED_BODY()

	UPROPERTY()
		TObjectPtr<AMainCharacter> character = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
		float speed = 0;
public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float _deltaSeconds) override;
	float GetSpeed();
	UFUNCTION() void SetSpeed(const float _speed);
};
