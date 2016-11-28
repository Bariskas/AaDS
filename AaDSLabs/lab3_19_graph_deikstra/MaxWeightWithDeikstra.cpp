#include "stdafx.h"
#include "MaxWeightWithDeikstra.h"

using namespace std;

#define NONINITIALIZED_UNVIZITED_MAX_ELEMENT_VALUE (-1)

int FindMaxWeight(Graph & graph, int source, int destination)
{
	int graphSize = graph.size();
	DeikstraData data;
	InitData(data, graph, source);
	while (any_of(data.visitedPoints.begin(), data.visitedPoints.end(),
		[](bool el) { return !el; }
	))
	{
		int maxIndex = INT_MAX;
		int maxElWeight = NONINITIALIZED_UNVIZITED_MAX_ELEMENT_VALUE;
		for (int i = 0; i < graphSize; ++i)
		{
			if (data.weights[i] > maxElWeight && !data.visitedPoints[i])
			{
				maxElWeight = data.weights[i];
				maxIndex = i;
			}
		}
		if (maxElWeight == NONINITIALIZED_UNVIZITED_MAX_ELEMENT_VALUE)
		{
			break;
		}

		for (int i = 0; i < graphSize; ++i)
		{
			bool doesWayExist = graph[maxIndex][i] != 0;
			bool doesWayBiggerThenValue = (graph[maxIndex][i] > data.weights[i]) && (maxElWeight > data.weights[i]);
			if (doesWayExist && doesWayBiggerThenValue
				&& !data.visitedPoints[i])
			{
				data.weights[i] = min(maxElWeight, graph[maxIndex][i]);
			}
		}

		data.visitedPoints[maxIndex] = true;
	}

	if (data.weights[destination] == NONINITIALIZED_UNVIZITED_MAX_ELEMENT_VALUE)
	{
		throw runtime_error("There are no way from " + to_string(source + 1) + " to " + to_string(destination + 1));
	}

	return data.weights[destination];
}

void InitData(DeikstraData& data, Graph& graph, int source)
{
	int pointsCount = graph.size();
	data.weights = vector<int>(pointsCount, NONINITIALIZED_UNVIZITED_MAX_ELEMENT_VALUE);
	data.weights[source] = INT_MAX;
	data.visitedPoints = vector<bool>(pointsCount, false);
}