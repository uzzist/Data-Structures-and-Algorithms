#include<iostream>
using namespace std;
#pragma once
template<class T>
class Queue
{
public:
	Queue()
	{
		size = 0;
		for (int index = 0; index < 100; index++)
		{
			array[index] = 0;
		}
	}
	int Size()
	{
		return size;
	}
	bool isEmpty()
	{
		if (size > 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	T Front()
	{
		if (size > 0)
		{
			return array[0];
		}
		else
		{
			return 0;
		}
	}
	void Dequeue()
	{
		if (size > 0)
		{
			array[0] = 0;
			T temp;
			for (int index = 0; index < 9; index++)
			{
				temp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = temp;
			}
			size--;
		}
		else
		{
			cout << "Queue is empty!\n";
		}
	}
	void Enqueue(T value)
	{
		if (size < 10)
		{
			array[size] = value;
			size++;
		}
		else
		{
			cout << "Error! Queue is full!\n";
		}
	}
	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << array[i] << endl;
		}
	}
private:
	T array[100];
	int size;
};

#pragma once
class Graph
{
public:
	Graph();
	Graph(int);
	void addEdge(int, int, int);
	void deleteEdge(int, int);
	void print();
	bool hasCycle(bool*, int, int);
	bool visited(bool*);
	int Prim(int);
	int firstnode(int);
	int nextnode(int, int);
	~Graph();
private:
	int** adjmatrix;
	int vertices;
};

Graph::Graph()
{
	adjmatrix = nullptr;
	vertices = 0;
}
Graph::Graph(int vertex)
{
	this->vertices = vertex;
	adjmatrix = new int* [vertices];
	for (int c = 0; c < vertices; c++)
	{
		adjmatrix[c] = new int[vertices];
	}
	for (int rows = 0; rows < vertices; rows++)
	{
		for (int cols = 0; cols < vertices; cols++)
		{
			adjmatrix[rows][cols] = 0;
		}
	}
}
void Graph::addEdge(int source, int destination, int weight)
{
	adjmatrix[source][destination] = weight;
	adjmatrix[destination][source] = weight;
}
void Graph::deleteEdge(int source, int destination)
{
	adjmatrix[source][destination] = 0;
	adjmatrix[destination][source] = 0;
}
Graph::~Graph()
{
	for (int i = 0; i < vertices; i++)
	{
		delete[]adjmatrix[i];
	}
	delete[] adjmatrix;
}
void Graph::print()
{
	cout << "  ";
	for (int v = 0; v < vertices; v++)
	{
		cout << v << " ";
	}

	for (int rows = 0; rows < vertices; rows++)
	{
		cout << endl << rows << " ";
		for (int cols = 0; cols < vertices; cols++)
		{
			cout << adjmatrix[rows][cols] << " ";
		}
	}
}
bool Graph::hasCycle(bool* mark, int current, int next)
{
	if (mark[current] && mark[next])
	{
		return true;
	}
	return false;
}

bool Graph::visited(bool* mark)
{
	for (int i = 0; i < vertices; i++)
	{
		if (!mark[i])
		{
			return false;
		}
	}
	return true;
}
int Graph::Prim(int startingNode)
{
	cout << "Path	   Cost" << endl;
	bool* mark = new bool[vertices];
	for (int i = 0; i < vertices; i++)
	{
		mark[i] = false;
	}
	Queue<int> queue;
	int cost = 0;
	mark[startingNode] = true;
	queue.Enqueue(startingNode);
	while (!visited(mark))
	{
		int max_cost = INT_MAX;
		int v;
		int start;

		while (!queue.isEmpty())
		{
			startingNode = queue.Front();
			queue.Dequeue();
			int currentVertex = firstnode(startingNode);
			while (currentVertex != -1)
			{
				if (max_cost > adjmatrix[startingNode][currentVertex] && !hasCycle(mark, startingNode, currentVertex))
				{
					max_cost = adjmatrix[startingNode][currentVertex];
					v = currentVertex;
					start = startingNode;
				}
				currentVertex = nextnode(startingNode, currentVertex);
			}
		}
		if (max_cost != INT_MAX)
		{
			cost = cost + max_cost;
			mark[v] = true;
			cout << start << "->" << v << "	    " << max_cost << endl;
		}

		for (int i = 0; i < vertices; i++)
		{
			if (mark[i])
			{
				queue.Enqueue(i);
			}
		}
	}
	return cost;
}
int Graph::firstnode(int vertex)
{
	for (int i = 0; i < this->vertices; i++)
	{
		if (adjmatrix[vertex][i] != 0)
		{
			return i;
		}
	}
	return -1;
}
int Graph::nextnode(int vertex1, int vertex2)
{
	for (int i = vertex2 + 1; i < this->vertices; i++)
	{
		if (adjmatrix[vertex1][i] != 0)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	Graph obj(4);
	obj.addEdge(0, 1, 1);
	obj.addEdge(0, 2, 4);
	obj.addEdge(0, 3, 3);
	obj.addEdge(1, 0, 1);
	obj.addEdge(1, 3, 2);
	obj.addEdge(2, 0, 3);
	obj.addEdge(2, 3, 5);
	obj.addEdge(3, 0, 3);
	obj.addEdge(3, 1, 2);
	obj.addEdge(3, 2, 5);
	obj.print();
	cout << endl;
	int startingNode;
	cout << "Enter starting node: ";
	cin >> startingNode;
	cout << "Total Cost: " << obj.Prim(startingNode);
}