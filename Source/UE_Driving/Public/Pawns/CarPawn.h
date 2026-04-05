#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CarPawn.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class UE_DRIVING_API ACarPawn : public APawn
{
	GENERATED_BODY()

public:
	ACarPawn();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent *SpringArm;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent *Camera;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent *CarBase;
};
