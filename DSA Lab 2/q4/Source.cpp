#include<iostream>
#include<vector>
#include<string>
#include "Stack.h"
using namespace std;

string InfixToPostfix(string infix)
{
	Stack<string>obj;
	string temp;
	for (int i = 0; i < infix.length(); i++)
	{
		if (infix[i] == '*')
		{
			temp = infix[i];
			infix[i] = infix[i + 1];
			infix[i + 1] = temp;
		}
	}
}

int main()
{
	string infix;
	cout << "Enter infix expression: ";
	cin >> infix;
	string postfix = InfixToPostfix(infix);
	return 0;
}