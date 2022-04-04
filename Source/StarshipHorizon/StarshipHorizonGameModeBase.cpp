// Copyright Epic Games, Inc. All Rights Reserved.


#include "StarshipHorizonGameModeBase.h"

AStarshipHorizonGameModeBase::AStarshipHorizonGameModeBase()
{
	EnemySpawnController = CreateDefaultSubobject<UEnemySpawnController>(TEXT("EnemySpawnController"));
}
