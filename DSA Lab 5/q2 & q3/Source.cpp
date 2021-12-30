#include "Node.h"
#include "SinglyLinkedList.h"
#include<iostream>
using namespace std;

int main()
{
	SinglyLinkedList<int>obj;
	obj.insertAtStart(2);
	obj.insertAtStart(6);
	obj.insertAtStart(7);
	obj.insertAtEnd(9);
	obj.insertAtStart(7);
	obj.insertAtStart(8);
	obj.insertAtStart(9);
	obj.deleteAll(7);
	obj.Print();
	bool found = obj.search(2);
	if (found == false)
	{
		cout << "\nValue not found";
	}
	else
	{
		cout << "\nValue found";
	}
	found = obj.search(9);
	if (found == false)
	{
		cout << "\nValue not found";
	}
	else
	{
		cout << "\nValue found";
	}
	found = obj.search(10);
	if (found == false)
	{
		cout << "\nValue not found";
	}
	else
	{
		cout << "\nValue found";
	}
	obj.deleteAtStart();
	cout << endl;
	obj.Print();
	return 0;
}