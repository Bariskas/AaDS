#pragma once

#include "stdafx.h"

struct DeikstraData
{
	std::vector<int> weights;
	std::vector<bool> visitedPoints;
};

int FindMaxWeight(Graph& graph, int source, int destination);
void InitData(DeikstraData& data, Graph& graph, int source);