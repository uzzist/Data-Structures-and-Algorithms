#pragma once
#include<iostream>
using namespace std;
template<class T>
class Queue
{
public:
	Queue()
	{
		size = 0;
		for (int index = 0; index < 10; index++)
		{
			array[index] = 0;
		}
	}
	int Size()
	{
		return size;
	}
	bool isEmpty()
	{
		if (size > 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	T& Front()
	{
		if (size > 0)
		{
			return array[0];
		}
		else
		{
			return 0;
		}
	}
	void Dequeue()
	{
		if (size > 0)
		{
			array[0] = 0;
			T temp;
			for (int index = 0; index < 9; index++)
			{
				temp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = temp;
			}
			size--;
		}
		else
		{
			cout << "Queue is empty!\n";
		}
	}
	void Enqueue(T value)
	{
		if (size < 10)
		{
			array[size] = value;
			size++;
		}
		else
		{
			cout << "Error! Queue is full!\n";
		}
	}
	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << array[i] << endl;
		}
	}
private:
	T array[10];
	int size;
};