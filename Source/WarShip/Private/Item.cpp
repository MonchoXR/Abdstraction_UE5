// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

#include "WarShip/DebugMacros.h" //Tengo definido Macros

AItem::AItem()
{

	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;
}


void AItem::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("BEGING PLAY CALLED"));

	FVector AvgVector = Avg<FVector>(GetActorLocation(), FVector::ZeroVector);
	DRAW_POINT_SingleFrame(AvgVector);

}

float AItem::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}


void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;
	//UE_LOG(LogTemp, Warning, TEXT("DeltaTime: %f"), RunningTime);
	/*UE_LOG(LogTemp, Warning, TEXT("DeltaTime: %f"), DeltaTime);*/
	//if (GEngine)
	//{
	//	FString Name = GetName();
	//	FString Message = FString::Printf(TEXT("Item Name: %s"), *Name);
	//	GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, Message);

	//	UE_LOG(LogTemp, Warning, TEXT("Item Name: %s"), *Name);
	//}



	DRAW_SPHERE_SingleFrame(GetActorLocation())
	DRAW_VECTOR_SingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);
}

