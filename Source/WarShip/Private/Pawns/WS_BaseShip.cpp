// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/WS_BaseShip.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

AWS_BaseShip::AWS_BaseShip()
{
 	
	PrimaryActorTick.bCanEverTick = true;



	BaseShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseShipMesh"));
	SetRootComponent(BaseShipMesh);
	

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 300.f;

	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(CameraBoom);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}


void AWS_BaseShip::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWS_BaseShip::MoveForward(float Value)
{
	UE_LOG(LogTemp, Warning, TEXT("Value: %f"), Value);

	if (Controller && (Value != 0.f))
	{
		FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, Value);
	}
}

void AWS_BaseShip::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void AWS_BaseShip::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}


void AWS_BaseShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AWS_BaseShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &AWS_BaseShip::MoveForward);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &AWS_BaseShip::Turn);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &AWS_BaseShip::LookUp);
}

