#pragma once
template<class T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node()
	{
		data = 0;
		next = nullptr;
	}
	Node(T value)
	{
		data = value;
	}
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
		tail = nullptr;
	}
	void insertAtStart(T const element)
	{
		Node<T>* temp = new Node<T>;
		temp->data = element;
		temp->next = nullptr;
		if (head == nullptr)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			temp->next = head;
			head = temp;
		}
	}
	void insertAtEnd(T const element)
	{
		Node<T>* temp = new Node<T>;
		temp->data = element;
		temp->next = nullptr;
		if (head == nullptr)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = tail->next;
		}
	}
	SinglyLinkedList(const SinglyLinkedList& old_obj)
	{
		if (head != nullptr)
		{
			Node<T>current = nullptr;
			while (head != nullptr)
			{
				current = head;
				head = head->next;
				delete current;
			}
		}
		else if (old_obj.head == nullptr)
		{
			head = nullptr;
		}
		else
		{
			head = new Node<T>;
			head->data = old_obj.head->data;
			Node<T>* current = head;
			Node<T>* old_objhead = old_obj.head;
			Node<T>* currentobj = old_objhead;
			while (currentobj->next != nullptr)
			{
				current->next = new Node(currentobj->next->value);
				currentobj = currentobj->next;
				current = current->next;
			}
		}
	}
	void print()const
	{
		Node<T>* current = head;
		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
	}
	bool search(T const& value)const
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
	bool insertBefore(T const v1, T const v2)
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
	void deleteAll(T const value)
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
		head = nullptr;
		tail = nullptr;
	}
	void reverseDisplay(Node<T>* current)
	{
		if (current != nullptr)
		{
			reversePrint(current->next);
			cout << current->data << " ";
		}
	}
	void reversePrint()
	{
		reverseDisplay(head);
		cout << " ";
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
	int operator[](int index)
	{
		if (head == nullptr)
		{
			return -99;
		}
		else if (head != nullptr)
		{
			Node<T>* current = head;
			int i = 0;
			while (current != nullptr)
			{
				i++;
				if (i == index)
				{
					return current->data;
				}
				current = current->next;
			}
		}
		else
		{
			return -99;
		}
	}
	void operator+=(SinglyLinkedList obj)
	{
		Node<T>* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		Node<T>currentobj = obj.head;
		while (currentobj != nullptr)
		{
			current->next = currentobj;
			current = current->next;
			currentobj = currentobj->next;
		}
	}
private:
	Node<T>* head;
	Node<T>* tail;
};

int main()
{
	SinglyLinkedList<int>obj;
	obj.insertAtStart(2);
	obj.insertAtStart(6);
	obj.insertAtStart(7);
	obj.insertAtEnd(9);
	obj.insertAtStart(7);
	obj.insertAtStart(8);
	obj.insertAtStart(9);
	obj.deleteAll(7);
	obj.print();
	bool found = obj.search(2);
	if (found == false)
	{
		cout << "\nValue not found";
	}
	else
	{
		cout << "\nValue found";
	}
	found = obj.search(9);
	if (found == false)
	{
		cout << "\nValue not found";
	}
	else
	{
		cout << "\nValue found";
	}
	found = obj.search(10);
	if (found == false)
	{
		cout << "\nValue not found";
	}
	else
	{
		cout << "\nValue found";
	}
	obj.deleteAtStart();
	cout << endl;
	obj.print();
	return 0;
}
