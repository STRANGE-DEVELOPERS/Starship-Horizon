// Fill out your copyright notice in the Description page of Project Settings.


#include "Other/PawnShild.h"
#include "Engine/World.h"
#include "Pawns/PlayerPawn.h"

// Sets default values
APawnShild::APawnShild()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void APawnShild::ActivateShield(APlayerPawn* PlayerPawn)
{
	PlayerPawn->bCanBeDamaged=false;

	FAttachmentTransformRules AttachRules = FAttachmentTransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, false);

	AttachToActor(PlayerPawn, AttachRules);
	
}

void APawnShild::DiactivateShield()
{

}