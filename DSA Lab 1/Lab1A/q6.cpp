#include<iostream>
using namespace std;

void swap(int, int);
void SwapByPointer(int*, int*);

int main()
{
	int x = 5, y = 6;
	cout << "Value of x before swap = " << x << endl;
	cout << "Value of y before swap = " << y << endl;
	swap(x,y);
	SwapByPointer(&x, &y);
	cout << "Value of x after swap by pointer = " << x << endl;
	cout << "Value of y after swap by pointer = " << y << endl;
	return 0;
}
void swap(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
	cout << "Value of x after swap = " << x << endl;
	cout << "Value of y after swap = " << y << endl;
}
void SwapByPointer(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
	//cout << "Value of x after swap by pointer = " << *p1 << endl;
	//cout << "Value of y after swap by pointer = " << *p2 << endl;
}
