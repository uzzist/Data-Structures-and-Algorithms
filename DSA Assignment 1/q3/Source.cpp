#pragma once
#include<iostream>
#include<string>
using namespace std;
template<class T>
class CircularQueue
{
public:
	CircularQueue()
	{
		front = rear = -1;
		size = 0;
		capacity = 5;
		array = new T[capacity];
	}
	bool isEmpty()
	{
		if (front == -1 && rear == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Enqueue(T const& e)
	{
		if ((rear + 1) % capacity == front)
		{
			cout << "Queue is full. Cannot add more elements!" << endl;
		}
		else if (front == -1 && rear == -1)
		{
			front = rear = 0;
		}
		else
		{
			rear = (rear + 1) % capacity;
		}
		array[rear] = e;
		size++;
	}
	void Dequeue()
	{
		if (front == -1 && rear == -1)
		{
			cout << "Error! Queue is empty!\n";
		}
		else if (front == rear)
		{
			front = rear = -1;
			size--;
		}
		else
		{
			front = (front + 1) % capacity;
			size--;
		}
	}
	T front_element()
	{
		if (rear == -1 && front == -1)
		{
			return 0;
		}
		else
		{
			return array[front];
		}
	}
	int size_of()
	{
		return size;
	}
	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << array[i] << endl;
		}
	}
	~CircularQueue()
	{
		delete[]array;
	}
private:
	T* array;
	int front, rear, size, capacity;
};

int main()
{
	CircularQueue<int>obj;
	int number;
	int user = -1;
	while (user != 0)
	{
		cout << "********************MENU********************\n";
		cout << "Press 1 to Enqueue\n";
		cout << "Press 2 to Dequeue\n";
		cout << "Press 3 to check the front element\n";
		cout << "Press 4 to check the size of the queue\n";
		cout << "Press 5 to check if the queue is empty\n";
		cout << "Press 6 to print queue\n";
		cout << "Press 0 to quit\n";
		cout << "********************************************\n";
		cout << "Enter your choice: ";
		cin >> user;
		if (user == 1)
		{
			cout << "Enter an integer: ";
			cin >> number;
			obj.Enqueue(number);
		}
		if (user == 2)
		{
			obj.Dequeue();
		}
		if (user == 3)
		{
			int value = obj.front_element();
			if (value == 0)
			{
				cout << "\nThere is not front element as the Queue is empty!";
			}
			else
			{
				cout << "\nFront value in Queue = " << value << endl;
			}
		}
		if (user == 4)
		{
			int size_of_queue = obj.size_of();
			cout << "\nSize of queue = " << size_of_queue << endl;
		}
		if (user == 5)
		{
			if (obj.isEmpty())
			{
				cout << "Queue is empty!" << endl;
			}
			else
			{
				cout << "Queue is not empty!" << endl;
			}
		}
		if (user == 6)
		{
			obj.Print();
		}
		cout << endl;
	}
	cout << "Program Exited!" << endl;
	return 0;
}