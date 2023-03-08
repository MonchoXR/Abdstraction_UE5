// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorComponent.h"
#include "Engine/TriggerBox.h"

// Sets default values for this component's properties
UDoorComponent::UDoorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorComponent::BeginPlay()
{
	Super::BeginPlay();

	StartRotation = GetOwner()->GetActorRotation();
	FinalRotation = GetOwner()->GetActorRotation() + DesireRotation;
	CurrentRotationTime = 0.0f;
}
	


// Called every frame
void UDoorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (CurrentRotationTime < TimeToRotate)
	{
		if (TriggerBox && GetWorld() && GetWorld()->GetFirstPlayerController())
		{
			APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

			if (PlayerPawn && TriggerBox->IsOverlappingActor(PlayerPawn))
			{
				CurrentRotationTime += DeltaTime;
				/*const float RotationAlpha = FMath::Clamp(CurrentRotationTime / TimeToRotate, 0.0f, 1.0f);*/ //este clamp es para restringir entre valor de 0y 1
				const float TimeRatio = FMath::Clamp(CurrentRotationTime / TimeToRotate, 0.0f, 1.0f);
				const float RotationAlpha = OpenCurve.GetRichCurveConst()->Eval(TimeRatio);
				const FRotator CurrentRotation = FMath::Lerp(StartRotation, FinalRotation, RotationAlpha);//Esto va entre 0y 1
				GetOwner()->SetActorRotation(CurrentRotation);
			}
		}

	}

}

