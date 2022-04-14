// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Pawns/EnemyPawn.h"
#include "EnemySpawnController.generated.h"

USTRUCT(BlueprintType)
struct FEnemySpawnInfo
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		TSubclassOf<AEnemyPawn> EnemyClass = AEnemyPawn::StaticClass();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		FTransform SpawnTransform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		int32 NumOfEnemies;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		float SpawnDelay;
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))


class STARSHIPHORIZON_API UEnemySpawnController : public UActorComponent
{
	GENERATED_BODY()


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void Deactivate() override;

	void StartSpawnStage();

	void SpawnEnemy();

	FTimerHandle ChangeStageTimer;
	FTimerHandle EnemySpawnTimer;

	//FEnemySpawnInfo SpawnStage;
	int EnemiesSpawned;

	FRandomStream Random;

public:
	// Called every frame
	/** spawn infos for this game  */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemies")
		TArray<FEnemySpawnInfo> SpawnInfos;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemies")
		float StageMinDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemies")
		float StageMaxDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemies")
		FEnemySpawnInfo SpawnStage;

};