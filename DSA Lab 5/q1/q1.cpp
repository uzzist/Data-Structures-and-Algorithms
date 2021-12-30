#include<iostream>
using namespace std;

int slowMethod(int);
int fastMethod(int);
void power(int [][2],int);
void multiply(int [][2], int [][2]);

int main()
{
	int n;
	cout<< "Enter number of terms: ";
	cin >> n;
	cout<<"Fibonacci series with slow method: ";
	for(int i = 0; i < n; i++)
	{
		cout << slowMethod(i) << " ";
	}
	cout << "\nFibonacci series with fast method: ";
	for(int i = 0; i < n; i++)
	{
		cout << fastMethod(i) << " ";
	}
	return 0;
}
int slowMethod(int n)
{
	if(n == 1 || n == 0)
	{
		return n;
	}
	else
	{
		return slowMethod(n - 1) + slowMethod(n - 2);
	}
}
int fastMethod(int n)
{
	int arr[2][2] = {{1,1},{1,0}};
	if(n == 0)
	{
		return 0;
	}
	power(arr, n - 1);
	return arr[0][0];
}
void power(int arr[2][2], int x)
{
	if(x == 0 || x == 1)
	{
		return;
	}
	int temp[2][2] = {{1,1},{1,0}};
	power(arr, x / 2);
	multiply(arr, arr);
	if(x % 2 != 0)
	{
		multiply(arr, temp);
	}
}
void multiply(int arr[2][2], int temp[2][2]) 
{
   int a = arr[0][0] * temp[0][0] + arr[0][1] * temp[1][0];
   int b= arr[0][0] * temp[0][1] + arr[0][1] * temp[1][1];
   int c = arr[1][0] * temp[0][0] + arr[1][1] * temp[1][0];
   int d = arr[1][0] * temp[0][1] + arr[1][1] * temp[1][1];
   arr[0][0] = a;
   arr[0][1] = b;
   arr[1][0] = c;
   arr[1][1] = d;
}
