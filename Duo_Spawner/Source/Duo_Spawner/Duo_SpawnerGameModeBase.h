// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include"MainCharacter.h"
#include"PathSystem.h"
#include"Switcher.h"
#include"PawnView.h"
#include "Duo_SpawnerGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class DUO_SPAWNER_API ADuo_SpawnerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere)
		TArray<AMainCharacter*> allMainCharacter;
	UPROPERTY(EditAnywhere)
		TSoftObjectPtr<APathSystem> path = nullptr;	
	UPROPERTY(EditAnywhere)
		TSoftObjectPtr<ASwitcher> switcher = nullptr;
	UPROPERTY(EditAnywhere)
		TSoftObjectPtr<APawnView> pawnView = nullptr;
public:
	FORCEINLINE TArray<AMainCharacter*> GetTabMainCharacter() { return allMainCharacter; }
	FORCEINLINE TSoftObjectPtr<ASwitcher> GetSwitcher() {return switcher; }
	FORCEINLINE TSoftObjectPtr<APawnView> GetPawnView() {return pawnView; }
	void SpawnCharacter(TSubclassOf<AMainCharacter> _type,FVector _location);
	FORCEINLINE void RemoveChara(AMainCharacter* _chara)
	{
		allMainCharacter.Remove(_chara);
	}
	FORCEINLINE void ResetPosses()
	{
		if (!pawnView)
			return;
		GetWorld()->GetFirstPlayerController()->Possess(pawnView.Get());
	}
};
