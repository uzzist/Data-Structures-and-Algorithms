#include<iostream>
using namespace std;

int main()
{
	int* x = new int;
	cout << "Enter value: ";
	cin >> *x;
	float* y = new float;
	cout << "Enter value: ";
	cin >> *y;
	char* z = new char;
	cout <<"Enter character: ";
	cin >> *z;
	if(!(x == new int))
	{
		cout << "Error: out of memory." << endl;
	}
	else
	{
		cout << "Value of x is " << *x << endl;
	}
	if(!(y == new float))
	{
		cout << "Error: out of memory." << endl;
	}
	else
	{
		cout << "Value of y is " << *y << endl;
	}
	if(!(z == new char))
	{
		cout << "Error: out of memory." << endl;
	}
	else
	{
		cout << "Value of z is " << *z << endl;
	}
	return 0;
}
