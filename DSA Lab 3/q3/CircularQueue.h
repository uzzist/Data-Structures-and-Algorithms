#pragma once
#include<vector>
#include<iostream>
using namespace std;
template<class T>
class CircularQueue
{
public:
	CircularQueue()
	{
		array = nullptr;
		front = -1;
		rear = -1;
	}
	CircularQueue(int size)
	{
		this->size = size;
		array = new T[size];
		front = -1;
		rear = -1;
	}
	void Enqueue(T value)
	{
		if (isFull)
		{
			cout << "Array is full. Cannot add more elements!" << endl;
		}
		else if (isEmpty)
		{
			front = rear = 0;
		}
		else
		{
			rear = (rear + 1) % size;
		}
		array[rear] = value;
	}
	T Dequeue()
	{
		T value;
		if (isEmpty)
		{
			return 0;
		}
		else if (front == rear)
		{
			value = array[front];
			front = rear = -1;
		}
		else
		{
			value = array[front];
			front = (front + 1) % size;
		}
		return value;
	}
	bool isFull()
	{
		if ((rear + 1) % size == front)
		{
			return true;
		}
		else
		{
			return false;
		}
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
	int front, rear, size;
};

