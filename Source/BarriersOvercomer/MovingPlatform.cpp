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

	StartingLocationVector = GetActorLocation();

	// UE_LOG(LogTemp, Display, TEXT("Configured Moved Distance: %f"), MovedDistance);
	// FString PlatformName = this->GetActorNameOrLabel();
	// FString PlatformName = GetName();
	// UE_LOG(LogTemp, Display, TEXT("Platform name is: %s"), *PlatformName);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	if (ShouldPlatformReturn())
	{
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartingLocationVector = StartingLocationVector + MoveDirection * MovedDistance;
		SetActorLocation(StartingLocationVector);
		PlatformVelocity = -PlatformVelocity;
	}
	else
	{
		FVector CurrentLocationVector = GetActorLocation();
		CurrentLocationVector = CurrentLocationVector + PlatformVelocity * DeltaTime;
		SetActorLocation(CurrentLocationVector);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	UE_LOG(LogTemp, Display, TEXT("%s platform rotating.."), *GetName());
}

inline bool AMovingPlatform::ShouldPlatformReturn() const
{
	return GetDistanceMoved() > MovedDistance;
}

inline float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(GetActorLocation(), StartingLocationVector);
}
