#include "Pawns/CarPawn.h"
#include "Components/CarMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

ACarPawn::ACarPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	CarBase = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CarBase"));
	SetRootComponent(CarBase);
	CarBase->SetCollisionProfileName(TEXT("Pawn"));
	CarBase->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CarBase->SetGenerateOverlapEvents(true);


	CarWheelFrontRight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FrontRightWheel"));
	CarWheelFrontRight->SetupAttachment(CarBase);

	CarWheelFrontLeft = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FrontLeftWheel"));
	CarWheelFrontLeft->SetupAttachment(CarBase);

	CarWheelBackRight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BackRightWheel"));
	CarWheelBackRight->SetupAttachment(CarBase);

	CarWheelBackLeft = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BackLeftWheel"));
	CarWheelBackLeft->SetupAttachment(CarBase);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(CarBase);
	SpringArm->TargetArmLength = 500.f;
	SpringArm->bUsePawnControlRotation = true;
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	CarMovementComponent = CreateDefaultSubobject<UCarMovementComponent>(TEXT("CarMovementComponent"));

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
	PlayerInputComponent->BindAxis("TurnRight", this, &ACarPawn::TurnRight);
	PlayerInputComponent->BindAxis("RotateCameraX", this, &ACarPawn::RotateCameraX);
	PlayerInputComponent->BindAxis("RotateCameraY", this, &ACarPawn::RotateCameraY);
}

void ACarPawn::MoveForward(float Value)
{
	CarMovementComponent->SetThrottle(Value);
}

void ACarPawn::TurnRight(float Value)
{
	CarMovementComponent->SetSteering(Value);
}

void ACarPawn::RotateCameraY(float Value)
{
	AddControllerPitchInput(Value);
}

void ACarPawn::RotateCameraX(float Value)
{
	AddControllerYawInput(Value);

}
