// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_QueueIntNode.h"

#include "CPP_QueueInt.generated.h"

UCLASS()
class TA_DATASTRUCTURES_API ACPP_QueueInt : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_QueueInt();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	int size = 0;
	UCPP_QueueIntNode* firstNode{};
	UCPP_QueueIntNode* lastNode{};

public:
	UFUNCTION(BlueprintCallable, Category = "Queue")
	bool Empty();
	UFUNCTION(BlueprintCallable, Category = "Queue")
	int Size();
	UFUNCTION(BlueprintCallable, Category = "Queue")
	UCPP_QueueIntNode* Front();
	UFUNCTION(BlueprintCallable, Category = "Queue")
	UCPP_QueueIntNode* Back();
	UFUNCTION(BlueprintCallable, Category = "Queue")
	void Enqueue(UCPP_QueueIntNode* node);
	UFUNCTION(BlueprintCallable, Category = "Queue")
	void Emplace(int value);
	UFUNCTION(BlueprintCallable, Category = "Queue")
	UCPP_QueueIntNode* Dequeue();

};
