#include<vector>
#include<string>
#include<iostream>
#include "Stack.h"
using namespace std;

string RemoveConsecutiveWords(string data)
{
	Stack<string>obj;
	string temp1 = "", temp2 = "";
	int count = 0;
	bool first_iteration = true;
	while(count < data.length())
	{
		if (first_iteration == true)
		{
			for (int j = count; data[j] != ' '; j++)
			{
				temp1 += data[j];
				count++;
			}
			count++;
		}
		for (int k = count; data[k] != '\0'; k++)
		{
			if (data[k] != ' ')
			{
				temp2 += data[k];
				count++;
			}
			else
			{
				break;
			}
		}
		count++;
		if (first_iteration == true)
		{
			if (temp1 != temp2)
			{
				obj.Push(temp1);
				obj.Push(temp2);
				first_iteration = false;
			}
			temp1 = "";
			temp2 = "";
		}
		else
		{
			if (obj.isEmpty() == false)
			{
				temp1 = obj.Pop();
			}
			else
			{
				temp1 = "";
			}
			if (temp1 == "")
			{
				obj.Push(temp2);
			}
			else if (temp1 != temp2)
			{
				obj.Push(temp1);
				obj.Push(temp2);
			}
			temp1 = "";
			temp2 = "";
		}
	}
	string result = "";
	while (!obj.isEmpty())
	{
		result += obj.Pop();
		result += " ";
	}
	return result;
}

int main()
{
	string data;
	cout << "Enter string: ";
	getline(cin, data);
	cout << "Final string = " << RemoveConsecutiveWords(data) << endl;
	return 0;
}
