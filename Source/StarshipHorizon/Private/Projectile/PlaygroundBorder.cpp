// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile/PlaygroundBorder.h"
#include "Components/BoxComponent.h"
#include "Pawns/PlayerPawn.h"

// Sets default values
APlaygroundBorder::APlaygroundBorder()
{
    Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Triger"));
    SetRootComponent(Trigger);

    Trigger->SetCollisionProfileName("OverlapAll");


}

void APlaygroundBorder::NotifyActorEndOverlap(AActor* OtherActor)
{
    Super::NotifyActorEndOverlap(OtherActor);

    if (!OtherActor) return;

    if (Cast<APlayerPawn>(OtherActor)) return;

    UE_LOG(LogTemp, Log, TEXT("OUT OF PLAYGROUND: %s"), *OtherActor->GetName());

    OtherActor->Destroy();
}

