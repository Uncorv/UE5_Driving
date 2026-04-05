#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CarMovementComponent.generated.h"


UCLASS( ClassGroup=(Movement), meta=(BlueprintSpawnableComponent) )
class UE_DRIVING_API UCarMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCarMovementComponent();

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetThrottle(float Value);
	void DoThrottle(float DelatTime);
	void SetSteering(float Value);
	void DoSteering(float DeltaTime);

private:
	float ThrottleInput = 0.f;
	float SteeringInput = 0.f;
	float CurrentSpeed = 0.f;
	float MaxForwardSpeed = 1500.f;
	float MaxReverseSpeed = 500.f;
	float Acceleration = 3000.f;
	float Deceleration = 2000.f;
	float BrakeStrength = 5000.f;
};
