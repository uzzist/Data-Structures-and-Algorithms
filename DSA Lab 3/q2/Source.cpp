#include "Queue.h"
#include<iostream>
using namespace std;

int main()
{
	Queue<int>obj;
	int user;
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter element: ";
		cin >> user;
		obj.Enqueue(user);
	}
	cout << "Stack if full enter element to check if you get an error: ";
	cin >> user;
	obj.Enqueue(user);
	cout << "\nChecking Dequeue function!\n";
	obj.Dequeue();
	obj.Enqueue(12);
	obj.Print();
	return 0;
}