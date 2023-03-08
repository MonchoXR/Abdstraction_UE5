// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "InteractableDoorMesh.generated.h"

class UDoorComponent;
UCLASS()
class WARSHIP_API AInteractableDoorMesh : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AInteractableDoorMesh();

protected:

	UPROPERTY(EditAnywhere,NoClear)
	UDoorComponent* DoorInteractionComponents;

};
