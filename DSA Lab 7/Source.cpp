#pragma once
template<class T>
class Node
{
public:
	Node* next;
	Node* previous;
	int data;
};

#pragma once
#include<iostream>
using namespace std;
template<class T>
class DoublyLinkedList
{
public:
	DoublyLinkedList()
	{
		head = new Node<T>;
		tail = head;
		head->next = nullptr;
		head->previous = nullptr;
	}
	void insertAtEnd(T const element)
	{
		Node<T>* temp = new Node<T>;
		temp->data = element;
		temp->next = nullptr;
		temp->previous = nullptr;
		Node<T>* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = temp;
		temp->previous = current;
		temp->next = nullptr;
		tail = temp;
	}
	void insertAtStart(T const element)
	{
		Node<T>* temp = new Node<T>;
		temp->data = element;
		temp->next = head->next;
		temp->previous = head;
		head->next = temp;
		Node < T>* current = temp->next;
		current->previous = temp;
	}
	void deleteAtStart()
	{
		Node<T>* current = head;
		if (current->next == nullptr)
		{
			return;
		}
		current = current->next;
		head->next = current->next;
		current->next->previous = head;
		delete current;
		current = nullptr;
	}
	void deleteAtEnd()
	{
		Node<T>* current = head;
		if (current->next == nullptr)
		{
			return;
		}
		while (current->next != nullptr)
		{
			current = current->next;
		}
		Node<T>* prev = current->previous;
		prev->next = nullptr;
		delete current;
		current = nullptr;
		tail = prev;
	}
	void print()
	{
		Node<T>* current = head->next;
		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
	void insertAtMiddle(T const element)
	{
		int size = 0;
		Node<T>* current = head->next;
		while (current != nullptr)
		{
			size++;
			current = current->next;
		}
		int middle = size / 2;
		current = head->next;
		for (int i = 1; i <= middle; i++)
		{
			current = current->next;
		}
		Node<T>* temp = new Node<T>;
		temp->data = element;
		temp->next = current->next;
		current->next->previous = temp;
		temp->previous = current;
		current->next = temp;
	}
	void removeDuplicate()
	{
		Node<T>* current = nullptr;
		Node<T>* duplicate = nullptr;
		for (current = head->next; current != nullptr; current = current->next)
		{
			duplicate = current->next;
			while (duplicate != nullptr)
			{
				if (duplicate->data == current->data)
				{
					Node<T>* n = duplicate->next;
					Node<T>* p = duplicate->previous;
					if (n == nullptr)
					{
						p->next = n;
						delete duplicate;
						tail = p;
						duplicate = nullptr;
					}
					else
					{
						n->previous = p;
						p->next = n;
						delete duplicate;
						duplicate = n;
					}
				}
				else
				{
					duplicate = duplicate->next;
				}
			}
		}
	}
	bool insertBefore(T const v1, T const v2)
	{
		Node<T>* search = head->next;
		bool found = false;
		while (search != nullptr)
		{
			if (search->data == v2)
			{
				found = true;
				break;
			}
			else
			{
				search = search->next;
			}
		}
		if (found == true)
		{
			Node<T>* temp = new Node<T>;
			temp->data = v1;
			temp->next = nullptr;
			temp->previous = nullptr;
			Node<T>* current = head->next;
			while (current != nullptr)
			{
				if (current->data == v2)
				{
					temp->next = current;
					temp->previous = current->previous;
					current->previous->next = temp;
					current->previous = temp;
					return true;
				}
				current = current->next;
			}
			return false;
		}
	}
	void reverse()
	{
		int size = 0;
		Node<T>* current = head->next;
		while (current != nullptr)
		{
			size++;
			current = current->next;
		}
		T* array = new T[size];
		int index = 0;
		current = head->next;
		while (current != nullptr)
		{
			array[index] = current->data;
			index++;
			current = current->next;
		}
		current = head;
		while (current != nullptr)
		{
			head = head->next;
			delete current;
			current = head;
		}
		head = nullptr;
		tail = nullptr;
		current = nullptr;
		head = new Node<T>;
		tail = head;
		head->next = nullptr;
		head->previous = nullptr;
		for (int i = size - 1; i >= 0; i--)
		{
			Node<T>* temp = new Node<T>;
			temp->data = array[i];
			temp->next = nullptr;
			temp->previous = nullptr;
			current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = temp;
			temp->previous = current;
			temp->next = nullptr;
			tail = temp;
		}
		delete[]array;
	}
	~DoublyLinkedList()
	{
		Node<T>* current = head;
		while (current != nullptr)
		{
			head = head->next;
			delete current;
			current = head;
		}
		head = nullptr;
		tail = nullptr;
		current = nullptr;
	}
private:
	Node<T>* head;
	Node<T>* tail;
};

int main()
{
	DoublyLinkedList<int>obj;
	obj.insertAtEnd(7);
	obj.insertAtEnd(9);
	obj.insertAtStart(9);
	obj.insertAtEnd(10);
	obj.insertAtEnd(9);
	obj.insertAtMiddle(15);
	obj.print();
	bool insert = obj.insertBefore(6, 11);
	if (insert == true)
	{
		cout << "Value inserted\n";
	}
	else
	{
		cout << "Value not inserted\n";
	}
	obj.print();
	obj.reverse();
	obj.print();
	return 0;
}