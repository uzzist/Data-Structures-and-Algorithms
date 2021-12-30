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
	void reversePrint(Node<T>* current)const
	{
		if (current != nullptr)
		{
			reversePrint(current->next);
			cout << current->data << " ";
		}
	}
	void recursivePrint()const
	{
		reversePrint(head);
		cout << endl;
	}
	int count_length(Node<T>* current)
	{
		if (current == nullptr)
		{
			return 0;
		}
		else
		{
			return 1 + count_length(current->next);
		}
	}
	int length()
	{
		int list_length = 0;
		list_length += count_length(head);
		return list_length;
	}
	bool check_isSorted(Node<T>* current)const
	{
		if (current == nullptr || current->next == nullptr)
		{
			return true;
		}
		else
		{
			return (current->data < current->next->data&& check_isSorted(current->next));
		}
	}
	bool isSorted()const
	{
		if (check_isSorted(head))
		{
			return true;
		}
		return false;
	}
	void deleteList(Node<T>* current)const
	{
		if (current == nullptr)
		{
			return;
		}
		deleteList(current->next);
		delete current;
	}
	void deleteAll()
	{
		deleteList(head);
		head = nullptr;
	}
private:
	Node<T>* head;
};

int product(int, int);

int main()
{
	int first = 15, second = -9;
	cout << "Product of " << first << " and " << second << " = " << product(first, second) << endl;
	SinglyLinkedList<int>obj;
	obj.insertAtStart(10);
	obj.insertAtStart(9);
	obj.insertAtStart(7);
	obj.insertAtStart(5);
	obj.recursivePrint();
	bool output = obj.isSorted();
	if (output)
	{
		cout << "List is sorted in ascending order\n";
	}
	else
	{
		cout << "List is not sorted\n";
	}
	int len = obj.length();
	cout << "Length of linked list = " << len << endl;
	obj.deleteAll();
	len = obj.length();
	cout << "Length of linked list = " << len << endl;
	return 0;
}
int product(int first, int second)
{
	if (first < 0 && second < 0)
	{
		return product(first * -1, second * -1);
	}
	else if (first > 0 && second < 0)
	{
		return product(second, first);
	}
	else if (first > second)
	{
		return product(second, first);
	}
	else if (second != 0)
	{
		return first + product(first, second - 1);
	}
	else
	{
		return 0;
	}
}