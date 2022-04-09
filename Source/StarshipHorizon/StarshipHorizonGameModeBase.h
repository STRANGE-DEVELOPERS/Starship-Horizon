// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Components/EnemySpawnController.h"
#include "Components/GameHealthComponent.h"
#include "Components/ShootComponent.h"
#include "StarshipHorizonGameModeBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGameOverEvent);

USTRUCT(BlueprintType)
struct FShootInfoLevel
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shooting")
	TArray<FShootInfo> ShootInfos;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Shooting")
	float ShootPeriod;

};


UCLASS()
class STARSHIPHORIZON_API AStarshipHorizonGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

		AStarshipHorizonGameModeBase();

	virtual void BeginPlay() override;

protected:

	UFUNCTION(BlueprintNativeEvent, Category = "Game")
		void ExplodePawn();
	void ExplodePawn_Implementation();

	UFUNCTION(BlueprintNativeEvent, Category = "Game")
		void RecoverPawn();
	void RecoverPawn_Implementation();

	FTimerHandle RecoverTime;

public:
	/** enemy spawn component  */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemies")
	UEnemySpawnController* EnemySpawnController;

	/** game health component  */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game Health")
	UGameHealthComponent* HealthsComponent;

	UPROPERTY(BlueprintAssignable, Category = "Game")
	FGameOverEvent GameOver;

	UFUNCTION(BlueprintCallable, Category = "Game")
	void EndGame();

	UFUNCTION(BlueprintCallable, Category = "Game")
	void AddPoints(int Points);

	UFUNCTION(BlueprintCallable, Category = "Game")
	bool ChangeShootLevel(bool Up);

	UPROPERTY(BlueprintReadWrite, Category = "Game")
	float PlayerRecoverTime;

	UPROPERTY(BlueprintReadOnly, Category = "Game")
	class	APlayerPawn* PlayerPawn;

	UPROPERTY(BlueprintReadOnly, Category = "Game")
	int	GamePoints;

	UPROPERTY(EditAnywhere, Category = "Shooting")
	TArray<FShootInfoLevel> ShootInfoLevels;

	UPROPERTY(BlueprintReadOnly, Category = "Shooting")
	int CurrentShootLevel;

};
