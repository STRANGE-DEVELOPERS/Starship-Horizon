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
	
protected:

	FTimerHandle ShieldTimer;

	class APlayerPawn* ShieldForPawn;

public:	
	// Sets default values for this actor's properties
	APawnShild();

	UFUNCTION(BlueprintCallable, Category = "Shild")
	void ActivateShield(APlayerPawn* PlayerPawn);

	UFUNCTION(BlueprintCallable, Category = "Shild")
	void DeactivateShield();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Shild")
	float ShieldTime;

};
