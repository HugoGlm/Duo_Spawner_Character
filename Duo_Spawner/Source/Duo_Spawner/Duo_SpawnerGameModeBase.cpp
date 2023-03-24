// Copyright Epic Games, Inc. All Rights Reserved.


#include "Duo_SpawnerGameModeBase.h"

void ADuo_SpawnerGameModeBase::SpawnCharacter(TSubclassOf<AMainCharacter> _type, FVector _location)
{
	AMainCharacter* _chara = GetWorld()->SpawnActor<AMainCharacter>(_type, _location, FRotator::ZeroRotator);
	if (!path)
		return;
	_chara->InitPath(path->RandomPath());
	allMainCharacter.Add(_chara);
}
