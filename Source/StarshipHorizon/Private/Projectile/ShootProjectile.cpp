// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile/ShootProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/DamageType.h"
#include "Components/StaticMeshComponent.h"
#include "..\..\Public\Projectile\ShootProjectile.h"

// Sets default values
AShootProjectile::AShootProjectile()
	:
	ProjectilesSpeed(500.f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("ProjectileCollision"));
	RootComponent = Collision;
	Collision->SetCollisionResponseToAllChannels(ECR_Ignore);
	Collision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Collision, NAME_None);
	Mesh->SetCollisionProfileName("NoCollision");
	
	
}

// Called when the game starts or when spawned
void AShootProjectile::BeginPlay()
{
	Super::BeginPlay();

	if (GetOwner())
	{
		Collision->IgnoreActorWhenMoving(GetOwner(), true);
	}

	Collision->OnComponentBeginOverlap.AddDynamic(this, &AShootProjectile::OnProjectileOverlap);
}

void AShootProjectile::OnProjectileOverlap(UPrimitiveComponent* OpelappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 BodyIndex, bool Sweep, const FHitResult& Hit)
{
	//if (OtherActor || !Cast<APawn>(OtherActor)) return;
	if (!GetOwner()) return;
	APawn* PawnOwner = Cast<APawn>(GetOwner());
	if (!PawnOwner) return;
	AController* Instigat = PawnOwner->GetController();

	UGameplayStatics::ApplyDamage(OtherActor, Damage, Instigat, this, UDamageType::StaticClass());

	Destroy();
}



// Called every frame
void AShootProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalOffset(FVector(ProjectilesSpeed * DeltaTime, 0.f, 0.f));

}

