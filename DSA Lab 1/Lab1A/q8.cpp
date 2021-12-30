#include<iostream>
using namespace std;

int main()
{
	string one, two;
	cout << "Enter first string: ";
	cin >> one;
	cout << "Enter second string: ";
	cin >> two;
	if(one == two)
	{
		cout << one << " is equal to " << two;
	}
	else
	{
		cout << one << " is not equal to " << two;
	}
	return 0;
}
