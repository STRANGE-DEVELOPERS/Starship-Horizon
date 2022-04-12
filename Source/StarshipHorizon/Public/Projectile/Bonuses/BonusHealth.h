// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile/Bonuses/Bonus.h"
#include "BonusHealth.generated.h"

/**
 * 
 */
UCLASS()
class STARSHIPHORIZON_API ABonusHealth : public ABonus
{
	GENERATED_BODY()
	
protected:

	virtual void BonusCollected_Implementation() override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bonus")
	int Health;
};
