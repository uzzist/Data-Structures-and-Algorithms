#include<iostream>
#include<vector>
using namespace std;

class Queue
{
public:
	Queue()
	{
		size = 0;
		for (int index = 0; index < 10; index++)
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
	int Front()
	{
		if (size > 0)
		{
			return array[0];
		}
		else
		{
			return -1;
		}
	}
	void Dequeue()
	{
		if (size > 0)
		{
			array[0] = 0;
			int temp;
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
	void Enqueue(int value)
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
	int array[10];
	int size;
};

class Graph
{
public:
	Graph(int, int);
	void addEdge(int, int);
	void BFS(int);
private:
	int vertex, edge;
	int** adj;
};

Graph::Graph(int vertex, int edge)
{
	this->vertex = vertex;
	this->edge = edge;
	adj = new int* [vertex];
	for (int row = 0; row < vertex; row++)
	{
		adj[row] = new int[vertex];
		for (int column = 0; column < vertex; column++)
		{
			adj[row][column] = 0;
		}
	}
}
void Graph::addEdge(int start, int end)
{
	adj[start][end] = 1;
	adj[end][start] = 1;
}
void Graph::BFS(int start)
{
	Queue q;
	vector<bool>visited(vertex, false);
	q.Enqueue(start);
	visited[start] = true;
	int v;
	while (!q.isEmpty())
	{
		v = q.Front();
		cout << v << " ";
		q.Dequeue();
		for (int i = 0; i < vertex; i++)
		{
			if (adj[v][i] == 1 && !visited[i])
			{
				q.Enqueue(i);
				visited[i] = true;
			}
		}
	}
}
int main()
{
	int v = 5, e = 4;
	Graph G(v, e);
	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(1, 3);
	G.BFS(0);
	return 0;
}