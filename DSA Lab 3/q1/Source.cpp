#include "Stack.h"
#include<vector>
#include<string>
#include<iostream>
using namespace std;

bool isOpening(char value)
{
	if (value == '(' || value == '[' || value == '{')
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool isClosing(char bracket)
{
	if (bracket == ')' || bracket == ']' || bracket == '}')
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool checkPair(char closing, char opening)
{
	if (opening == '[' && closing == ']')
	{
		return true;
	}
	else if (opening == '(' && closing == ')')
	{
		return true;
	}
	else if (opening == '{' && closing == '}')
	{
		return true;
	}
	return false;
}
bool isBalanced(string expression)
{
	Stack<char>obj;
	int length = expression.length();
	for (int i = 0; i < length; i++)
	{
		if (isOpening(expression[i]))
		{
			obj.Push(expression[i]);
		}
		else if (isClosing(expression[i]))
		{
			if (obj.isEmpty() || !checkPair(expression[i], obj.Top()))
			{
				return false;
			}
			else
			{
				obj.Pop();
			}
		}
	}
	return true;
}

int main()
{
	string expression;
	cout << "Enter Expression: ";
	cin >> expression;
	if (isBalanced(expression))
	{
		cout << "Balanced";
	}
	else
	{
		cout << "Not balanced";
	}
	return 0;
}