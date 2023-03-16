// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Curves/CurveFloat.h"
#include "DoorComponent.generated.h"

class ATriggerBox;

UENUM()
enum class EDoorState
{
	DS_Closed = 0  UMETA(DisplayName = "Closed"),
	DS_Open = 1    UMETA(DisplayName = "Open"),
	DS_Locked = 2  UMETA(DisplayName = "Locked"),

};
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WARSHIP_API UDoorComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FRotator DesireRotation;

	FRotator DeltaRotation;
	FRotator StartRotation = FRotator::ZeroRotator;
	FRotator FinalRotation = FRotator::ZeroRotator;
	float CurrentRotationTime;

	UPROPERTY(EditAnywhere)
	float TimeToRotate = 1.0f;

	UPROPERTY(EditAnywhere)
	ATriggerBox* TriggerBox;

	UPROPERTY(EditAnywhere)
	FRuntimeFloatCurve OpenCurve;

	UPROPERTY(BlueprintReadOnly)
	EDoorState DoorState;

public:	
	// Sets default values for this component's properties
	UDoorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
