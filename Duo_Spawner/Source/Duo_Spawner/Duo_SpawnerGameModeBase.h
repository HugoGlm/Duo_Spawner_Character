// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include"MainCharacter.h"
#include"PathSystem.h"
#include "Duo_SpawnerGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class DUO_SPAWNER_API ADuo_SpawnerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	UPROPERTY()
		TArray<AMainCharacter*> allMainCharacter;
	UPROPERTY()
		TObjectPtr<APathSystem> path = nullptr;
public:
	FORCEINLINE TArray<AMainCharacter*> GetTabMainCharacter() { return allMainCharacter; }
	void SpawnCharacter(TSubclassOf<AMainCharacter> _type,FVector _location);
};
