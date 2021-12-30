#pragma once
#include<vector>
#include<iostream>
using namespace std;

class Stack
{
public:
	Stack()
	{

	}
	void push(int value)
	{
		stack.push_back(value);
	}
	int pop()
	{
		if (stack.size() > 0)
		{
			int value = stack[stack.size() - 1];
			stack.pop_back();
			return value;
		}
		else
		{
			cout << "Error! Stack is empty\n";
			return -1;
		}
	}
	int top()
	{
		if (stack.size() > 0)
		{
			int top = stack.size() - 1;
			return stack[top];
		}
		else
		{
			cout << "Error! Stack is empty\n";
			return -1;
		}
	}
	bool isEmpty()
	{
		if (stack.size() > 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	~Stack()
	{

	}
	void Print()
	{
		int length = stack.size();
		for (int i = 0; i < length; i++)
		{
			cout << stack[i] << endl;
		}
	}
private:
	vector<int>stack;
};

class Graph
{
private:
	int n;
	int** adj;
public:
	Graph(int size);
	~Graph();
	void addEdge(int x, int y);
	bool isConnected(int x, int y);
	void DFS(int start, int end);
};

Graph::Graph(int size)
{
	if (size < 2)
	{
		n = 2;
	}
	else
	{
		n = size;
	}

	adj = new int* [n];

	for (int i = 0; i < n; ++i)
	{
		adj[i] = new int[n];
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			adj[i][j] = 0;
		}
	}
}

Graph::~Graph()
{
	for (int i = 0; i < n; ++i)
	{
		delete[] adj[i];
	}
	delete[] adj;
}

void Graph::addEdge(int x, int y)
{
	adj[x - 1][y - 1] = adj[y - 1][x - 1] = 1;
}

bool Graph::isConnected(int x, int y)
{
	return (adj[x - 1][y - 1] == 1);
}

void Graph::DFS(int start, int end)
{
	Stack s;
	bool* visited = new bool[n + 1];

	for (int i = 0; i <= n; ++i)
	{
		visited[i] = false;
	}

	s.push(start);
	visited[start] = true;

	if (start == end)
	{
		return;
	}

	cout << "Depth-first search starting from point: " << start << endl;

	while (!s.isEmpty())
	{
		int k = s.top();
		s.pop();

		if (k == end)
		{
			break;
		}

		cout << k << " ";

		for (int i = n; i >= 0; --i)
		{
			if (isConnected(k, i) && !visited[i])
			{
				s.push(i);
				visited[i] = true;
			}
		}
	}
	cout << end << endl;
	delete[] visited;
}

int main()
{
	Graph g(8);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(2, 6);
	g.addEdge(3, 7);
	g.addEdge(7, 8);
	g.DFS(1, 7);
	return 0;
}