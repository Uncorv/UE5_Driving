#include "Pawns/CarPawn.h"
#include "Components/CarMovementComponent.h"
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

	CarMovementComponent = CreateDefaultSubobject<UCarMovementComponent>(TEXT("CarMovementComponent"));

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void ACarPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACarPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACarPawn::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ACarPawn::MoveForward);

}

void ACarPawn::MoveForward(float Value)
{
	CarMovementComponent->SetThrottle(Value);
}

void ACarPawn::TurnRight(float Value)
{
	CarMovementComponent->SetSteering(Value);
}
