#pragma once

#include "stdafx.h"

struct DeikstraData
{
	std::vector<int> weights;
	std::vector<bool> visitedPoints;
	std::vector<int> path;
};

int FindMaxWeight(Graph& graph, int source, int destination);
void InitData(DeikstraData& data, Graph& graph, int source);
void PrintPath(const std::vector<int>& path, int source, int destination);