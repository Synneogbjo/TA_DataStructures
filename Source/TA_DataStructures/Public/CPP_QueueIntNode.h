// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CPP_QueueIntNode.generated.h"

/**
 * 
 */
UCLASS()
class TA_DATASTRUCTURES_API UCPP_QueueIntNode : public UObject
{
public:
	UCPP_QueueIntNode();
	UCPP_QueueIntNode(int setValue, UCPP_QueueIntNode* setNextNode = nullptr);

private:
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, Category = "Queue Node")
	int value;
	UPROPERTY(BlueprintReadWrite, Category = "Queue Node")
	UCPP_QueueIntNode* nextNode;
};
