#include "Stack.h"
#include<vector>
#include<string>
#include<iostream>
using namespace std;

int main()
{
	Stack<int>obj;
	for (int i = 0; i < 10; i++)
	{
		obj.Push(i);
	}
	obj.Print();
	for (int i = 0; i < 5; i++)
	{
		obj.Pop();
	}
	obj.Print();
	int top = obj.Top();
	cout << "Top value of stack is: " << top << endl;
	return 0;
}