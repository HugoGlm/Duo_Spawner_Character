// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAnim.h"

void UCharacterAnim::NativeBeginPlay()
{
	character = Cast<AMainCharacter>(TryGetPawnOwner());
	if (!character)
		return;
	character->OnMoveForward().AddDynamic(this, &UCharacterAnim::SetSpeed);
}
void UCharacterAnim::NativeUpdateAnimation(float _deltaSeconds)
{
	speed = GetSpeed();
}
float UCharacterAnim::GetSpeed()
{
	const APawn* _target = TryGetPawnOwner();
	if (!_target)
		return 0;
	return _target->GetVelocity().GetSafeNormal().Size();
}
void UCharacterAnim::SetSpeed(const float _speed)
{
	speed = _speed;
}
