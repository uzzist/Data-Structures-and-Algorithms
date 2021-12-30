#pragma once
class Node
{
public:
	char data;
	Node* next;
	Node* prev;
};

#pragma once
#include<iostream>
using namespace std;
class cString
{
public:
	cString()
	{
		head = nullptr;
	}
	cString(const cString& obj)
	{
		Node* obj_current = obj.head;
		while (obj_current != nullptr)
		{
			Node* temp = new Node;
			temp->data = obj_current->data;
			if (head == nullptr)
			{
				head = temp;
				head->next = nullptr;
				head->prev = nullptr;
			}
			else
			{
				Node* current = head;
				while (current->next != nullptr)
				{
					current = current->next;
				}
				current->next = temp;
				temp->prev = current;
				temp->next = nullptr;
			}
			obj_current = obj_current->next;
		}
	}
	void print()
	{
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->data;
			current = current->next;
		}
		cout << endl;
	}
	void assign_recursion(char* source, int index, int length)
	{
		if (index == length)
		{
			return;
		}
		else
		{
			Node* temp = new Node;
			temp->data = source[index];
			if (head == nullptr)
			{
				head = temp;
				head->next = nullptr;
				head->prev = nullptr;
				index++;
				assign_recursion(source, index, length);
			}
			else
			{
				Node* current = head;
				while (current->next != nullptr)
				{
					current = current->next;
				}
				temp->prev = current;
				current->next = temp;
				temp->next = nullptr;
				index++;
				assign_recursion(source, index, length);
			}
		}
	}
	void assign(char* source)
	{
		if (head != nullptr)
		{
			Node* current = head;
			while (current != nullptr)
			{
				head = head->next;
				delete current;
				current = head;
			}
		}
		int index = 0;
		int length = strlen(source);
		assign_recursion(source, index, length);
	}
	bool palindrome_recusrion(Node* first, Node* last)
	{
		if (first == last)
		{
			return true;
		}
		if (first->data != last->data)
		{
			return false;
		}
		if (first->data == last->data)
		{
			first = first->next;
			last = last->prev;
			return palindrome_recusrion(first, last);
		}
	}
	bool isPalindrome()
	{
		if (head == nullptr)
		{
			return false;
		}
		else
		{
			Node* first = head;
			Node* last = head;
			while (last->next != nullptr)
			{
				last = last->next;
			}
			if (palindrome_recusrion(first, last))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	void append(const cString& obj)
	{
		Node* current = head;
		Node* obj_current = obj.head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		while (obj_current != nullptr)
		{
			Node* temp = new Node;
			temp->data = obj_current->data;
			temp->prev = current;
			current->next = temp;
			current = temp;
			temp->next = nullptr;
			obj_current = obj_current->next;
		}
	}
	void copy_recursion(Node* current, char* destination, int index)
	{
		if (current == nullptr)
		{
			destination[index] = '\0';
			return;
		}
		destination[index] = current->data;
		current = current->next;
		index++;
		return copy_recursion(current, destination, index);
	}
	void copy(char* destination)
	{
		int index = 0;
		copy_recursion(head, destination, index);
	}
	void removeAll(cString const& obj)
	{
		if (head == nullptr)
		{
			cout << "List is empty cannot remove\n";
			return;
		}
		Node* obj_current = obj.head;
		if (obj_current->data == head->data)
		{
			Node* current = head;
			head = head->next;
			delete current;
			head->prev = nullptr;
			current = head;
		}
		else
		{
			while (obj_current != nullptr)
			{
				Node* current = head;
				while (current != nullptr)
				{
					if (obj_current->data == current->data)
					{
						if (current->next == nullptr)
						{
							current->prev->next = nullptr;
							delete current;
							current = nullptr;
						}
						else
						{
							Node* n = current->next;
							Node* p = current->prev;
							n->prev = p;
							p->next = n;
							delete current;
							current = n;
						}
					}
					else
					{
						current = current->next;
					}
				}
				obj_current = obj_current->next;
			}
		}
	}
	~cString()
	{
		Node* current = head;
		while (current != nullptr)
		{
			head = head->next;
			delete current;
			current = head;
		}
		head = nullptr;
		current = nullptr;
	}
private:
	Node* head;
};

void addStrings(cString&, cString&, cString&);

int main()
{
	cString str;
	char pakistan[100] = "pakistan";
	char substr[100] = "ntias";
	char ror[10] = "ror";
	char rol[10] = "rol";
	str.assign(pakistan);
	cString str1(str);
	cString another;
	another.assign(substr);
	str1.removeAll(another);
	char destination[20];
	str1.copy(destination);
	cout << destination << endl;
	cString pal;
	pal.assign(ror);
	cout << pal.isPalindrome() << endl;
	pal.assign(rol);
	cout << pal.isPalindrome() << endl;
	cString result;
	addStrings(pal, str, result);
	result.copy(destination);
	cout << destination << endl;
	return 0;
}
void addStrings(cString& list1, cString& list2, cString& result)
{
	char contents[100];
	list1.copy(contents);
	result.assign(contents);
	result.append(list2);
}