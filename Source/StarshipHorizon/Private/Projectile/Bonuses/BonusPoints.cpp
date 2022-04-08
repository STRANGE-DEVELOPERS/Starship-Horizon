// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile/Bonuses/BonusPoints.h"
#include "Kismet/GameplayStatics.h"
#include "StarshipHorizon/StarshipHorizonGameModeBase.h"

void ABonusPoints::BonusCollected_Implementation()
{
	AStarshipHorizonGameModeBase* GameMode = Cast<AStarshipHorizonGameModeBase>(UGameplayStatics::GetGameMode(this));
	if (GameMode) GameMode->AddPoints(Points);

	Super::BonusCollected_Implementation();
}
