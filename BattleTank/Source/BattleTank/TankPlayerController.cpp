// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() 
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if(!ControlledTank)
	{ 
		UE_LOG(LogTemp, Warning, TEXT("No Pawn for player to control")); 
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Pawn is: %s"), *(ControlledTank->GetName()));
	}
}


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();

}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::AimTowardsCrosshair()
{

	if (!GetControlledTank()) { return; } //TODO make this more efficient

	FVector HitLocation; // out parameter

	if (GetSightRayHitLocation(HitLocation)) //Has "side-effect", is going to linetrace
	{

		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());

		//TODO turn towrds hit point

	}

}

//get world location of linetrace through crosshair, true if it hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{

	OutHitLocation = FVector(1.0);

	return true;

}