// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HealthComponent.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent():
  Health(100)
{
	
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::OnOwnerDamahed);
}

void UHealthComponent::OnOwnerDamahed(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Instigst, AActor* DamageCause)
{
	ChangeHealth(-Damage);
}

void UHealthComponent::ChangeHealth(float Value)
{
	Health += Value;

	if (Health <= 0.f)
	{
		GetOwner()->OnTakeAnyDamage.RemoveDynamic(this, &UHealthComponent::OnOwnerDamahed);

		OnHealthEnded.Broadcast();
	}

}

float UHealthComponent::GetHealth()
{
	return Health;
}


