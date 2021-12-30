#pragma once
#include<iostream>
using namespace std;
template<class T>
class Matrix
{
public:
	Matrix()
	{
		matrix = nullptr;
		rows = 0;
		columns = 0;
	}
	Matrix(int rows, int columns)
	{
		this->rows = rows;
		this->columns = columns;
		matrix = new T * [rows];
		for (int index = 0; index < rows; index++)
		{
			matrix[index] = new T[columns];
		}
	}
	Matrix(const Matrix& obj)
	{
		this->rows = obj.rows;
		this->columns = obj.columns;
		matrix = new T * [rows];
		for (int index = 0; index < rows; index++)
		{
			matrix[index] = new T[columns];
		}
		for (int r = 0; r < rows; r++)
		{
			for (int c = 0; c < columns; c++)
			{
				this->matrix[r][c] = obj.matrix[r][c];
			}
		}
	}
	void insertElement(const T& element, int rows, int columns)
	{
		this->matrix[rows][columns] = element;
	}
	Matrix operator+(Matrix const& obj)
	{
		if (obj.rows != this->rows || obj.columns != this->columns)
		{
			cout << "Error!" << endl;
		}
		else
		{
			Matrix temp(rows, columns);
			for (int r = 0; r < this->rows; r++)
			{
				for (int c = 0; c < this->columns; c++)
				{
					temp.matrix[r][c] = this->matrix[r][c] + obj.matrix[r][c];
				}
			}
			return temp;
		}
	}
	void print()
	{
		for (int r = 0; r < this->rows; r++)
		{
			for (int c = 0; c < this->columns; c++)
			{
				cout << matrix[r][c] << " ";
			}
			cout << endl;
		}
	}
	void transpose()
	{
		T** temp = new T * [columns];
		for (int index = 0; index < columns; index++)
		{
			temp[index] = new T[rows];
		}
		for (int r = 0; r < this->columns; r++)
		{
			for (int c = 0; c < this->rows; c++)
			{
				temp[r][c] = matrix[c][r];
			}
		}
		for (int del = 0; del < rows; del++)
		{
			delete matrix[del];
		}
		delete[]matrix;
		matrix = nullptr;
		this->matrix = new T * [columns];
		for (int index = 0; index < columns; index++)
		{
			this->matrix[index] = new T[rows];
		}
		matrix = temp;
		int t = this->rows;
		this->rows = this->columns;
		this->columns = t;
	}
	~Matrix()
	{
		for (int del = 0; del < rows; del++)
		{
			delete matrix[del];
		}
		delete[]matrix;
		matrix = nullptr;
	}
private:
	T** matrix;
	int rows, columns;
};
