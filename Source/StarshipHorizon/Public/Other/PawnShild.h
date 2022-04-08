// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PawnShild.generated.h"


class APlayerPawn;

UCLASS()
class STARSHIPHORIZON_API APawnShild : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APawnShild();


public:	

	UFUNCTION(BlueprintCallable, Category = "Shild")
	void ActivateShield(APlayerPawn* PlayerPawn);

	UFUNCTION(BlueprintCallable, Category = "Shild")
	void DiactivateShield();

};
