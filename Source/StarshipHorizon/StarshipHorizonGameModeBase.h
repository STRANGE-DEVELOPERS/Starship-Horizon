// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Components/EnemySpawnController.h"
#include "Components/GameHealthComponent.h"
#include "StarshipHorizonGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class STARSHIPHORIZON_API AStarshipHorizonGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
		AStarshipHorizonGameModeBase();

public:
	/** enemy spawn component  */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemies")
		UEnemySpawnController* EnemySpawnController;

	/** game health component  */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game Health")
		UGameHealthComponent* HealthsComponent;
};
