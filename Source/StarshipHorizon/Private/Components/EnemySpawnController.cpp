// Fill out your copyright notice in the Description page of Project Settings.



#include "Components/EnemySpawnController.h"
#include "Engine/World.h"
#include "TimerManager.h"


// Called when the game starts
void UEnemySpawnController::BeginPlay()
	
{
	Super::BeginPlay();

	// ...

	Random.GenerateNewSeed();

	StartSpawnStage();


}


void UEnemySpawnController::Deactivate()
{
	Super::Deactivate();

	GetWorld()->GetTimerManager().ClearTimer(ChangeStageTimer);
	GetWorld()->GetTimerManager().ClearTimer(EnemySpawnTimer);
}

void UEnemySpawnController::StartSpawnStage()

{


	SpawnStage = SpawnInfos[Random.RandRange(0, SpawnInfos.Num() - 1)];

	EnemiesSpawned = 0;
	SpawnEnemy();

	float ChangeStageTime = Random.RandRange(StageMinDelay, StageMaxDelay)* ChangeStageTimeMultiplier;

	GetWorld()->GetTimerManager().SetTimer(ChangeStageTimer, this, &UEnemySpawnController::StartSpawnStage, ChangeStageTime, false);
}

void UEnemySpawnController::SpawnEnemy()
{
	FActorSpawnParameters SpawnParameters;
	GetWorld()->SpawnActor<AEnemyPawn>(SpawnStage.EnemyClass, SpawnStage.SpawnTransform, SpawnParameters);


	EnemiesSpawned++;
	if (EnemiesSpawned < SpawnStage.NumOfEnemies) {

		GetWorld()->GetTimerManager().SetTimer(EnemySpawnTimer, this, &UEnemySpawnController::SpawnEnemy, SpawnStage.SpawnDelay, false);
	}

};

// Called every frame
