// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile/Bonuses/BonusShootLevelUp.h"
#include "Kismet/GameplayStatics.h"
#include "StarshipHorizon/StarshipHorizonGameModeBase.h"

void ABonusShootLevelUp::BonusCollected_Implementation()
{
	AStarshipHorizonGameModeBase* GameMode = Cast<AStarshipHorizonGameModeBase>(UGameplayStatics::GetGameMode(this));
	if (!GameMode) return;

	GameMode->ChangeShootLevel(true);

	Super::BonusCollected_Implementation();

}
