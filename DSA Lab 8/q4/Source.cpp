#include<iostream>
#include<list>
#include<vector>
using namespace std;

#pragma once
template<class T>
class Stack
{
public:
	Stack()
	{

	}
	void Push(T value)
	{
		stack.push_back(value);
	}
	T Pop()
	{
		if (stack.size() > 0)
		{
			T value = stack[stack.size() - 1];
			stack.pop_back();
			return value;
		}
		else
		{
			cout << "Error! Stack is empty\n";
			return -1;
		}
	}
	T Top()
	{
		if (stack.size() > 0)
		{
			T top = stack.size() - 1;
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
	vector<T>stack;
};

class Graph
{
    int V;
    list<int>* adj; 
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
void Graph::DFS(int s)
{
    vector<bool> visited(V, false); 
    Stack<int> stack;
    stack.Push(s);
    while (!stack.isEmpty())
    {
        s = stack.Top();
        stack.Pop();
        if (!visited[s])
        {
            cout << s << " ";
            visited[s] = true;
        }
		for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				stack.Push(*i);
			}
		}
    }
}

int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);

    cout << "Following is Depth First Traversal\n";
    g.DFS(0);

    return 0;
}