// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:

	virtual void BeginPlay() override;

	ATank* GetControlledTank() const;
	
	//Start the tank moving the barrel so that a shot will hit where a crosshair intersects the world
	void ATankPlayerController::AimTowardsCrosshair();

	//return an out parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

public:

	virtual void Tick(float DeltaTime) override;



};