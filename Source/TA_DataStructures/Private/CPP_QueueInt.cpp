// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_QueueInt.h"

// Sets default values
ACPP_QueueInt::ACPP_QueueInt()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ACPP_QueueInt::BeginPlay()
{
	Super::BeginPlay();
	
}

bool ACPP_QueueInt::Empty()
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("Is Empty: %d"), (size <= 0)));

	return (size <= 0);
}

int ACPP_QueueInt::Size()
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("Size: %d"), size));

	return size;
}

UCPP_QueueIntNode* ACPP_QueueInt::Front()
{
	if (size <= 0)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("Cannot get front from Queue, its empty!")));

		return nullptr;
	}

	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("Front node: value %d, nextNode %d"), firstNode->value, firstNode->nextNode));

	return firstNode;
}

UCPP_QueueIntNode* ACPP_QueueInt::Back()
{
	if (size <= 0)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("Cannot get back from Queue, its empty!")));

		return nullptr;
	}

	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("Back node: value %d, nextNode %d"), lastNode->value, lastNode->nextNode));

	return lastNode;
}

void ACPP_QueueInt::Enqueue(UCPP_QueueIntNode* node)
{
	if (!firstNode) firstNode = node;

	if (lastNode)
	{
		lastNode->nextNode = node;
	}

	lastNode = node;

	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("Enqueued node: value %d, nextNode %d"), node->value, node->nextNode));
}

void ACPP_QueueInt::Emplace(int value)
{
	UCPP_QueueIntNode* node = NewObject<UCPP_QueueIntNode>();
	node->value = value;

	if (!firstNode) firstNode = node;

	if (lastNode)
	{
		lastNode->nextNode = node;
	}

	lastNode = node;

	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("Emplaced node: value %d, nextNode %d"), node->value, node->nextNode));

}

UCPP_QueueIntNode* ACPP_QueueInt::Dequeue()
{
	if (Empty())
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("Could not dequeue from queue, its empty!")));

		return nullptr;
	}

	auto node = firstNode;
	firstNode = (node) ? node->nextNode : nullptr;
	size--;

	if (Empty()) lastNode = nullptr;

	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, FString::Printf(TEXT("Dequeued node: value %d, nextNode %d"), node->value, node->nextNode));

	return node;
}

