// Copyright Epic Games, Inc. All Rights Reserved.


#include "StarshipHorizonGameModeBase.h"

AStarshipHorizonGameModeBase::AStarshipHorizonGameModeBase()
{
	EnemySpawnController = CreateDefaultSubobject<UEnemySpawnController>(TEXT("EnemySpawnController"));
	HealthsComponent = CreateDefaultSubobject<UGameHealthComponent>(TEXT("HealthComponent"));
}

void AStarshipHorizonGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	HealthsComponent->HealthsEnded.AddDynamic(this, &AStarshipHorizonGameModeBase::EndGame);
}

void AStarshipHorizonGameModeBase::EndGame()
{
	GameOver.Broadcast();
	UE_LOG(LogTemp, Log, TEXT("GAME OVER!!!"));
}
