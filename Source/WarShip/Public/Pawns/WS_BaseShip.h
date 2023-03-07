// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "WS_BaseShip.generated.h"


class USpringArmComponent;
class UCameraComponent;
class UStaticMeshComponent;

UCLASS()
class WARSHIP_API AWS_BaseShip : public APawn
{
	GENERATED_BODY()

public:
	
	AWS_BaseShip();
		
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:

	virtual void BeginPlay() override;


	void MoveForward(float Value);
	void Turn(float Value);
	void LookUp(float Value);

private:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseShipMesh;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;

};
