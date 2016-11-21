#include "stdafx.h"
#include "MaxWeightWithDeikstra.h"

using namespace std;

int FindMaxWeight(Graph & graph, int source, int destination)
{
	int graphSize = graph.size();
	DeikstraData data;
	InitData(data, graph, source);
	while (any_of(data.visitedPoints.begin(), data.visitedPoints.end(),
		[](bool el) { return !el; }
	))
	{
		int minIndex = INT_MAX;
		int minElWeight = INT_MAX;
		for (int i = 0; i < graphSize; ++i)
		{
			if (data.weights[i] < minElWeight && !data.visitedPoints[i])
			{
				minElWeight = data.weights[i];
				minIndex = i;
			}
		}

		for (int i = 0; i < graphSize; ++i)
		{
			if (graph[minIndex][i] != 0
				&& (graph[minIndex][i] + minElWeight) < data.weights[i]
				&& !data.visitedPoints[i])
			{
				data.weights[i] = graph[minIndex][i] + minElWeight;
			}
		}

		data.visitedPoints[minIndex] = true;
	}

	return data.weights[destination];
}

void InitData(DeikstraData& data, Graph& graph, int source)
{
	int pointsCount = graph.size();
	data.weights = vector<int>(pointsCount, INT_MAX);
	data.weights[source] = 0;
	data.visitedPoints = vector<bool>(pointsCount, false);
}