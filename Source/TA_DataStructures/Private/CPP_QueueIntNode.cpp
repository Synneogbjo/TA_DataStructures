// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_QueueIntNode.h"

UCPP_QueueIntNode::UCPP_QueueIntNode()
{
	value = 0;
	nextNode = nullptr;
}

UCPP_QueueIntNode::UCPP_QueueIntNode(int setValue, UCPP_QueueIntNode* setNextNode)
{
	value = setValue;
	nextNode = setNextNode;
}
