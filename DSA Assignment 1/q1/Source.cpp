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

void InfixToPostfix(string);
void InfixToPrefix(string);
void PostfixToInfix(string);
void PostfixToPrefix(string);
void PrefixToInfix(string);
void PrefixToPostfix(string);
bool isOperator(char);
int precedence(char);

int main()
{
	int user = -1;
	while (user != 0)
	{
		cout << "**********MENU************************************\n";
		cout << "Press 1 for Infix to Postfix and Prefix conversion\n";
		cout << "Press 2 for Postfix to Infix and Prefix conversion\n";
		cout << "Press 3 for Prefix to Infix and Postfix conversion\n";
		cout << "Press 0 to quit\n";
		cout << "**************************************************\n";
		cout << "Enter your choice: ";
		cin >> user;
		if (user == 1)
		{
			string exp;
			cout << "Enter Infix expression: ";
			cin >> exp;
			InfixToPostfix(exp);
			InfixToPrefix(exp);
		}
		if (user == 2)
		{
			string exp;
			cout << "Enter Postfix expression: ";
			cin >> exp;
			PostfixToInfix(exp);
			PostfixToPrefix(exp);
		}
		if (user == 3)
		{
			string exp;
			cout << "Enter Prefix expression: ";
			cin >> exp;
			PrefixToInfix(exp);
			PrefixToPostfix(exp);
		}
	}
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
void InfixToPostfix(string exp)
{
	Stack<char>obj;
	string postfix;
	int length = exp.length();
	for (int index = 0; index < length; index++)
	{
		if (exp[index] >= 'a' && exp[index] <= 'z' || exp[index] >= 'A' && exp[index] <= 'Z')
		{
			postfix += exp[index];
		}
		else if (exp[index] == '(')
		{
			obj.Push(exp[index]);
		}
		else if (exp[index] == ')')
		{
			while ((obj.Top() != '(') && (!obj.isEmpty()))
			{
				postfix += obj.Top();
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
						postfix += obj.Top();
						obj.Pop();
					}
					obj.Push(exp[index]);
				}
			}
		}
	}
	while (!obj.isEmpty())
	{
		postfix += obj.Top();
		obj.Pop();
	}
	cout << "Infix to Postfix = " << postfix << endl;
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
void PostfixToInfix(string exp)
{
	Stack<string>obj;
	string infix;
	int length = exp.length();
	for (int index = 0; index < length; index++)
	{
		if (exp[index] >= 'a' && exp[index] <= 'z' || exp[index] >= 'A' && exp[index] <= 'Z')
		{
			string operand(1, exp[index]);
			obj.Push(operand);
		}
		else
		{
			string temp1 = obj.Top();
			obj.Pop();
			string temp2 = obj.Top();
			obj.Pop();
			obj.Push("(" + temp2 + exp[index] + temp1 + ")");
		}
	}
	infix = obj.Top();
	cout << "Postfix to Infix = " << infix << endl;
}
void PostfixToPrefix(string exp)
{
	Stack<string>obj;
	string prefix;
	int length = exp.length();
	for (int index = 0; index < length; index++)
	{
		if (exp[index] >= 'a' && exp[index] <= 'z' || exp[index] >= 'A' && exp[index] <= 'Z')
		{
			string operand(1, exp[index]);
			obj.Push(operand);
		}
		else
		{
			string temp1 = obj.Top();
			obj.Pop();
			string temp2 = obj.Top();
			obj.Pop();
			obj.Push(exp[index] + temp2 + temp1);
		}
	}
	prefix = obj.Top();
	cout << "Postfix to Prefix = " << prefix << endl;
}
void PrefixToInfix(string exp)
{
	Stack<string>obj;
	string infix;
	int length = exp.length();
	for (int index = length-1; index >= 0; index--)
	{
		if (exp[index] >= 'a' && exp[index] <= 'z' || exp[index] >= 'A' && exp[index] <= 'Z')
		{
			string operand(1, exp[index]);
			obj.Push(operand);
		}
		else
		{
			string temp1 = obj.Top();
			obj.Pop();
			string temp2 = obj.Top();
			obj.Pop();
			obj.Push("(" + temp1 + exp[index] + temp2 + ")");
		}
	}
	infix = obj.Top();
	cout << "Prefix to Infix = " << infix << endl;
}
void PrefixToPostfix(string exp)
{
	Stack<string>obj;
	string postfix;
	int length = exp.length();
	for (int index = length - 1; index >= 0; index--)
	{
		if (exp[index] >= 'a' && exp[index] <= 'z' || exp[index] >= 'A' && exp[index] <= 'Z')
		{
			string operand(1, exp[index]);
			obj.Push(operand);
		}
		else
		{
			string temp1 = obj.Top();
			obj.Pop();
			string temp2 = obj.Top();
			obj.Pop();
			obj.Push(temp1 + temp2 + exp[index]);
		}
	}
	postfix = obj.Top();
	cout << "Prefix to Infix = " << postfix << endl;
}