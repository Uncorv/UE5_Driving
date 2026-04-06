#include "Components/CarMovementComponent.h"

UCarMovementComponent::UCarMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UCarMovementComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UCarMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	DoThrottle(DeltaTime);
	DoSteering(DeltaTime);
}

void UCarMovementComponent::SetThrottle(float Value)
{
	ThrottleInput = FMath::Clamp(Value, -1.f, 1.f);
}

void UCarMovementComponent::DoThrottle(float DeltaTime)
{
	if (ThrottleInput > 0)
	{
		if (CurrentSpeed >= 0)
		{
			CurrentSpeed += ThrottleInput * Acceleration * DeltaTime;
		}
		else
		{
			CurrentSpeed += BrakeStrength * DeltaTime;
		}
	}
	else if (ThrottleInput < 0)
	{
		if (CurrentSpeed <= 0)
		{
			CurrentSpeed += ThrottleInput * Acceleration * DeltaTime;
		}
		else
		{
			CurrentSpeed -= BrakeStrength * DeltaTime;
		}
	}
	else
	{
		if (CurrentSpeed > 0.f)
		{
			CurrentSpeed = FMath::Max(0.f, CurrentSpeed - Deceleration * DeltaTime);
		}
		else if (CurrentSpeed < 0.f)
		{
			CurrentSpeed = FMath::Min(0.f, CurrentSpeed + Deceleration * DeltaTime);
		}
	}

	CurrentSpeed = FMath::Clamp(CurrentSpeed, -MaxReverseSpeed, MaxForwardSpeed);

	FVector Direction = GetOwner()->GetActorForwardVector();
	FVector Delta = Direction * CurrentSpeed * DeltaTime;
	GetOwner()->AddActorWorldOffset(Delta, true);
}

void UCarMovementComponent::SetSteering(float Value)
{
	SteeringInput = Value;
}

void UCarMovementComponent::DoSteering(float DeltaTime)
{
	if (CurrentSpeed != 0)
	{
		FRotator DeltaRotation(0.f, SteeringInput * SteeringSpeed * DeltaTime, 0.f);
		GetOwner()->AddActorWorldRotation(DeltaRotation);
	}
}