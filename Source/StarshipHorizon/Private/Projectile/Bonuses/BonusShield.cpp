// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile/Bonuses/BonusShield.h"
#include "Kismet/GameplayStatics.h"
#include "Pawns/PlayerPawn.h"
#include "Other/PawnShild.h"

void ABonusShield::BonusCollected_Implementation()
{
	APawn* Pawn = UGameplayStatics::GetPlayerPawn(this, 0);

	if (!Pawn) return;
	APlayerPawn* PlayerPawn = Cast<APlayerPawn>(Pawn);

	if(!PlayerPawn) return;

	APawnShild* Shield = GetWorld()->SpawnActor<APawnShild>(ShildClass);
	Shield->ActivateShield(PlayerPawn);

	Super::BonusCollected_Implementation();

}