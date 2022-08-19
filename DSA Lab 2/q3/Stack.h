#pragma once
#include<vector>
#include<iostream>
using namespace std;
template<class T>
class Stack
{
public:
	Stack()
	{

	}
	void Push(T value)
	{
		stack.push_back(value);
	}
	T Pop()
	{
		if (stack.size() > 0)
		{
			T value = stack[stack.size() - 1];
			stack.pop_back();
			return value;
		}
		else
		{
			cout << "Error! Stack is empty\n";
			return "";
		}
	}
	T Top()
	{
		if (stack.size() > 0)
		{
			T top = stack.size() - 1;
			return stack[top];
		}
		else
		{
			cout << "Error! Stack is empty\n";
			return "";
		}
	}
	bool isEmpty()
	{
		if (stack.size() > 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	~Stack()
	{

	}
	void Print()
	{
		int length = stack.size();
		for (int i = 0; i < length; i++)
		{
			cout << stack[i] << endl;
		}
	}
private:
	vector<T>stack;
};
