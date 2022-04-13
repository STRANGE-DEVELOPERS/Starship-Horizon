// Copyright Epic Games, Inc. All Rights Reserved.


#include "StarshipHorizonGameModeBase.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "Pawns/PlayerPawn.h"

AStarshipHorizonGameModeBase::AStarshipHorizonGameModeBase():
	PlayerRecoverTime(3),
	CurrentShootLevel(-1)
{
	EnemySpawnController = CreateDefaultSubobject<UEnemySpawnController>(TEXT("EnemySpawnController"));
	HealthsComponent = CreateDefaultSubobject<UGameHealthComponent>(TEXT("HealthComponent"));
}

void AStarshipHorizonGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	HealthsComponent->HealthsEnded.AddDynamic(this, &AStarshipHorizonGameModeBase::EndGame);

	PlayerPawn= Cast<APlayerPawn> (UGameplayStatics::GetPlayerPawn(this, 0));

	if (!PlayerPawn) return;

	ChangeShootLevel(true);

	PlayerPawn -> PawnDamaged.AddDynamic(this, &AStarshipHorizonGameModeBase::ExplodePawn);
}

void AStarshipHorizonGameModeBase::ExplodePawn_Implementation()
{
	PlayerPawn->ExplodePawn();
	HealthsComponent->ChangeHealths(-1);

	ChangeShootLevel(false);

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

void AStarshipHorizonGameModeBase::AddPoints(int Points)
{
	GamePoints += Points;
}


void AStarshipHorizonGameModeBase::AddHealth(int Healths)
{
	HealthsComponent->ChangeHealths(Healths);

	UE_LOG(LogTemp, Log, TEXT("Add Health"));
}

bool AStarshipHorizonGameModeBase::ChangeShootLevel(bool Up)
{
	PlayerPawn = Cast<APlayerPawn>(UGameplayStatics::GetPlayerPawn(this, 0));
	if (!PlayerPawn) return false;

	int NewLevel = FMath::Clamp(CurrentShootLevel + (Up ? 1 : -1), 0, ShootInfoLevels.Num()-1);

	if (NewLevel == CurrentShootLevel) return true;

	CurrentShootLevel = NewLevel;

	PlayerPawn->ShootComponent->ShootInfos = ShootInfoLevels[CurrentShootLevel].ShootInfos;
	PlayerPawn->ShootComponent->ShootPeriod = ShootInfoLevels[CurrentShootLevel].ShootPeriod;

	return true;
}
