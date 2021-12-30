#include <iostream>
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
class Node
{
public:
	Node* next;
	Node* previous;
	int vertex;
	int weight;
};

#pragma once
class LinkedList
{
public:
	LinkedList();
	void insertAtStart(int, int);
	void insertAtEnd(int, int);
	void deleteAtStart();
	void deleteAtEnd();
	void deleteAt(int value);
	void print();
	int getWeight(int index);
	int firstNode();
	int nextNode(int);
	~LinkedList();
private:
	Node* head;
};

LinkedList::LinkedList()
{
	head = nullptr;
}

void LinkedList::insertAtStart(int vertex, int weight)
{
	if (head == nullptr)
	{
		head = new Node;
		head->weight = weight;
		head->vertex = vertex;
		head->next = nullptr;
		head->previous = nullptr;
	}
	else
	{
		Node* temp = new Node;
		temp->weight = weight;
		temp->vertex = vertex;
		temp->next = head;
		temp->previous = nullptr;
		head->previous = temp;
		head = temp;
	}
}

void LinkedList::insertAtEnd(const int vertex, const int weight)
{
	if (head == nullptr)
	{
		head = new Node;
		head->vertex = vertex;
		head->weight = weight;
		head->next = nullptr;
		head->previous = nullptr;
	}
	else
	{
		Node* current = head;
		Node* temp = new Node;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		temp->weight = weight;
		temp->vertex = vertex;
		temp->next = nullptr;
		temp->previous = current;
		current->next = temp;
	}
}
void LinkedList::deleteAtStart()
{
	if (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		if (head != nullptr)
		{
			head->previous = nullptr;
		}
		delete temp;
	}
}
void LinkedList::deleteAtEnd()
{
	Node* current = head;
	while (current->next != nullptr)
	{
		current = current->next;
	}
	Node* temp = current->previous;
	delete current;
	temp->next = nullptr;
}

void LinkedList::deleteAt(int vertex)
{
	Node* current = head;
	while (current->vertex == vertex)
	{
		current = current->next;
	}
	if (current == head)
	{
		deleteAtStart();
	}
	else if (current->next == nullptr)
	{
		deleteAtEnd();
	}
	else
	{
		current->previous->next = current->next;
		current->next->previous = current->previous;
		delete current;
	}
}
void LinkedList::print()
{
	Node* current = head;
	while (current != nullptr)
	{
		cout << " -> (" << current->vertex << ", " << current->weight << ")";
		current = current->next;
	}
	cout << endl;
}
int LinkedList::getWeight(int vertex)
{
	Node* current = head;
	while (current != nullptr)
	{
		if (vertex == current->vertex)
		{
			return current->weight;
		}
		current = current->next;
	}
	return 0;
}
int LinkedList::firstNode()
{
	if (head != nullptr)
	{
		return head->vertex;
	}
	return -1;
}
int LinkedList::nextNode(int vertex)
{
	Node* current = head;
	bool check = true;
	while (current)
	{
		if (current->vertex == vertex && current->next)
		{
			return current->next->vertex;
		}
		current = current->next;
	}
	return -1;
}
LinkedList::~LinkedList()
{
	while (head)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

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
	int getweight(int, int);
	int firstnode(int);
	int nextnode(int, int);
	~Graph();
private:
	LinkedList* adjList;
	int vertices;
};
Graph::Graph()
{
	adjList = nullptr;
	vertices = 0;
}
Graph::Graph(int vertices)
{
	this->vertices = vertices;
	adjList = new LinkedList[this->vertices];
}
int Graph::firstnode(int vertex)
{
	return adjList[vertex].firstNode();
}
int Graph::nextnode(int vertex1, int vertex2)
{
	return adjList[vertex1].nextNode(vertex2);
}
void Graph::addEdge(int source, int destination, int weight)
{
	adjList[source].insertAtEnd(destination, weight);
}
void Graph::deleteEdge(int v1, int v2)
{
	adjList[v1].deleteAt(v2);
}
void Graph::print()
{
	for (int i = 0; i < this->vertices; i++)
	{
		cout << i;
		adjList[i].print();
		cout << endl;
	}
	cout << endl;
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
			int current_Vertex = firstnode(startingNode);
			while (current_Vertex != -1)
			{
				int w = getweight(startingNode, current_Vertex);
				if (max_cost > w && !hasCycle(mark, startingNode, current_Vertex))
				{
					max_cost = w;
					v = current_Vertex;
					start = startingNode;
				}
				current_Vertex = nextnode(startingNode, current_Vertex);
			}
		}
		if (max_cost != INT_MAX)
		{
			cost = cost + max_cost;
			mark[v] = true;
			cout << start << "->" << v << "	    " << max_cost << endl;
		}

		for (int i = 0; i < this->vertices; i++)
		{
			if (mark[i])
			{
				queue.Enqueue(i);
			}
		}
	}
	return cost;
}
int Graph::getweight(int vertex1, int vertex2)
{
	return adjList[vertex1].getWeight(vertex2);
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
	for (int i = 0; i < this->vertices; i++)
	{
		if (!mark[i])
		{
			return false;
		}
	}
	return true;
}
Graph::~Graph()
{
	delete[] adjList;
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
	int startingNode;
	cout << "Enter starting node: ";
	cin >> startingNode;
	cout << "Total Cost: " << obj.Prim(startingNode);
}