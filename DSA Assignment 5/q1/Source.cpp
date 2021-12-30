//Muhammad Uzair
//L1F18BSCS0311
//DSA Section-H
#pragma once
#include<iostream>
#include <ctime>
using namespace std;
#pragma once
template<class T>
class Node
{
public:
	T data;
	Node<T>* next;
};

#pragma once
#include<iostream>
using namespace std;
template<class T>
class Stack
{
public:
	Stack()
	{
		head = nullptr;
	}
	int size()
	{
		return stack_size + 1;
	}
	bool isEmpty()
	{
		if (head == nullptr)
		{
			return true;
		}
		return false;
	}
	void push(T const& value)
	{
		if (head == nullptr)
		{
			Node<T>* temp = new Node<T>;
			temp->data = value;
			temp->next = nullptr;
			head = temp;
		}
		else
		{
			Node<T>* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			Node<T>* temp = new Node<T>;
			temp->data = value;
			temp->next = nullptr;
			current->next = temp;
		}
		stack_size++;
	}
	T Top()
	{
		T e;
		if (!isEmpty())
		{
			Node<T>* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			e = current->data;
			return e;
		}
		throw("There is not value in stack");
	}
	void pop()
	{
		if (head == nullptr)
		{
			cout << "Stack is empty" << endl;
			return;
		}
		Node<T>* current = head;
		Node<T>* previous = head;
		while (current->next != nullptr)
		{
			previous = current;
			current = current->next;
		}
		delete current;
		current = previous;
		current->next = nullptr;
		stack_size--;
		if (stack_size == -1)
		{
			head = nullptr;
			cout << "Stack is empty" << endl;
			return;
		}
	}
	~Stack()
	{
		Node<T>* current = head;
		while (current != nullptr)
		{
			head = current->next;
			delete current;
			current = head;
		}
	}
private:
	Node<T>* head;
	int stack_size = -1;
};

#pragma once
class RatGame
{
public:
	RatGame();
	RatGame(const int&, const int&);
	void play();
	void printBoard();
	void setRowsCols(const int&, const int&);
	bool isValidMove(const int&, const int&);
	bool Win();
	~RatGame();

private:
	Stack<int> ratR;
	Stack<int> ratC;
	int** board;
	int rows, columns;
	void initiliaze_Board();
};

RatGame::RatGame()
{
	board = nullptr;
	rows = 0;
	columns = 0;
}
RatGame::RatGame(const int& rows, const int& cols)
{
	setRowsCols(rows, cols);
}
RatGame::~RatGame()
{
	for (int counter = 0; counter < rows; counter++)
	{
		delete[] board[counter];
	}
	delete[] board;
}
void RatGame::setRowsCols(const int& rows, const int& cols)
{
	this->rows = rows;
	this->columns = cols;

	board = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		board[i] = new int[columns];
	}
	initiliaze_Board();
}
void RatGame::initiliaze_Board()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			board[i][j] = 1;
		}
	}
	board[0][0] = 0;
	board[rows - 1][columns - 1] = 3; 
	for (int i = 0; i < (rows * columns) / 4; i++)
	{
		bool check = true;
		while (check)
		{
			int row = rand() % rows;
			int col = rand() % columns;

			if (board[row][col] == 1)
			{
				board[row][col] = 2; 
				check = false;
			}
		}
	}
}
void RatGame::play()
{
	bool check = true;
	ratR.push(0);
	ratC.push(0);

	while (check && !Win())
	{
		if (ratC.Top() + 1 < columns && isValidMove(ratR.Top(), ratC.Top() + 1))
		{
			ratR.push(ratR.Top());
			ratC.push(ratC.Top() + 1);
			board[ratR.Top()][ratC.Top()] = 0;
		}
		else if (ratR.Top() + 1 < rows && isValidMove(ratR.Top() + 1, ratC.Top()))
		{
			ratR.push(ratR.Top() + 1);
			ratC.push(ratC.Top());
			board[ratR.Top()][ratC.Top()] = 0;
		}
		else if (ratC.Top() - 1 >= 0 && isValidMove(ratR.Top(), ratC.Top() - 1))
		{
			ratR.push(ratR.Top());
			ratC.push(ratC.Top() - 1);
			board[ratR.Top()][ratC.Top()] = 0;
		}
		else if (ratR.Top() - 1 >= 0 && isValidMove(ratR.Top() - 1, ratC.Top()))
		{
			ratR.push(ratR.Top() - 1);
			ratC.push(ratC.Top());
			board[ratR.Top()][ratC.Top()] = 0;
		}
		else
		{
			board[ratR.Top()][ratC.Top()] = 4;
			ratR.pop();
			ratC.pop();
			if (ratR.isEmpty())
			{
				check = false;
				cout << "Rat failed to reach the destination\n";
			}
		}
	}
	cout << endl << endl;
}
void RatGame::printBoard()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
}
bool RatGame::isValidMove(const int& Rat_R, const int& Rat_C)
{
	if (board[Rat_R][Rat_C] == 1 || board[Rat_R][Rat_C] == 3)
	{
		return true;
	}
	return false;
}
bool RatGame::Win()
{
	if (ratR.Top() == (rows - 1) && ratC.Top() == (columns - 1))
	{
		cout << "The Rat has reached its destination. Win!\n";
		return true;
	}
	return false;
}

int main()
{
	srand(time(NULL));
	RatGame obj;
	obj.setRowsCols(14, 15);
	obj.printBoard();
	obj.play();
	return 0;
}