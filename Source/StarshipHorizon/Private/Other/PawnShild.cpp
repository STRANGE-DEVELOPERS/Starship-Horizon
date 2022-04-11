// Fill out your copyright notice in the Description page of Project Settings.


#include "Other/PawnShild.h"
#include "Pawns/PlayerPawn.h"
#include "Engine/World.h"
#include "TimerManager.h"

// Sets default values
APawnShild::APawnShild() :
	ShieldTime(5.f)
{
 	

}

void APawnShild::ActivateShield(APlayerPawn* PlayerPawn)
{
	if (!PlayerPawn)
	{
		Destroy();
		return;
	}

	ShieldForPawn = PlayerPawn;

	PlayerPawn->CanRecieveDamage =false;

	FAttachmentTransformRules AttachRules = FAttachmentTransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, false);

	AttachToActor(PlayerPawn, AttachRules);
	
	GetWorld()->GetTimerManager().SetTimer(ShieldTimer, this, &APawnShild::DeactivateShield, ShieldTime, false);
}

void APawnShild::DeactivateShield()
{
	if (!ShieldForPawn) return;

	ShieldForPawn->CanRecieveDamage = true;

	Destroy();
}