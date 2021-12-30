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
class Stack
{
public:
	Stack()
	{
		head = nullptr;
	}
	int size()
	{
		return stack_size + 1;
	}
	bool isEmpty()
	{
		if (head == nullptr)
		{
			return true;
		}
		return false;
	}
	void push(T const& value)
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
		stack_size++;
	}
	bool Top(T& e)
	{
		if (head == nullptr)
		{
			return false;
		}
		Node<T>* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		e = current->data;
		return true;
	}
	void pop()
	{
		if (head == nullptr)
		{
			cout << "Stack is empty" << endl;
			return;
		}
		Node<T>* current = head;
		Node<T>* previous = head;
		while (current->next != nullptr)
		{
			previous = current;
			current = current->next;
		}
		delete current;
		current = previous;
		current->next = nullptr;
		stack_size--;
		if (stack_size == -1)
		{
			head = nullptr;
			cout << "Stack is empty" << endl;
			return;
		}
	}
	~Stack()
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
	int stack_size = -1;
};

int main()
{
	int user = -1;
	Stack<int>obj;
	while (user != 0)
	{
		cout << "********************Menu*********************\n";
		cout << "Press 1 to push\n";
		cout << "Press 2 to pop\n";
		cout << "Press 3 to check stack size\n";
		cout << "Press 4 to check if the stack is empty\n";
		cout << "Press 5 to check the top element in the stack\n";
		cout << "Press 0 to quit\n";
		cout << "**********************************************\n";
		cout << "Enter your choice: ";
		cin >> user;
		if (user == 1)
		{
			int value;
			cout << "Enter element: ";
			cin >> value;
			obj.push(value);
		}
		if (user == 2)
		{
			obj.pop();
		}
		if (user == 3)
		{
			int s = obj.size();
			cout << "Size of stack = " << s << endl;
		}
		if (user == 4)
		{
			bool answer = obj.isEmpty();
			if (answer == true)
			{
				cout << "Stack is empty\n";
			}
			else
			{
				cout << "Stack is not empty\n";
			}
		}
		if (user == 5)
		{
			int e;
			bool v = obj.Top(e);
			if (v == false)
			{
				cout << "Stack is empty\n";
			}
			else
			{
				cout << "Top value = " << e << endl;
			}
		}
	}
	return 0;
}