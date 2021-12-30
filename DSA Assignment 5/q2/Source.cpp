//Muhammad Uzair
//L1F18BSCS0311
//DSA Section-H
#pragma once
#include <iostream>
#include<fstream>
#include<stack>
using namespace std;

template <class T>
class MinHeap
{
public:
	MinHeap()
	{
		size = 25;
		data = new T[size];
		lastIndex = 0;
	}
	void dequeue()
	{
		if (lastIndex != 0)
		{
			lastIndex--;
			swap(data[lastIndex], data[0]);
			HeapifyDown(0);
		}
	}
	void enqueue(T val)
	{
		data[lastIndex] = val;
		HeapifyUp(lastIndex);
		lastIndex++;
		if (lastIndex == size)
		{
			regrow();
		}
	}
	bool isEmpty()
	{
		if (lastIndex == 0)
		{
			return true;
		}
		return false;
	}
	T* top()
	{
		return data;
	}
	int totalElements()
	{
		return lastIndex;
	}
	~MinHeap()
	{
		delete[] data;
	}
	void HeapifyUp(int current)
	{
		while (current != 0)
		{
			if (data[current].freq < data[(current - 1) / 2].freq)
			{
				swap(data[current], data[(current - 1) / 2]);
			}
			current = (current - 1) / 2;
		}
	}
	void HeapifyDown(int current)
	{
		bool check = true;
		while (check && current < lastIndex)
		{
			if (data[(current * 2) + 1].freq <= data[(current * 2) + 2].freq && (current * 2) + 2 < lastIndex)
			{
				if (data[(current * 2 + 1)].freq < data[current].freq)
				{
					swap(data[current], data[current * 2 + 1]);
				}
				current = current * 2 + 1;
			}
			else if (data[current * 2 + 1].freq > data[(current * 2) + 2].freq && (current * 2) + 2 < lastIndex)
			{
				if (data[((current * 2) + 2)].freq < data[current].freq)
				{
					swap(data[current], data[(current * 2) + 2]);
				}
				current = (current * 2) + 2;
			}
			else if (data[current].freq > data[current * 2 + 1].freq && (current * 2) + 2 >= lastIndex)
			{
				if ((current * 2 + 1) < lastIndex)
				{
					swap(data[current], data[current * 2 + 1]);
				}
				current = current * 2 + 1;
			}
			else
			{
				check = false;
			}
		}
	}
	void regrow()
	{
		T* temp = new T[size * 2];
		for (int counter = 0; counter < size; counter++)
		{
			temp[counter] = data[counter];
		}
		size = size * 2;
		delete[] data;
		data = temp;
	}
private:
	T* data;
	int size;
	int lastIndex;
};

struct HNode
{
	int freq;
	char character;
	HNode* left, *right;
	HNode* parent;
};

class Huffman
{
public:
	Huffman();
	void createHuffman(string const);
	void printHuffman();
	~Huffman();
	void insertInMinHeap(string const, MinHeap<HNode>&);
	void search(HNode*, HNode*&, char, bool&);
	void getCode(HNode*, stack<int>&);
	HNode* copy_data(HNode*);
	void deleteAllNodes(HNode* current);
private:
	HNode* root;
	string fileName;
};

Huffman::Huffman()
{
	root = nullptr;
}
void Huffman::createHuffman(string const filename)
{
	MinHeap<HNode> obj;
	insertInMinHeap(filename, obj);
	if (!obj.isEmpty())
	{
		while (obj.totalElements() != 1)
		{
			HNode* temp = new HNode;
			temp->left = copy_data(obj.top());
			obj.dequeue();
			temp->right = copy_data(obj.top());
			obj.dequeue();
			temp->character = 27;
			temp->freq = temp->left->freq + temp->right->freq;
			temp->parent = nullptr;
			temp->right->parent = temp;
			temp->left->parent = temp;
			obj.enqueue(*temp);
		}
		root = copy_data(obj.top());
	}
}
void Huffman::printHuffman()
{
	ifstream fin(fileName);
	do
	{
		char c;
		int dummy;
		fin.get(c);
		fin >> dummy;
		if (fin)
		{
			HNode* temp = nullptr;
			bool check = true;
			stack<int> code;
			search(root, temp, c, check);
			getCode(temp, code);
			cout << c << ": ";
			while (!code.empty())
			{
				cout << code.top();
				code.pop();
			}
			cout << endl;
			fin.ignore();
		}
	} while (fin);
}
void Huffman::insertInMinHeap(string const fileName, MinHeap<HNode>& obj)
{
	this->fileName = fileName;
	ifstream fin(fileName);
	do
	{
		char ch;
		fin.get(ch);
		if (fin)
		{
			HNode* temp = new HNode;

			temp->character = ch;
			fin >> temp->freq;
			temp->parent = nullptr;
			temp->left = nullptr;
			temp->right = nullptr;
			obj.enqueue(*temp);
			fin.ignore();
		}
	} while (fin);
}
void Huffman::search(HNode* current, HNode*& find, char ch, bool& check)
{
	if (current != nullptr && check == true)
	{
		if (current->character == ch)
		{
			find = current;
		}
		search(current->left, find, ch, check);
		search(current->right, find, ch, check);
	}
}
void Huffman::getCode(HNode* current, stack<int>& code)
{
	while (current != nullptr)
	{
		if (current->parent != nullptr)
		{
			if (current->parent->left == current)
			{
				code.push(0);
			}
			else
			{
				code.push(1);
			}
		}
		current = current->parent;
	}
}
HNode* Huffman::copy_data(HNode* data)
{
	HNode* temp = new HNode;
	temp->character = data->character;
	temp->freq = data->freq;
	temp->right = data->right;
	temp->left = data->left;
	temp->parent = data->parent;
	if (temp->left != nullptr)
	{
		temp->left->parent = temp;
	}
	if (temp->right != nullptr)
	{
		temp->right->parent = temp;
	}
	return temp;
}
void Huffman::deleteAllNodes(HNode* current)
{
	if (current != nullptr)
	{
		deleteAllNodes(current->left);
		deleteAllNodes(current->right);
		delete current;
	}
}
Huffman::~Huffman()
{
	deleteAllNodes(root);
}

int main()
{
	Huffman obj;

	obj.createHuffman("file.txt");
	obj.printHuffman();
}