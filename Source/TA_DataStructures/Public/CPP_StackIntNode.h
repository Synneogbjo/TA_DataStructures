// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "CPP_StackIntNode.generated.h"

/**
 * 
 */

UCLASS()
class TA_DATASTRUCTURES_API UCPP_StackIntNode : public UObject
{
public:
	UCPP_StackIntNode();
	UCPP_StackIntNode(int setValue, UCPP_StackIntNode* setPreviousNode = nullptr);

private:
	GENERATED_BODY()

public:
	int value;
	UCPP_StackIntNode* previousNode;

};
