// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class BARRIERSOVERCOMER_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	int32 MyInt = 99;

	UPROPERTY(EditAnywhere)
	int32 InputA{};

	UPROPERTY(EditAnywhere)
	int32 InputB{3};

	UPROPERTY(EditAnywhere)
	int32 APlusB{};

	UPROPERTY(EditAnywhere)
	float MyFloat = 0.0001;

	UPROPERTY(EditAnywhere)
	float InputFloatA = 0.03;

	UPROPERTY(EditAnywhere)
	float InputFloatB = 0.5;

	UPROPERTY(EditAnywhere)
	float FloatAPlusFloatB{};

	float summFloats(float, float);

	UPROPERTY(EditAnywhere)
	bool MyBool = true;
};
