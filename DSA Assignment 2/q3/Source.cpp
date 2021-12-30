#pragma once
template<class T>
class Node
{
public:
	T data;
	Node<T>* next;
};

#pragma once
#include<iostream>
using namespace std;
template<class T>
class Queue
{
public:
	Queue()
	{
		head = nullptr;
		queue_size = -1;
	}
	void enqueue(T const& e)
	{
		if (head == nullptr)
		{
			Node<T>* temp = new Node<T>;
			temp->data = e;
			temp->next = nullptr;
			head = temp;
		}
		else
		{
			Node<T>* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			Node<T>* temp = new Node<T>;
			temp->data = e;
			temp->next = nullptr;
			current->next = temp;
		}
		queue_size++;
	}
	void dequeue()
	{
		if (head == nullptr)
		{
			cout << "Queue is empty" << endl;
			return;
		}
		Node<T>* current = head;
		head = current->next;
		delete current;
		queue_size--;
	}
	int size()
	{
		return queue_size + 1;
	}
	bool isEmpty()
	{
		if (head == nullptr)
		{
			return true;
		}
		return false;
	}
	bool front(T& e)
	{
		if (head == nullptr)
		{
			return false;
		}
		e = head->data;
		return true;
	}
	~Queue()
	{
		Node<T>* current = head;
		while (current != nullptr)
		{
			head = current->next;
			delete current;
			current = head;
		}
	}
private:
	Node<T>* head;
	int queue_size;
};

int main()
{
	int user = -1;
	Queue<int>obj;
	while (user != 0)
	{
		cout << "********************Menu*********************\n";
		cout << "Press 1 to enqueue\n";
		cout << "Press 2 to dequeue\n";
		cout << "Press 3 to check queue size\n";
		cout << "Press 4 to check if the queue is empty\n";
		cout << "Press 5 to check the top element in the queue\n";
		cout << "Press 0 to quit\n";
		cout << "**********************************************\n";
		cout << "Enter your choice: ";
		cin >> user;
		if (user == 1)
		{
			int value;
			cout << "Enter element: ";
			cin >> value;
			obj.enqueue(value);
		}
		if (user == 2)
		{
			obj.dequeue();
		}
		if (user == 3)
		{
			int s = obj.size();
			cout << "Size of queue = " << s << endl;
		}
		if (user == 4)
		{
			bool answer = obj.isEmpty();
			if (answer == true)
			{
				cout << "Queue is empty\n";
			}
			else
			{
				cout << "Queue is not empty\n";
			}
		}
		if (user == 5)
		{
			int e;
			bool v = obj.front(e);
			if (v == false)
			{
				cout << "Queue is empty\n";
			}
			else
			{
				cout << "Top value = " << e << endl;
			}
		}
	}
	return 0;
}