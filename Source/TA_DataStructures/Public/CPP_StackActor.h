// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_StackActor.generated.h"

UCLASS()
class TA_DATASTRUCTURES_API ACPP_StackActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_StackActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};