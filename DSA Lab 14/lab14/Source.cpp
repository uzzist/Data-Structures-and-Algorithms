#include<iostream>
#include<fstream>
#include<string>
using namespace std;
template<class v>
struct HashItem
{
	int key;
	v value;
	short status;
};

template<class v>
class HashMap
{
private:
	HashItem<v>* hashArray;
	int capacity;
	int currentElements;
	virtual int getNextCandidateIndex(int key, int i)
	{
		return (key * i) % capacity;
	}
public:
	HashMap()
	{
		capacity = 10;
		hashArray = new HashItem<v>[capacity];
		for (int i = 0; i < 10; i++)
		{
			hashArray[i].status = 0;
		}
		currentElements = 0;
	}
	HashMap(int const capacity)
	{
		if (capacity > 1)
		{
			this->capacity = capacity;
			hashArray = new HashItem<v>[capacity];
			for (int i = 0; i < 10; i++)
			{
				hashArray[i].status = 0;
			}
			currentElements = 0;
		}
		else
		{
			throw("capacity > 1");
		}
	}
	void insert(int const key, v const value)
	{
		if (currentElements / float(capacity) < 0.75)
		{
			int index = key % capacity;
			if (hashArray[index].status != 2)
			{
				hashArray[index].key = key;
				hashArray[index].value = value;
				hashArray[index].status = 2;
			}
			else
			{
				for (int i = 1; i < capacity; i++)
				{
					index = getNextCandidateIndex(key, i);
					if (hashArray[index].status != 2)
					{
						hashArray[index].key = key;
						hashArray[index].value = value;
						hashArray[index].status = 2;
						break;
					}
				}
			}
		}
		else
		{
			doubleCapacity();
			insert(key, value);
		}
	}
	void doubleCapacity()
	{
		capacity *= 2;
		HashItem<v>* temp = new HashItem<v>[capacity];
		for (int i = 0; i < capacity; i++)
		{
			temp[i].status = 0;
		}
		for (int i = 1; i < capacity / 2; i++)
		{
			int index = getNextCandidateIndex(hashArray[i].key, 0);
			if (temp[index].status != 2)
			{
				temp[index].key = hashArray[i].key;
				temp[index].value = hashArray[i].value;
				temp[index].status = 2;
			}
			else
			{
				for (int j = 1; j < capacity; j++)
				{
					index = getNextCandidateIndex(hashArray[i].key, j);
					if (temp[index].status != 2)
					{
						temp[index].key = hashArray[i].key;
						temp[index].value = hashArray[i].value;
						temp[index].status = 2;
						break;
					}
				}
			}
		}
		delete[] hashArray;
		hashArray = temp;
	}
	bool deleteKey(int const key)const
	{
		int index = getNextCandidateIndex(key, 0);
		if (hashArray[index].key == key && hashArray[index].status == 2)
		{
			hashArray[index].status = 1;
			return true;
		}
		else
		{
			for (int i = 1; i < capacity; i++)
			{
				index = getNextCandidateIndex(key, i);
				if (hashArray[index].status != 2)
				{
					return false;
				}
				else if (hashArray[index].key == key && hashArray[index].status == 2)
				{
					hashArray[index].status = 1;
					return true;
				}
			}
		}
	}
	v* get(int const key)
	{
		int index = getNextCandidateIndex(key, 0);
		v* value = nullptr;
		if (hashArray[index].status == 2 && hashArray[index].key == key)
		{
			value = &hashArray[index].value;
		}
		else
		{
			for (int i = 1; i < capacity; i++)
			{
				index = getNextCandidateIndex(key, i);

				if (hashArray[index].status != 2)
				{
					return nullptr;
				}
				else if (hashArray[index].status == 2 && hashArray[index].key == key)
				{
					value = &hashArray[index].value;
					break;
				}
			}
		}
		return value;
	}
	~HashMap()
	{
		delete[] hashArray;
	}
};

template <class v>
class QHashMap : public HashMap<v>
{
private:
	int getNextCandidateIndex(int key, int i)
	{
		return ((key + (i * i)) % this->capacity);
	}
public:
	QHashMap()
	{

	}
	QHashMap(int const capacity) : HashMap<v>::HashMap(capacity)
	{

	}
	~QHashMap()
	{

	}
};

template <class v>
class DHashMap : public HashMap<v>
{
private:
	int getNextCandidateIndex(int key, int i)
	{
		int first_value = key % this->capacity;
		int second_value = 3 - (key % 3);
		return ((first_value + (i * second_value)) % this->capacity);
	}

public:
	DHashMap()
	{

	}
	DHashMap(int const capacity) : HashMap<v>::HashMap(capacity)
	{

	}
	~DHashMap()
	{

	}
};

void populateHash(string, HashMap<string>*);

int main()
{
	HashMap<string>* map;
	map = new HashMap<string>;
	populateHash("students.txt", map);
	cout << *map->get(9);
	map->deleteKey(9);
	/*assert(map->get(9) == nullptr)*/;
	delete map;

	map = new QHashMap<string>;
	populateHash("students.txt", map);
	cout << *map->get(98);
	map->deleteKey(98);
	/*assert(map->get(98) == nullptr)*/;
	delete map;

	map = new DHashMap<string>;
	populateHash("students.txt", map);
	cout << *map->get(101);
	map->deleteKey(101);
	/*assert(map->get(101) == nullptr)*/;
	delete map;

	return 0;
}
void populateHash(string filename, HashMap<string>* hash)
{
	ifstream infile(filename);
	int size = 0;
	int key = 0;
	string str;
	infile >> size;
	for (int counter = 0; counter < size; counter++)
	{
		infile >> key;
		infile >> str;
		hash->insert(key, str);
	}
}