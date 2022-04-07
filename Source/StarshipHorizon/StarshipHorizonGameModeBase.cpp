// Copyright Epic Games, Inc. All Rights Reserved.


#include "StarshipHorizonGameModeBase.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "Pawns/PlayerPawn.h"

AStarshipHorizonGameModeBase::AStarshipHorizonGameModeBase():
	PlayerRecoverTime(3)
{
	EnemySpawnController = CreateDefaultSubobject<UEnemySpawnController>(TEXT("EnemySpawnController"));
	HealthsComponent = CreateDefaultSubobject<UGameHealthComponent>(TEXT("HealthComponent"));
}

void AStarshipHorizonGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	HealthsComponent->HealthsEnded.AddDynamic(this, &AStarshipHorizonGameModeBase::EndGame);

	PlayerPawn= Cast<APlayerPawn> (UGameplayStatics::GetPlayerPawn(this, 0));

	PlayerPawn -> PawnDamaged.AddDynamic(this, &AStarshipHorizonGameModeBase::ExplodePawn);
}

void AStarshipHorizonGameModeBase::ExplodePawn_Implementation()
{
	PlayerPawn->ExplodePawn();
	HealthsComponent->ChangeHealths(-1);

	GetWorld()->GetTimerManager().SetTimer(RecoverTime, this, &AStarshipHorizonGameModeBase::RecoverPawn, PlayerRecoverTime, false);
}

void AStarshipHorizonGameModeBase::RecoverPawn_Implementation()
{
	PlayerPawn->RecoverPawn();
}

void AStarshipHorizonGameModeBase::EndGame()
{
	GameOver.Broadcast();
	UE_LOG(LogTemp, Log, TEXT("GAME OVER!!!"));
}
