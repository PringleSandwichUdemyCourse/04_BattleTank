// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Pawn for AI to Control"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Pawn is: %s"), *(ControlledTank->GetName()));
	}



	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI cannot get player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank Targeted"));
	}
}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		// TODO Move Towards the Player

		// Aim Towards the Player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());


		// TODO Fire if ready

	}
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}
