#include<iostream>
using namespace std;
class arrBST
{
public:
	arrBST();
	~arrBST();
	void insertElement(int);
	void searchElement(int);
	void inOrder(int);
	void preOrder(int);
	void postOrder(int);
private:
	int* arr;
	int size;
};

arrBST::arrBST()
{
	size = 20;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = -1;
	}
}
arrBST::~arrBST()
{
	delete[]arr;
}
void arrBST::insertElement(int value)
{
	if (arr[1] == -1)
	{
		arr[1] = value;
	}
	else
	{
		int current = 1;
		while (current < size)
		{
			if (value > arr[current])
			{
				current = current * 2 + 1;
			}
			else if (value < arr[current])
			{
				current = current * 2;
			}
			else
			{
				arr[current] = value;
				break;
			}
			if (arr[current] == -1 && current < size)
			{
				arr[current] = value;
				break;
			}
		}
	}
}
void arrBST::searchElement(int value)
{
	if (arr[1] == value)
	{
		cout << endl << value << " found in BST\n";
		return;
	}
	int flag = 0;
	for (int current = 1; current < size;)
	{
		if (value > arr[current])
		{
			current = current * 2 + 1;
		}
		else if (value < arr[current])
		{
			current = current * 2;
		}
		else
		{
			cout << endl << value << " found in BST\n";
			break;
		}
		if (value == arr[current])
		{
			cout << endl << value << " found in BST\n";
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		cout << endl << value << " not found in BST\n";
	}
}
void arrBST::inOrder(int currentIndex)
{
	if (currentIndex < size && currentIndex > 0 && arr[currentIndex] != -1)
	{
		inOrder(currentIndex * 2);
		cout << arr[currentIndex] << " ";
		inOrder(currentIndex * 2 + 1);
	}
}
void arrBST::preOrder(int currentIndex)
{
	if (currentIndex < size && currentIndex > 0 && arr[currentIndex] != -1)
	{
		cout << arr[currentIndex] << " ";
		inOrder(currentIndex * 2);
		inOrder(currentIndex * 2 + 1);
	}
}
void arrBST::postOrder(int currentIndex)
{
	if (currentIndex < size && currentIndex > 0 && arr[currentIndex] != -1)
	{
		inOrder(currentIndex * 2);
		inOrder(currentIndex * 2 + 1);
		cout << arr[currentIndex] << " ";
	}
}

int main()
{
	arrBST obj;
	obj.insertElement(8);
	obj.insertElement(7);
	obj.insertElement(9);
	obj.insertElement(6);
	cout << "In Order printing: ";
	obj.inOrder(1);
	cout << "\nPre Order printing: ";
	obj.preOrder(1);
	cout << "\nPost Order printing: ";
	obj.postOrder(1);
	obj.searchElement(5);
	return 0;
}