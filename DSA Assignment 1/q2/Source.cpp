#pragma once
#include<iostream>
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

void Evaluation_of_Infix(string);
void Evaluation_of_Postfix(string);
void Evaluation_of_Prefix(string);
bool isOperator(char);
int precedence(char);
int calculation(int, int, char);

int main()
{
	int user = -1;
	while (user != 0)
	{
		cout << "********************MENU********************\n";
		cout << "Press 1 for Evaluation of Infix expression\n";
		cout << "Press 2 for Evaluation of Postfix expression\n";
		cout << "Press 3 for Evaluation of Prefix expression\n";
		cout << "Press 0 to quit\n";
		cout << "********************************************\n";
		cout << "Enter your choice: ";
		cin >> user;
		if (user == 1)
		{
			string exp;
			cout << "Enter infix expressions: ";
			cin >> exp;
			Evaluation_of_Infix(exp);
		}
		if (user == 2)
		{
			string exp;
			cout << "Enter postfix expressions: ";
			cin >> exp;
			Evaluation_of_Postfix(exp);
		}
		if (user == 3)
		{
			string exp;
			cout << "Enter prefix expressions: ";
			cin >> exp;
			Evaluation_of_Prefix(exp);
		}
	}
	return 0;
}
bool isOperator(char op)
{
	if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
	{
		return true;
	}
	else
	{
		return false;
	}
}
int precedence(char op)
{
	if (op == '^')
	{
		return 3;
	}
	else if(op == '*' || op == '/')
	{
		return 2;
	}
	else if (op == '+' || op == '-')
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int calculation(int num1, int num2, char op)
{
	if (op == '+')
	{
		return num1 + num2;
	}
	if (op == '-')
	{
		return num1 - num2;
	}
	if (op == '*')
	{
		return num1 * num2;
	}
	if (op == '/')
	{
		return num1 / num2;
	}
	if (op == '^')
	{
		while (num2 != 0)
		{
			num1 *= num1;
			num2--;
		}
		return num1;
	}
}
void Evaluation_of_Infix(string exp)
{
	Stack<int>operand;
	Stack<char>operators;
	int length = exp.length();
	for (int index = 0; index < length; index++)
	{
		if (exp[index] == '(')
		{
			operators.Push(exp[index]);
		}
		else if (exp[index] >= '0' && exp[index] <= '9')
		{
			int result = 0;
			while (index < length && isdigit(exp[index]))
			{
				result = (result * 10) + (exp[index] - '0');
				index++;
			}
			index--;
			operand.Push(result);
		}
		else if (isOperator(exp[index]))
		{
			operators.Push(exp[index]);
		}
		else if (exp[index] == ')')
		{
			while (!operators.isEmpty() && operators.Top() != '(')
			{
				int num2 = operand.Top();
				operand.Pop();
				int num1 = operand.Top();
				operand.Pop();
				char op = operators.Top();
				operators.Pop();
				operand.Push(calculation(num1, num2, op));
			}
			if (!operators.isEmpty())
			{
				operators.Pop();
			}
		}
		else
		{
			while (!operators.isEmpty() && precedence(operators.Top()) >= precedence(exp[index]))
			{
				int num2 = operand.Top();
				operand.Pop();
				int num1 = operand.Top();
				operand.Pop();
				char op = operators.Top();
				operators.Pop();
				operand.Push(calculation(num1, num2, op));
			}
			operators.Push(exp[index]);
		}
	}
	while (!operators.isEmpty())
	{
		int num2 = operand.Top();
		operand.Pop();
		int num1 = operand.Top();
		operand.Pop();
		char op = operators.Top();
		operators.Pop();
		operand.Push(calculation(num1, num2, op));
	}
	int final = operand.Top();
	cout << "Infix result = " << final << endl;
}
void Evaluation_of_Postfix(string exp)
{
	Stack<int>operand;
	int length = exp.length();
	for (int index = 0; index < length; index++)
	{
		if (exp[index] >= '0' && exp[index] <= '9')
		{
			operand.Push(exp[index] - '0');
		}
		else
		{
			int num2 = operand.Top();
			operand.Pop();
			int num1 = operand.Top();
			operand.Pop();
			char op = exp[index];
			operand.Push(calculation(num1, num2, op));
		}
	}
	int final = operand.Top();
	cout << "Postfix result = " << final << endl;
}
void Evaluation_of_Prefix(string exp)
{
	Stack<int>operand;
	int length = exp.length();
	for (int index = length - 1; index >= 0; index--)
	{
		if (exp[index] >= '0' && exp[index] <= '9')
		{
			operand.Push(exp[index] - '0');
		}
		else
		{
			int num1 = operand.Top();
			operand.Pop();
			int num2 = operand.Top();
			operand.Pop();
			char op = exp[index];
			operand.Push(calculation(num1, num2, op));
		}
	}
	int final = operand.Top();
	cout << "Prefix result = " << final << endl;
}