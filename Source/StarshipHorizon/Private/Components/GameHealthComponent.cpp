// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/GameHealthComponent.h"

// Sets default values for this component's properties
UGameHealthComponent::UGameHealthComponent():
	Healths(3)
{
	
}


// Called when the game starts
void UGameHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UGameHealthComponent::ChangeHealths(int ByValue)
{
	Healths += ByValue;
	HealthsChanged.Broadcast(ByValue);

	if (Healths <= 0.f)
	{
		HealthsEnded.Broadcast();
	}
}

int UGameHealthComponent::GetHealths()
{
	return Healths;
}



