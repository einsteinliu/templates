#pragma once
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

template<typename T>
class Vertex
{
public:
	Vertex<T>()
	{

	}
	~Vertex<T>()
	{

	}
	int index;
	T value;
	string name;
};


class Graph
{
public:
	Graph();
	~Graph();
	void init(string filename = "");
	vector< int > getConnectedVertices(int v);
	void printAllVertices();
private:
	void resetVisitedMap();
	void reflectAdjMat();
	int count;
	Vertex<string>* vertices;
	map<int,bool> visited;
	int** adjMat;
};

