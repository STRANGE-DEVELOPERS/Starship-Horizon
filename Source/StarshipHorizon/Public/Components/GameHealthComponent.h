// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameHealthComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHealhtsEndedEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHealhtsChangedEvent, int, ChangeValue);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STARSHIPHORIZON_API UGameHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGameHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Game Health")
	int Healths;

	
public:	
	UFUNCTION()
	void OnOwnerDamaged(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
	
	UFUNCTION(BlueprintCallable, Category = "Game Health")
	void ChangeHealths(int ByValue);

	UFUNCTION(BlueprintCallable, Category = "Game Health")
	void AddHealths(int ByValue);

	UFUNCTION(BlueprintPure, Category = "Game Health")
	int GetHealths();
		
	UPROPERTY(BlueprintAssignable, Category = "Game Health")
	FHealhtsEndedEvent HealthsEnded;

	UPROPERTY(BlueprintAssignable, Category = "Game Health")
	FHealhtsChangedEvent HealthsChanged;

	UPROPERTY(BlueprintReadOnly, Category = "Game")
	float	GameHealths;

};
