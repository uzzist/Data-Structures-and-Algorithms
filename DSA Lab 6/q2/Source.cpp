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
class CircularLinkedList
{
public:
	CircularLinkedList()
	{
		head = nullptr;
	}
	void insertAtEnd(T const& element)
	{
		Node<T>* temp = new Node<T>;
		temp->data = element;
		temp->next = nullptr;
		if (head == nullptr)
		{
			head = temp;
			temp->next = head;
		}
		else
		{
			Node<T>* current = head;
			while (current->next != head)
			{
				current = current->next;
			}
			current->next = temp;
			temp->next = head;
		}
	}
	void insertAtStart(T const& element)
	{
		Node<T>* temp = new Node<T>;
		temp->data = element;
		temp->next = nullptr;
		if (head == nullptr)
		{
			head = temp;
			temp->next = head;
		}
		else
		{
			Node<T>* current = head;
			while (current->next != head)
			{
				current = current->next;
			}
			temp->next = head;
			head = temp;
			current->next = head;
		}
	}
	void Print()
	{
		Node<T>* current = head;
		while (current->next != head)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << current->data << " ";
	}
	bool search(T value)
	{
		Node<T>* current = head;
		while (current->next != head)
		{
			if (current->data == value)
			{
				return true;
			}
			current = current->next;
		}
		if (current->data == value)
		{
			return true;
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
	void deleteAll(T value)
	{
		Node<T>* current = head;
		Node<T>* previous = head;
		while (current->next != head)
		{
			if (current->data == value)
			{
				previous->next = current->next;
				delete current;
				current = previous->next;
			}
			else
			{
				previous = current;
				current = current->next;
			}
		}
		if (current->data == value)
		{
			previous->next = current->next;
			delete current;
			current = previous->next;
		}
	}
	~CircularLinkedList()
	{
		Node<T>* current = head;
		Node<T>* last = head;
		if (current->next == head)
		{
			delete current;
			head = nullptr;
			current = nullptr;
			last = nullptr;
		}
		else
		{
			while (last->next != head)
			{
				last = last->next;
			}
			while (current->next != head)
			{
				head = current->next;
				delete current;
				current = head;
				last->next = head;
			}
		}
	}
	void deleteAtStart()
	{
		if (head == nullptr)
		{
			return;
		}
		Node<T>* current = head;
		Node<T>* last = head;
		while (last->next != head)
		{
			last = last->next;
		}
		head = current->next;
		delete current;
		current = head;
		last->next = head;
	}
private:
	Node<T>* head;
};

int main()
{
	CircularLinkedList<int>obj;
	obj.insertAtStart(2);
	obj.insertAtStart(7);
	obj.insertAtStart(8);
	obj.insertAtEnd(9);
	obj.insertAtEnd(7);
	obj.insertAtEnd(7);
	obj.deleteAll(7);
	obj.Print();
	return 0;
}