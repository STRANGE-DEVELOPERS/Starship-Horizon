// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sound/SoundBase.h"
#include "Bonus.generated.h"



UCLASS(Blueprintable)
class STARSHIPHORIZON_API ABonus : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABonus();

protected:
	

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UFUNCTION(BlueprintNativeEvent, Category = "Bonus")
	void BonusCollected();
	virtual void BonusCollected_Implementation();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audio")
	class USoundBase* DestroySound;

	virtual void Tick(float DeltaTime) override;

public:	
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Shooting")
	class	USphereComponent* Collision;

	
};
