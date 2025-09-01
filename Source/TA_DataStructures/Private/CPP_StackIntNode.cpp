// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_StackIntNode.h"

UCPP_StackIntNode::UCPP_StackIntNode()
{
	value = 0;
	previousNode = nullptr;
}

UCPP_StackIntNode::UCPP_StackIntNode(int setValue, UCPP_StackIntNode* setPreviousNode)
{
	value = setValue;
	previousNode = setPreviousNode;
}
