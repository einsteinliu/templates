#include "Graph.h"

Graph::Graph()
{
	count = 0;
}


Graph::~Graph()
{
}

void Graph::init(string filename)
{
	if (filename == "")
	{
		count = 6;
		adjMat = new int*[count];
		for (int i = 0; i < count; i++)
		{
			adjMat[i] = new int[count];
			for (int j = 0; j < count; j++)
				adjMat[i][j] = 0;
		}

		//init edges
		adjMat[0][5] = 1;
		adjMat[1][3] = 1;
		adjMat[2][3] = 1;
		adjMat[3][4] = 1;
		adjMat[2][5] = 1;
		adjMat[1][5] = 1;
		//only for non-directional adj mat
		reflectAdjMat();

		//init vertices
		vertices = new Vertex<string>[count];
		for (int i = 0; i < count; i++)
		{
			vertices[i].value = std::to_string(i);
		}
		resetVisitedMap();
	}
}

vector<int> Graph::getConnectedVertices(int v)
{
	vector<int> connectedVetices;
	for (int i = 0; i < count; i++)
	{
		if (i != v)
		{
			if (adjMat[v][i] != 0)
				connectedVetices.push_back(i);
		}
	}
	return connectedVetices;
}

void Graph::printAllVertices()
{
	vector<int> toBeVisited;
	toBeVisited.push_back(1);
	do
	{
		//visit the vertex with the index of currVisitIndex
		int currVisitIndex = toBeVisited.back();
		toBeVisited.pop_back();

		if (!visited[currVisitIndex])
		{
			std::cout << vertices[currVisitIndex].value << endl;
			visited[currVisitIndex] = true;

			//get the current visited vertex's neighours
			vector<int> connectedVertices = getConnectedVertices(currVisitIndex);
			toBeVisited.insert(toBeVisited.end(),
				connectedVertices.begin(),
				connectedVertices.end());
		}

	} while (!toBeVisited.empty());
}

void Graph::resetVisitedMap()
{
	for (int i = 0; i < count; i++)
		visited[i] = false;
}

void Graph::reflectAdjMat()
{
	for (int i = 1; i < count; i++)
	{
		for (int j = 0; j < i; j++)
		{
			adjMat[i][j] = adjMat[j][i];
		}
	}
}
