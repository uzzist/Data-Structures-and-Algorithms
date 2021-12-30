#include<iostream>
using namespace std;

int main()
{
	int x = 5, y = 10;
	int* p, *q;
	p = &x;
	q = &y;
	int temp = 0;
	temp = *p;
	*p = *q;
	*q = temp;
	cout << "The address of x and the value of x is " << &x << " " << x <<endl;
	cout << "The value of p and the value of *p is " << p << " " << *p << endl;
	cout << "The address of y and the value of y is " << &y << " " << y << endl;
	cout << "The value of q and the value of *q is " << q << " " << *q << endl;
	cout << "The address of p(not its contents!) " << &p << endl;
	cout << "The address of q(not its contents!) " << &q << endl;
	return 0; 
}
