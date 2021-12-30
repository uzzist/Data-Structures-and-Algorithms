#include "Stack.h"
#include<vector>
#include<string>
#include<iostream>
using namespace std;

string RemoveConsecutiveWords(string data)
{
	Stack<string>obj;
	string temp1 = "", temp2 = "";
	int count = 0;
	for (int i = count; i < data.length(); i++)
	{
		for (int j = i; data[j] != ' '; j++)
		{
			temp1 += data[j];
			count++;
		}
		for (int k = count; data[k] != ' '; k++)
		{
			temp2 += data[k];
			count++;
		}
		if (temp1 == temp2)
		{
			continue;
		}
		else
		{
			obj.Push(temp1);
		}
	}
	string result = "";
	while (!obj.isEmpty())
	{
		result += obj.Pop();
	}
	return result;
}

int main()
{
	string data;
	cout << "Enter string: ";
	getline(cin, data);
	string final = RemoveConsecutiveWords(data);
	cout << "Final string = " << final << endl;
	return 0;
}