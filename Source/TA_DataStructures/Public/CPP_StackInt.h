// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_StackIntNode.h"

#include "CPP_StackInt.generated.h"

UCLASS()
class TA_DATASTRUCTURES_API ACPP_StackInt : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_StackInt();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	int size = 0;
	UCPP_StackIntNode* firstNode{};

public:

	UFUNCTION(BlueprintCallable, Category = "Stack")
	bool Empty();
	UFUNCTION(BlueprintCallable, Category = "Stack")
	int Size();
	UFUNCTION(BlueprintCallable, Category = "Stack")
	UCPP_StackIntNode* Top();
	UFUNCTION(BlueprintCallable, Category = "Stack")
	void Push(UCPP_StackIntNode* node);
	UFUNCTION(BlueprintCallable, Category = "Stack")
	void Emplace(int value);
	UFUNCTION(BlueprintCallable, Category = "Stack")
	UCPP_StackIntNode* Pop();
};
