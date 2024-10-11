// Fill out your copyright notice in the Description page of Project Settings.


#include "PathfindingNode.h"


PathfindingNode::PathfindingNode(int GridXPos, int GridYPos, int GridZPos)
{
    GridX = GridXPos;
    GridY = GridYPos;
    GridZ = GridZPos;
}

// Destrutor da classe PathfindingNode
PathfindingNode::~PathfindingNode()
{
}

// Função que calcula e retorna o custo total (FCost) como a soma de GCost e HCost
float PathfindingNode::FCost()
{
    return HCost + GCost;
}
