#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CarPawn.generated.h"

class UCarMovementComponent;
class UCameraComponent;
class UInputComponent;
class USpringArmComponent;

UCLASS()
class UE_DRIVING_API ACarPawn : public APawn
{
	GENERATED_BODY()

public:
	ACarPawn();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent *PlayerInputComponent) override;

	void MoveForward(float Value);
	void TurnRight(float Value);
	void RotateCameraX(float Value);
	void RotateCameraY(float Value);

private:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent *SpringArm;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent *Camera;
	UPROPERTY(VisibleAnywhere)
	UCarMovementComponent *CarMovementComponent;

	UPROPERTY(VisibleAnywhere, Category = "CarMesh")
	UStaticMeshComponent *CarBase;
	UPROPERTY(VisibleAnywhere, Category = "CarMesh")
	UStaticMeshComponent *CarWheelFrontLeft;
	UPROPERTY(VisibleAnywhere, Category = "CarMesh")
	UStaticMeshComponent *CarWheelFrontRight;
	UPROPERTY(VisibleAnywhere, Category = "CarMesh")
	UStaticMeshComponent *CarWheelBackLeft;
	UPROPERTY(VisibleAnywhere, Category = "CarMesh")
	UStaticMeshComponent *CarWheelBackRight;
	
};
