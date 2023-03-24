// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include"PathPoint.h"
#include "MovePathComponent.generated.h"

class AMainCharacter;
struct FPath;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUO_SPAWNER_API UMovePathComponent : public UActorComponent
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere)
		TArray<APathPoint*> allPoints;
	UPROPERTY(EditAnywhere)
		float speed = 100;
	UPROPERTY(VisibleAnywhere)
		int index = 0;
	UPROPERTY()
		TObjectPtr<AMainCharacter> owner = nullptr;

public:	
	UMovePathComponent();
	void InitPoints(FPath _path);
private:	
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Init();
	void MoveForPoints();
};
