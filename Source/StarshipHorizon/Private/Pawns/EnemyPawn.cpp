// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/EnemyPawn.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "StarshipHorizon/StarshipHorizonGameModeBase.h"

// Sets default values
AEnemyPawn::AEnemyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PawnCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("PawnCollision"));
	RootComponent = PawnCollision;
	PawnCollision->SetCollisionProfileName("Name");

	PawnMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PawnMesh"));
	PawnMesh->SetupAttachment(PawnCollision, NAME_None);
	PawnMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	ShootComponent1 = CreateAbstractDefaultSubobject<UShootComponent>(TEXT("ShootComponent"));
	HealthComponent = CreateAbstractDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
}

// Called when the game starts or when spawned
void AEnemyPawn::BeginPlay()
{
	Super::BeginPlay();
	
	HealthComponent->OnHealthEnded.AddDynamic(this, &AEnemyPawn::KillPawn);
	OnActorBeginOverlap.AddDynamic(this, &AEnemyPawn::OnEnemyOverlap);
}

void AEnemyPawn::SpawnBonuses()
{
	FRandomStream Random;
	Random.GenerateNewSeed();

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	for (FBonusChance Bonus : PossibleBonusses)
	{
		float RandChance = Random.RandRange(0.f, 100.f);
		UE_LOG(LogTemp, Log, TEXT("BONUS CHANSE: %f"), RandChance);
		if (RandChance < Bonus.Chance)
		{
			GetWorld()->SpawnActor<ABonus>(Bonus.BonusClass, GetActorLocation(), FRotator(0.f), SpawnParameters);
			UE_LOG(LogTemp, Log, TEXT("BONUS!!"));
		}
	}
}

void AEnemyPawn::KillPawn()
{
	AStarshipHorizonGameModeBase* GameMode = Cast<AStarshipHorizonGameModeBase>(UGameplayStatics::GetGameMode(this));
	if (GameMode) GameMode->AddPoints(DestroyPoints);

	SpawnBonuses();

	DestroyPawn();
}

void AEnemyPawn::DestroyPawn()
{
	/*AStarshipHorizonGameModeBase* GameMode = Cast<AStarshipHorizonGameModeBase>(UGameplayStatics::GetGameMode(this));
	if (GameMode) GameMode->AddPoints(DestroyPoints);*/

	Destroy();
}

void AEnemyPawn::OnEnemyOverlap(AActor* OverlapedActor, AActor* OtherActor)
{
	if (OtherActor != UGameplayStatics::GetPlayerPawn(this, 0)) return;

	float AppliedDamage = UGameplayStatics::ApplyDamage(OtherActor, 100.f, GetController(), this, UDamageType::StaticClass());

	if(AppliedDamage>0.f) DestroyPawn();
}

// Called every frame
void AEnemyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

