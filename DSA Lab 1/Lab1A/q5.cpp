#include<iostream>
using namespace std;

int main()
{
	int* ptr = new int;
	cout << "Enter Int Value: ";
	cin >> *ptr;
	cout << "Value is: " << *ptr << endl;
	cout << "Pointer Value is: " << ptr << endl;
	delete ptr; //dangling pointer
	cout << "After Del, Value is: " << *ptr << endl;
	cout << "After Del, Pointer Value is: " << ptr << endl;
	cout << "Dangling Pointer? If Yes, then Resolve issue" << endl;
	ptr = 0;
	cout << "Dynamically occupied Float Variable: "<< new float << endl;
	int* ptr1 = new int;
	*ptr1 = 9;
	cout << *ptr1 << endl;
	//memory leak as previous memory of ptr1 is not deleted
	ptr1 = new int;
	cout << *ptr1 << endl;
	*ptr1 = 9;
	cout << "Is there any Memory Leak" << endl; //ptr1 is not deleted
	int a;
	int *ptr2;
	*ptr2 = 10;
	// if any illegal access, resolve it.
	return 0;
}

