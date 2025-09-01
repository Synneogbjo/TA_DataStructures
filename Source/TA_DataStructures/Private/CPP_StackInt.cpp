// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_StackInt.h"

// Sets default values
ACPP_StackInt::ACPP_StackInt()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ACPP_StackInt::BeginPlay()
{
	Super::BeginPlay();
	
}

bool ACPP_StackInt::Empty()
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("Is Empty: %d"), (size <= 0)));

	return (size <= 0);
}

int ACPP_StackInt::Size()
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("Size: %d"), size));

	return size;
}

UCPP_StackIntNode* ACPP_StackInt::Top()
{
	if (!firstNode)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("No node could be found, as the Stack is empty!")));

		return nullptr;
	}

	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("First Node: value %d, previous %d"), firstNode->value, firstNode->previousNode));

	return firstNode;
}

void ACPP_StackInt::Push(UCPP_StackIntNode* node)
{
	node->previousNode = firstNode;
	firstNode = node;
	size++;

	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("Pushed Node: value %d, previous %d"), firstNode->value, firstNode->previousNode));
}

void ACPP_StackInt::Emplace(int value)
{
	UCPP_StackIntNode* node = NewObject<UCPP_StackIntNode>();
	node->value = value;
	node->previousNode = firstNode;

	firstNode = node;
	size++;

	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("Emplaced Node: value %d, previous %d"), firstNode->value, firstNode->previousNode));
}

UCPP_StackIntNode* ACPP_StackInt::Pop()
{
	if (!firstNode)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("Could not pop, since the Stack is empty!")));
		return nullptr;
	}

	UCPP_StackIntNode* poppedNode = firstNode;
	firstNode = poppedNode->previousNode;
	size--;

	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("Popped Node: value %d, previous %d"), poppedNode->value, poppedNode->previousNode));

	return poppedNode;
}
