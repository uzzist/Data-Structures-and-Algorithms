#include "Stack.h"
#include<vector>
#include<string>
#include<iostream>
using namespace std;

int GetMiddleValue(Stack<int>& currentStack)
{
	vector<int>temp;
	int num;
	for (int i = 0; i < 10; i++)
	{
		num = currentStack.Pop();
		temp.push_back(num);
	}
	int middle_index = temp.size() / 2;
	int middle_value = temp[middle_index];
	temp.erase(temp.begin() + middle_index);
	for (int i = temp.size() - 1; i >= 0; i--)
	{
		currentStack.Push(temp[i]);
	}
	return middle_value;
}

int main()
{
	Stack<int>obj;
	for (int i = 0; i < 10; i++)
	{
		obj.Push(i);
	}
	int middle = GetMiddleValue(obj);
	cout << "Middle value of stack = " << middle << endl;
	return 0;
}