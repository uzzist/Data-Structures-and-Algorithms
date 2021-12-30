#include<iostream>
#include<fstream>
#include<string>
using namespace std;
template<typename k, typename v>
class HeapItem
{
public:
	k key;
	v value;
};
template<typename k, typename v>
class MinHeap
{
public:
	MinHeap()
	{
		arr = nullptr;
		capacity = 0;
		totalItems = 0;
	}
	MinHeap(int capacity)
	{
		this->capacity = capacity;
		arr = new HeapItem<k, v>[capacity];
		totalItems = 0;
		for (int i = 0; i < capacity; i++)
		{
			arr[i]->value = -1;
			arr[i]->key = -1;
		}
	}
	~MinHeap()
	{
		delete[]arr;
	}
	bool isEmpty()const
	{
		if (totalItems == 0)
		{
			return true;
		}
		return false;
	}
	void insert(k key, v value)
	{
		totalItems++;
		if (totalItems > capacity)
		{
			capacity *= 2;
			HeapItem<k, v>* temp = new HeapItem<k, v>[capacity];
			for (int i = 1; i < totalItems; i++)
			{
				temp[i]->value = arr[i]->value;
				temp[i]->key = arr[i]->key;
			}
			delete[]arr;
			arr = temp;
		}
		arr[totalItems]->value = value;
		HeapifyUp(totalItems);
	}
	void HeapifyUp(int index)
	{
		if (index && arr[index / 2] < arr[index])
		{
			swap(arr[index]->value, arr[index / 2]->value);
			HeapifyUp(index / 2);
		}
	}
	void getMin(v& value)
	{
		if (isEmpty())
		{
			cout << "Heap is empty cannot assign value\n";
		}
		else
		{
			value = arr[1]->value;
		}
	}
	void deleteMin()
	{
		arr[1]->value = arr[totalItems]->value;
		totalItems--;
		int index = 1;
		HeapifyDown(index);
	}
	void HeapifyDown(int index)
	{
		if (index > capacity)
		{
			return;
		}
		if ((2 * index) < capacity && arr[2 * index] > arr[index])
		{
			swap(arr[index]->value, arr[index * 2]->value);
			HeapifyDown(index * 2);
		}
		if ((2 * index + 1) < capacity && arr[2 * index + 1] > arr[index])
		{
			swap(arr[index]->value, arr[index * 2 + 1]->value);
			HeapifyDown(index * 2 + 1);
		}
	}
	void buildStudentHeap(string filename, MinHeap<int, Student>& stdHeap)
	{
		ifstream fin;
		fin.open(filename);
		int rollNo;
		string sname;
		float scgpa;
		while (fin >> rollNo)
		{
			fin >> sname;
			fin >> scgpa;
			stdHeap.insert(rollNo, rollNo);
		}
		fin.close();
	}
private:
	HeapItem<k, v>* arr;
	int capacity;
	int totalItems;
};

class Student
{
public:
	Student();
	Student(int, string, float);
	void setRollNumber(int);
	void setName(string);
	void setCgpa(float);
	int getRollNumber();
	string getName();
	float getCgpa();
	friend ostream& operator<<(ostream&, const Student&);
private:
	int rollNumber;
	string name;
	float cgpa;
};

Student::Student()
{
	rollNumber = 0;
	name = "";
	cgpa = 0.0;
}
Student::Student(int rollNumber, string name, float cgpa)
{
	setRollNumber(rollNumber);
	setName(name);
	setCgpa(cgpa);
}
void Student::setRollNumber(int rollNumber)
{
	if (rollNumber > 0)
	{
		this->rollNumber = rollNumber;
	}
	else
	{
		this->rollNumber = 0;
	}
}
void Student::setName(string name)
{
	this->name = name;
}
void Student::setCgpa(float cgpa)
{
	if (cgpa >= 0.0)
	{
		this->cgpa = cgpa;
	}
	else
	{
		this->cgpa = 0.0;
	}
}
int Student::getRollNumber()
{
	return rollNumber;
}
string Student::getName()
{
	return name;
}
float Student::getCgpa()
{
	return cgpa;
}
ostream& operator<<(ostream& os, const Student& obj)
{
	os << "Roll Number: " << obj.rollNumber << endl;
	os << "Name: " << obj.name << endl;
	os << "Cgpa: " << obj.cgpa << endl;
	return os;
}

int main()
{
	MinHeap<int, Student> stdHeap;
	stdHeap.buildStudentHeap("students.txt", stdHeap);

	while (!stdHeap.isEmpty())
	{
		Student s;
		stdHeap.getMin(s);
		cout << s << endl << endl;
		stdHeap.deleteMin();
	}

	system("pause");
}