// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


// Classe que representa um nó dentro da grade de Pathfinding
class IGDEVTEST_API PathfindingNode
{
public:
    // Construtor que inicializa o nó com sua posição na grade (X, Y, Z)
    PathfindingNode(int GridXPos, int GridYPos, int GridZPos);

    // Destrutor
    ~PathfindingNode();

    // Ponteiro para o nó pai (usado para traçar o caminho)
    PathfindingNode* ParentNode;

    // Posições do nó na grade
    int GridX, GridY, GridZ;

    // Custo G: Custo acumulado desde o ponto inicial até este nó
    int GCost = 0;

    // Custo H: Heurística estimada do nó até o destino
    int HCost = 0;

    // Função para calcular o custo total (FCost = GCost + HCost)
    float FCost();
};
