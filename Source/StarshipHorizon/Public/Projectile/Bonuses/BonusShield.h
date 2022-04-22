// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile/Bonuses/Bonus.h"
#include "BonusShield.generated.h"

class APawnShild;

UCLASS()
class STARSHIPHORIZON_API ABonusShield : public ABonus
{
	GENERATED_BODY()
	
protected:


	virtual void BonusCollected_Implementation() override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shild")
	TSubclassOf <APawnShild> ShildClass;

};
