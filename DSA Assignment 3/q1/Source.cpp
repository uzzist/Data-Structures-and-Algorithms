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
class SinglyLinkedList
{
public:
	SinglyLinkedList()
	{
		head = nullptr;
		size = 0;
	}
	void insertAtStart(T value)
	{
		Node<T>* temp = new Node<T>;
		temp->data = value;
		temp->next = nullptr;
		if (head == nullptr)
		{
			head = temp;
		}
		else
		{
			temp->next = head;
			head = temp;
		}
		size++;
	}
	void insertAtEnd(T value)
	{
		if (head == nullptr)
		{
			Node<T>* temp = new Node<T>;
			temp->data = value;
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
			temp->data = value;
			temp->next = nullptr;
			current->next = temp;
		}
		size++;
	}
	void Print()
	{
		Node<T>* current = head;
		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
	}
	bool search(T value)
	{
		Node<T>* current = head;
		while (current != nullptr)
		{
			if (current->data == value)
			{
				return true;
			}
			current = current->next;
		}
		return false;
	}
	bool isEmpty()
	{
		if (head == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool insertBefore(T v1, T v2)
	{
		if (head == nullptr)
		{
			return false;
		}
		else if (search(v2))
		{
			Node<T>* temp = new Node<T>;
			temp->data = v1;
			temp->next = nullptr;
			Node<T>* current = head;
			Node<T>* previous = head;
			while (current != nullptr)
			{
				if (current->data == v2)
				{
					temp->next = current;
					previous->next = temp;
					return true;
				}
				current = current->next;
				previous->next = current;
			}
		}
		else
		{
			return false;
		}
		size++;
	}
	void deleteAll(T value)
	{
		Node<T>* current = head;
		Node<T>* previous = head;
		if (current->data == value)
		{
			head = current->next;
			delete current;
			current = head;
			previous = head;
			size--;
		}
		while (current != nullptr)
		{
			if (current->data == value)
			{
				previous->next = current->next;
				delete current;
				current = previous->next;
				size--;
			}
			else
			{
				previous = current;
				current = current->next;
			}
		}
	}
	~SinglyLinkedList()
	{
		Node<T>* current = head;
		for (int index = 0; index < size; index++)
		{
			head = current->next;
			delete current;
			current = head;
		}
	}
	void deleteAtStart()
	{
		if (head == nullptr)
		{
			return;
		}
		Node<T>* current = head;
		head = current->next;
		delete current;
		size--;
	}
	bool hasCycle(Node<T>* head)
	{
		Node<T>* current = head;
		int temp_size = 0;
		while (temp_size < size - 1)
		{
			current = current->next;
			temp_size++;
		}
		if (current->next == nullptr)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	bool checkCycle()
	{
		if (hasCycle(head))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void checkSize()
	{
		cout << "\nSize = " << size << endl;
	}
	void makeCycle()
	{
		Node<T>* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = head->next;
	}
private:
	Node<T>* head;
	int size;
};

int main()
{
	SinglyLinkedList<int>obj;
	obj.insertAtEnd(2);
	obj.insertAtEnd(3);
	obj.insertAtEnd(4);
	bool cycle = obj.checkCycle();
	if (cycle == true)
	{
		cout << "Linked List has a cycle" << endl;
	}
	else
	{
		cout << "Linked List does not have a cycle" << endl;
	}
	obj.makeCycle();
	cycle = obj.checkCycle();
	if (cycle == true)
	{
		cout << "Linked List has a cycle" << endl;
	}
	else
	{
		cout << "Linked List does not have a cycle" << endl;
	}
	return 0;
}