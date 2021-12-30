#include<iostream>
using namespace std;

int stringCompare(char const*, char const*);

int main()
{
	char* string1 = new char[20];
	char* string2 = new char[20];
	cout << "Enter first string: ";
	cin >> string1;
	cout << "Enter second string: ";
	cin >> string2;
	int result = stringCompare(string1, string2);
	if (result == 0)
	{
		cout << "Strings are equal\n";
	}
	else if (result == 1)
	{
		cout << "String1 is greater than string2\n";
	}
	else
	{
		cout << "String2 is greater than string1\n";
	}
	delete[]string1;
	delete[]string2;
	return 0;
}
int stringCompare(char const* string1, char const* string2)
{
	if (string1[0] == '\0' &&  string2[0] == '\0')
	{
		return 0;
	}
	else if (string1[0] > string2[0])
	{
		return 1;
	}
	else if (string1[0] < string2[0])
	{
		return -1;
	}
	else
	{
		return stringCompare(string1 + 1, string2 + 1);
	}
}
