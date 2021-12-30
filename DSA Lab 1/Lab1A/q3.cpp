#include<iostream>
using namespace std;

int main()
{
	int i = 5;
	float j = 1.5;
	int* xptr = &i;
	float* yptr = &j;
	cout<<"Value of i is "<<i<<endl;
	cout<<"Value of j is "<<j<<endl;
	cout<<"Address of xptr is "<<xptr<<endl;
	cout<<"Address of yptr is "<<yptr<<endl;
	xptr++;
	yptr++;
	cout<<"Address of xptr is "<<xptr<<endl;
	cout<<"Address of yptr is "<<yptr<<endl;
	xptr--;
	yptr--;
	cout<<"Address of xptr is "<<xptr<<endl;
	cout<<"Address of yptr is "<<yptr<<endl;
	xptr += 3;
	yptr += 4;
	cout<<"Address of xptr is "<<xptr<<endl;
	cout<<"Address of yptr is "<<yptr<<endl;
	return 0;
}
