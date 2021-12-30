#include<iostream>
#include "Matrix.h"
using namespace std;

int main()
{
	Matrix<int> m1(2, 3);
	m1.insertElement(1, 0, 0);
	m1.insertElement(1, 0, 1);
	m1.insertElement(1, 0, 2);
	m1.insertElement(0, 1, 0);
	m1.insertElement(0, 1, 1);
	m1.insertElement(0, 1, 2);
	m1.transpose();
	m1.print();
	Matrix<int> m2(2, 3);
	m2.insertElement(-1, 0, 0);
	m2.insertElement(-1, 0, 1);
	m2.insertElement(-1, 0, 2);
	m2.insertElement(10, 1, 0);
	m2.insertElement(5, 1, 1);
	m2.insertElement(1, 1, 2);
	m2.transpose();
	Matrix<int> m3(m2);
	Matrix<int> m4(m1 + m3);
	m4.transpose();
	m4.print();
	return 0;
}