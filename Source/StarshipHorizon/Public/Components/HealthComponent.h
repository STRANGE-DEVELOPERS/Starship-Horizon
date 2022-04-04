// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHealhtEndedEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STARSHIPHORIZON_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	float Health;

	UFUNCTION()
	void OnOwnerDamahed(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Instigst, AActor* DamageCause);

public:	

	UFUNCTION(BlueprintCallable, Category = "Health")
	void ChangeHealth(float Value);

	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealth();

	UPROPERTY(BlueprintAssignable, Category = "Health")
	FHealhtEndedEvent OnHealthEnded;
};
