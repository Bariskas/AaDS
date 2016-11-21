// lab3_19_graph_deikstra.cpp: определяет точку входа для консольного приложения.
//

/*
19. Имеется  сеть  автомобильных  дорог.  Для каждой дороги
известна максимальная масса груза, которую можно  провезти  по
этой   дороге.   С   помощью  алгоритма  Дейкстры   определить
максимальный   груз,   который  можно  провести  между   двумя
указанными городам (10).
*/

#include "stdafx.h"
#include "MaxWeightWithDeikstra.h"

using namespace std;

void ReadGraphFrom(istream& inputStream, Graph& graph);
void WriteGraph(Graph& graph);

int main()
{
	string filePath;
	cout << "File path:" << endl;
	cin >> filePath;
	ifstream fs(filePath);
	if (!fs.is_open())
	{
		cout << "Wrong file path" << endl;
		return 1;
	}

	Graph graph;
	ReadGraphFrom(fs, graph);

	int source;
	int destination;
	cout << "Enter source and destination: <source> <destination>" << endl;
	cin >> source >> destination;

	int maxWeght;
	try
	{
		maxWeght = FindMaxWeight(graph, source - 1, destination - 1);
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
		return 1;
	}

	cout << "maxWeight = " << maxWeght << endl;
	cout << "Press something to exit " << endl;
	getchar();

    return 0;
}

void ReadGraphFrom(istream& inputStream, Graph& graph)
{
	string buffer;
	while (getline(inputStream, buffer))
	{
		stringstream ss(buffer);
		int sourceIndex;
		int destinationIndex;
		int weight;
		ss >> sourceIndex >> destinationIndex >> weight;

		size_t maxIndex = max(sourceIndex, destinationIndex);
		--sourceIndex;
		--destinationIndex;
		if (graph.size() < maxIndex)
		{
			graph.resize(maxIndex);
			for (auto& line : graph)
			{
				line.resize(maxIndex, 0);
			}
		}
		graph[sourceIndex][destinationIndex] = graph[destinationIndex][sourceIndex] = weight;
	}
}

void WriteGraph(Graph& graph)
{
	for (size_t i = 0; i < graph.size(); ++i)
	{
		for (size_t j = 0; j < graph[i].size(); ++j)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}

