// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/BoxComponent.h"
#include "Components/ShootComponent.h"
#include "Components/HealthComponent.h"
#include "EnemyPawn.generated.h"

UCLASS()
class STARSHIPHORIZON_API AEnemyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void DestroyPawn();

	UFUNCTION()
	void OnEnemyOverlap(AActor* OverlapedActor, AActor* OtherActor);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn")
	UBoxComponent* PawnCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn")
	UStaticMeshComponent* PawnMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Shooting")
	UShootComponent* ShootComponent1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Shooting")
	UHealthComponent* HealthComponent;
};
