#pragma once
#include "Node.h"
#include<iostream>
using namespace std;
template<class T>
class SinglyLinkedList
{
public:
	SinglyLinkedList()
	{
		head = nullptr;
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
		}
		while (current != nullptr)
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
	}
	~SinglyLinkedList()
	{
		Node<T>* current = head;
		while (current != nullptr)
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
	}
private:
	Node<T>* head;
};
