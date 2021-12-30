#pragma once
#include<iostream>
#include<string>
using namespace std;
template<class T>
class Stack
{
public:
	Stack()
	{
		size = -1;
	}
	void Push(T value)
	{
		size++;
		array[size] = value;
	}
	void Pop()
	{
		if (size >= 0)
		{
			size--;
		}
		else
		{
			return;
		}
	}
	T Top()
	{
		T value = array[size];
		return value;
	}
	bool isEmpty()
	{
		if (size >= 0)
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
private:
	T array[100];
	int size;
};

void InfixToPrefix(string);
bool isOperator(char);
int precedence(char);

int main()
{
	string exp;
	cout << "Enter an infix expression: ";
	cin >> exp;
	InfixToPrefix(exp);
	return 0;
}
bool isOperator(char s)
{
	if (s == '+' || s == '-' || s == '^' || s == '*' || s == '/')
	{
		return true;
	}
	else
	{
		return false;
	}
}
int precedence(char s)
{
	if (s == '^')
	{
		return 3;
	}
	else if (s == '*' || s == '/')
	{
		return 2;
	}
	else if (s == '+' || s == '-')
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
void InfixToPrefix(string exp)
{
	reverse(exp.begin(), exp.end());
	Stack<char>obj;
	string prefix;
	int length = exp.length();
	for (int index = 0; index < length; index++)
	{
		if (exp[index] >= 'a' && exp[index] <= 'z' || exp[index] >= 'A' && exp[index] <= 'Z')
		{
			prefix += exp[index];
		}
		else if (exp[index] == '(')
		{
			obj.Push(exp[index]);
		}
		else if (exp[index] == ')')
		{
			while ((obj.Top() != '(') && (!obj.isEmpty()))
			{
				prefix += obj.Top();
				obj.Pop();
			}
		}
		else if (isOperator(exp[index]))
		{
			if (obj.isEmpty())
			{
				obj.Push(exp[index]);
			}
			else
			{
				if (precedence(exp[index]) > precedence(obj.Top()))
				{
					obj.Push(exp[index]);
				}
				else if (precedence(exp[index]) == precedence(obj.Top()) && exp[index] == '^')
				{
					obj.Push(exp[index]);
				}
				else
				{
					while (!obj.isEmpty() && precedence(exp[index]) <= precedence(obj.Top()))
					{
						prefix += obj.Top();
						obj.Pop();
					}
					obj.Push(exp[index]);
				}
			}
		}
	}
	while (!obj.isEmpty())
	{
		prefix += obj.Top();
		obj.Pop();
	}
	reverse(prefix.begin(), prefix.end());
	cout << "Infix to Prefix = " << prefix << endl;
}