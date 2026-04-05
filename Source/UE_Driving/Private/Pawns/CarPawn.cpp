#include "Pawns/CarPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

ACarPawn::ACarPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	CarBase = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CarBase"));
	SetRootComponent(CarBase);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(CarBase);
	SpringArm->TargetArmLength = 500.f;
	SpringArm->SocketOffset = FVector(0.f, 0.f, 85.f);
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

void ACarPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACarPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
