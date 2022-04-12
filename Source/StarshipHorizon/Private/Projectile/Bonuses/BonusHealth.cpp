// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile/Bonuses/BonusHealth.h"
#include "Kismet/GameplayStatics.h"
#include "Components/GameHealthComponent.h"
#include "StarshipHorizon/StarshipHorizonGameModeBase.h"

void ABonusHealth::BonusCollected_Implementation()
{
	AStarshipHorizonGameModeBase* GameMode = Cast<AStarshipHorizonGameModeBase>(UGameplayStatics::GetGameMode(this));
	if (GameMode) GameMode->AddHealth(Health);

	Super::BonusCollected_Implementation();

}
