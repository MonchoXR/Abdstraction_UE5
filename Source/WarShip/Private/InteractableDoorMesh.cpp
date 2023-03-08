// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableDoorMesh.h"
#include "DoorComponent.h"

AInteractableDoorMesh::AInteractableDoorMesh()
{
	DoorInteractionComponents = CreateDefaultSubobject<UDoorComponent>(TEXT("DoorInteractionComponent"));
}

