// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(StartingLocationVector);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocationVector = GetActorLocation();

	static bool forwardDirection = true;
	if (CurrentLocationVector.Y == (StartingLocationVector.Y + 1000))
		forwardDirection = false;
	if (CurrentLocationVector.Y == (StartingLocationVector.Y - 1000))
		forwardDirection = true;

	if (forwardDirection)
		CurrentLocationVector.Y++;
	else
		CurrentLocationVector.Y--;

	SetActorLocation(CurrentLocationVector);
}
