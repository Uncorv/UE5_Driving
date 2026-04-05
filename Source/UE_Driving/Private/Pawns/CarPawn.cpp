#include "Pawns/CarPawn.h"

ACarPawn::ACarPawn()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACarPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACarPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACarPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

