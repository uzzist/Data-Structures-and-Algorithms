#pragma once
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template <typename k, typename v>
struct TNode
{
	k key;
	v value;
	TNode<k, v>* leftChild;
	TNode<k, v>* rightChild;
	int height;
};

template <class k, class v>
class BST
{
public:
	BST();
	void insert(k const key, v const value);
	v* search(k key);
	void inorderPrintKeysRec() const;
	void inorderPrintKeys() const;
	void preorderPrintKeysRec() const;
	void preorderPrintKeys() const;
	void postorderPrintKeysRec() const;
	void postorderPrintKeys() const;
	int length() const;
	void printAllAncestors(k const key);
	bool delete_Node(v const data);
	~BST();

protected:
	TNode<k, v>* root;
	void findKey_And_Update(TNode<k, v>*, k key, v value, bool&);
	void search(TNode<k, v>*, k key, v*& val);
	void in_order(TNode<k, v>* current_root) const;
	void pre_order(TNode<k, v>* current_root) const;
	void post_order(TNode<k, v>* current_root) const;
	void length(TNode<k, v>* current_root, int& count) const;
	TNode<k, v>* find_Node(v data);
	TNode<k, v>* find_Previous_Node(v data);
	void deleteAll(TNode<k, v>*);
};

template <class k, class v>
BST<k, v>::BST()
{
	root = nullptr;
}
template <class k, class v>
void BST<k, v>::findKey_And_Update(TNode<k, v>* current_root, k key, v value, bool& check)
{
	if (!check && current_root)
	{
		if (current_root->key == key)
		{
			check = true;
			current_root->value = value;
		}
		else
		{
			findKey_And_Update(current_root->leftChild, key, value, check);
			findKey_And_Update(current_root->rightChild, key, value, check);
		}
	}
}

template <class k, class v>
void BST<k, v>::insert(k const key, v const value)
{
	bool check = false;

	findKey_And_Update(root, key, value, check);
	if (!check)
	{
		if (root)
		{
			TNode<k, v>* current = root;
			bool check1 = true;

			while (check1)
			{
				if (value < current->value)
				{
					if (current->leftChild)
					{
						current = current->leftChild;
					}
					else
					{
						TNode<k, v>* temp = new TNode<k, v>;
						temp->value = value;
						temp->key = key;
						temp->leftChild = nullptr;
						temp->rightChild = nullptr;
						current->leftChild = temp;
						check1 = false;
					}
				}
				else
				{
					while (check)
					{
						cout << current->key << " ";

						if (value == current->value)
						{
							check = false;
						}

						if (value < current->value)
						{
							if (current->leftChild)
							{
								current = current->leftChild;
							}
						}
						else
						{
							if (current->rightChild)
							{
								current = current->rightChild;
							}
						}
					}					if (current->rightChild)
					{
						current = current->rightChild;
					}
					else
					{
						TNode<k, v>* temp = new TNode<k, v>;
						temp->value = value;
						temp->key = key;
						temp->leftChild = nullptr;
						temp->rightChild = nullptr;
						current->rightChild = temp;
						check1 = false;
					}
				}
			}
		}
		else
		{
			root = new TNode<k, v>;
			root->value = value;
			root->key = key;
			root->leftChild = nullptr;
			root->rightChild = nullptr;
		}
	}
}

template <class k, class v>
v* BST<k, v>::search(k key)
{
	v* val = nullptr;
	search(root, key, val);
	return val;
}

template <class k, class v>
void BST<k, v>::search(TNode<k, v>* current_root, k key, v*& val)
{
	if (current_root)
	{
		if (current_root->key == key)
		{
			val = &current_root->value;
		}
		search(current_root->leftChild, key, val);
		search(current_root->rightChild, key, val);
	}
}

template <class k, class v>
void BST<k, v>::inorderPrintKeysRec() const
{
	in_order(root);
}

template <class k, class v>
void BST<k, v>::in_order(TNode<k, v>* current_root) const
{
	if (current_root)
	{
		in_order(current_root->leftChild);
		cout << current_root->key << " ";
		in_order(current_root->rightChild);
	}
}

template <class k, class v>
void BST<k, v>::inorderPrintKeys() const
{
	if (root)
	{
		stack<TNode<k, v>*> obj;
		TNode<k, v>* current = root;
		obj.push(current);

		while (!obj.empty())
		{
			if (current)
			{
				obj.push(current);
				current = current->leftChild;
			}
			else
			{
				current = obj.top();
				obj.pop();
				if (!obj.empty())
				{
					cout << current->key << " ";
				}
				current = current->rightChild;
			}
		}
	}
}

template <class k, class v>
void BST<k, v>::preorderPrintKeysRec() const
{
	pre_order(root);
}

template <class k, class v>
void BST<k, v>::pre_order(TNode<k, v>* current_root) const
{
	if (current_root)
	{
		cout << current_root->key << " ";
		pre_order(current_root->leftChild);
		pre_order(current_root->rightChild);
	}
}

template <class k, class v>
void BST<k, v>::preorderPrintKeys() const
{
	if (root)
	{
		stack<TNode<k, v>*> obj;
		TNode<k, v>* current = root;
		obj.push(current);

		while (!obj.empty())
		{
			if (current)
			{
				obj.push(current);
				if (!obj.empty())
				{
					cout << current->key << " ";
				}
				current = current->leftChild;
			}
			else
			{
				current = obj.top();
				obj.pop();
				current = current->rightChild;
			}
		}
	}
}

template <class k, class v>
void BST<k, v>::postorderPrintKeysRec() const
{
	post_order(root);
}

template <class k, class v>
void BST<k, v>::post_order(TNode<k, v>* current_root) const
{
	if (current_root)
	{
		post_order(current_root->leftChild);
		post_order(current_root->rightChild);
		cout << current_root->key << " ";
	}
}

template <class k, class v>
void BST<k, v>::postorderPrintKeys() const
{
	if (root)
	{
		stack<TNode<k, v>*> obj;
		stack<k> keys;
		TNode<k, v>* current = root;
		obj.push(current);

		while (!obj.empty())
		{
			current = obj.top();
			keys.push(current->key);
			obj.pop();

			if (current->leftChild)
			{
				obj.push(current->leftChild);
			}
			if (current->rightChild)
			{
				obj.push(current->rightChild);
			}
		}

		while (!keys.empty())
		{
			cout << keys.top() << " ";
			keys.pop();
		}
	}
}

template <class k, class v>
int BST<k, v>::length() const
{
	int count = 0;
	length(root, count);
	return count;
}

template <class k, class v>
void BST<k, v>::length(TNode<k, v>* current_root, int& count) const
{
	if (current_root)
	{
		count++;
		length(current_root->leftChild, count);
		length(current_root->rightChild, count);
	}
}

template <class k, class v>
void BST<k, v>::printAllAncestors(k const key)
{
	if (root)
	{
		TNode<k, v>* current = root;
		k temp = key;
		v* value = search(temp);

		while (current->key != key)
		{
			cout << current->key << " ";

			if (value && *value < current->value)
			{
				if (current->leftChild)
				{
					current = current->leftChild;
				}
			}
			else
			{
				if (current->rightChild)
				{
					current = current->rightChild;
				}
			}
		}
	}
}

template <class k, class v>
bool BST<k, v>::delete_Node(v const data)
{
	TNode<k, v>* current = find_Node(data);
	TNode<k, v>* previous = find_Previous_Node(data);

	if (current)
	{
		if (current->leftChild && current->rightChild)
		{
			TNode<k, v>* temp = current->rightChild;

			while (temp->leftChild)
			{
				previous = temp;
				temp = temp->leftChild;
			}

			if (temp->rightChild)
			{
				TNode<k, v>* temp_previous = find_Previous_Node(temp->value);

				if (temp_previous->leftChild == temp)
				{
					temp_previous->leftChild = temp->rightChild;
				}
				else
				{
					temp_previous->rightChild = temp->rightChild;
				}
			}
			swap(current->value, temp->value);
			swap(current->key, temp->key);
			current = temp;
		}
		else if (current->leftChild || current->rightChild)
		{
			if (current == root)
			{
				if (current->leftChild)
				{
					root = current->leftChild;
				}
				else
				{
					root = current->rightChild;
				}
			}
			else if (current->leftChild)
			{
				if (previous->leftChild == current)
				{
					previous->leftChild = current->leftChild;
				}
				else
				{
					previous->rightChild = current->leftChild;
				}
			}
			else
			{
				if (previous->leftChild == current)
				{
					previous->leftChild = current->rightChild;
				}
				else
				{
					previous->rightChild = current->rightChild;
				}
			}
		}
		else
		{
			if (current == root)
			{
				root = nullptr;
			}
			else if (previous->leftChild == current)
			{
				previous->leftChild = nullptr;
			}
			else
			{
				previous->rightChild = nullptr;
			}
		}
		delete current;

		return true;
	}
	else
	{
		return false;
	}
}

template <class k, class v>
TNode<k, v>* BST<k, v>::find_Node(v data)
{
	if (root)
	{
		TNode<k, v>* current = root;

		while (current)
		{
			if (current->value == data)
			{
				return current;
			}
			else
			{
				if (data < current->value)
				{
					if (current->leftChild)
					{
						current = current->leftChild;
					}
				}
				else
				{
					if (current->rightChild)
					{
						current = current->rightChild;
					}
				}
			}
		}

		return nullptr;
	}
}

template <class k, class v>
TNode<k, v>* BST<k, v>::find_Previous_Node(v data)
{
	if (root)
	{
		TNode<k, v>* current = root;
		TNode<k, v>* previous = root;

		while (current)
		{
			if (current->value == data)
			{
				if (current == root)
				{
					return nullptr;
				}
				return previous;
			}
			else
			{
				if (data < current->value)
				{
					if (current->leftChild)
					{
						previous = current;
						current = current->leftChild;
					}
				}
				else
				{
					if (current->rightChild)
					{
						previous = current;
						current = current->rightChild;
					}
				}
			}
		}

		return nullptr;
	}
}

template <class k, class v>
void BST<k, v>::deleteAll(TNode<k, v>* current_root)
{
	if (current_root)
	{
		deleteAll(current_root->leftChild);
		deleteAll(current_root->rightChild);
		delete current_root;
	}
}

template <class k, class v>
BST<k, v>::~BST()
{
	deleteAll(root);
}

#pragma once
template <class k, class v>
class AVL : public BST<k, v>
{
public:
	AVL();
	void insert(k const key, v const value);
	bool delete_Node(v const data);
	int height() const;
	~AVL();

private:
	void insert_Node(TNode<k, v>*, TNode<k, v>*);
	void set_Height(TNode<k, v>* current);
	void balancing(TNode<k, v>*);
	int checking_Balance(TNode<k, v>*);
	void left_Rotation(TNode<k, v>*);
	void right_Rotation(TNode<k, v>*);
	void double_Left_Rotation(TNode<k, v>*);
	void double_Right_Rotation(TNode<k, v>*);
	bool check_Double_Left_Rotation(TNode<k, v>*);
	bool check_Double_Right_Rotation(TNode<k, v>*);
	void reset_Heights();
};

template <class k, class v>
AVL<k, v>::AVL()
{
}

template <class k, class v>
void AVL<k, v>::insert(k const key, v const value)
{
	bool check = false;

	this->findKey_And_Update(this->root, key, value, check);
	if (!check)
	{
		TNode<k, v>* temp = new TNode<k, v>;
		temp->value = value;
		temp->key = key;
		temp->leftChild = nullptr;
		temp->rightChild = nullptr;
		temp->height = 1;

		if (this->root)
		{
			insert_Node(this->root, temp);
		}
		else
		{
			this->root = temp;
		}
	}
}

template <class k, class v>
bool AVL<k, v>::delete_Node(v const data)
{
	TNode<k, v>* current = this->find_Node(data);
	TNode<k, v>* previous = this->find_Previous_Node(data);
	TNode<k, v>* edited_Node = nullptr;

	if (current)
	{
		if (current->leftChild && current->rightChild)
		{
			TNode<k, v>* temp = current->rightChild;

			while (temp->leftChild)
			{
				previous = temp;
				temp = temp->leftChild;
			}

			if (temp->rightChild)
			{
				TNode<k, v>* temp_previous = this->find_Previous_Node(temp->value);

				if (temp_previous->leftChild == temp)
				{
					temp_previous->leftChild = temp->rightChild;
				}
				else
				{
					temp_previous->rightChild = temp->rightChild;
				}
			}
			swap(current->value, temp->value);
			swap(current->key, temp->key);
			edited_Node = current;
			current = temp;
		}
		else if (current->leftChild || current->rightChild)
		{
			if (current == this->root)
			{
				if (current->leftChild)
				{
					this->root = current->leftChild;
				}
				else
				{
					this->root = current->rightChild;
				}
				edited_Node = this->root;
			}
			else if (current->leftChild)
			{
				if (previous->leftChild == current)
				{
					previous->leftChild = current->leftChild;
				}
				else
				{
					previous->rightChild = current->leftChild;
				}
				edited_Node = previous;
			}
			else
			{
				if (previous->leftChild == current)
				{
					previous->leftChild = current->rightChild;
				}
				else
				{
					previous->rightChild = current->rightChild;
				}
				edited_Node = previous;
			}
		}
		else
		{
			if (current == this->root)
			{
				this->root = nullptr;
			}
			else if (previous && previous->leftChild == current)
			{
				previous->leftChild = nullptr;
				edited_Node = previous;
			}
			else if (previous && previous->rightChild == current)
			{
				previous->rightChild = nullptr;
				edited_Node = previous;
			}
		}
		delete current;

		reset_Heights();
		while (edited_Node)
		{
			balancing(edited_Node);
			edited_Node = this->find_Previous_Node(edited_Node->value);
		}

		return true;
	}
	else
	{
		return false;
	}
}

template <class k, class v>
int AVL<k, v>::height() const
{
	if (this->root)
	{
		return (this->root->height);
	}
}

template <class k, class v>
void AVL<k, v>::insert_Node(TNode<k, v>* current, TNode<k, v>* node)
{
	if (node->value < current->value)
	{
		if (current->leftChild)
		{
			insert_Node(current->leftChild, node);
		}
		else
		{
			current->leftChild = node;
		}
	}
	else
	{
		if (current->rightChild)
		{
			insert_Node(current->rightChild, node);
		}
		else
		{
			current->rightChild = node;
		}
	}

	set_Height(current);
	balancing(current);
}

template <class k, class v>
void AVL<k, v>::set_Height(TNode<k, v>* current)
{
	if (current->leftChild && current->rightChild)
	{
		if (current->leftChild->height > current->rightChild->height)
		{
			current->height = current->leftChild->height + 1;
		}
		else
		{
			current->height = current->rightChild->height + 1;
		}
	}
	else if (current->leftChild)
	{
		current->height = current->leftChild->height + 1;
	}
	else if (current->rightChild)
	{
		current->height = current->rightChild->height + 1;
	}
	else
	{
		current->height = 1;
	}
}

template <class k, class v>
void AVL<k, v>::balancing(TNode<k, v>* current)
{
	if (current)
	{
		if (checking_Balance(current) < -1)
		{
			if (check_Double_Left_Rotation(current))
			{
				double_Left_Rotation(current);
			}
			else
			{
				left_Rotation(current);
			}
			reset_Heights();
		}
		else if (checking_Balance(current) > 1)
		{
			if (check_Double_Right_Rotation(current))
			{
				double_Right_Rotation(current);
			}
			else
			{
				right_Rotation(current);
			}
			reset_Heights();
		}
	}
}

template <class k, class v>
int AVL<k, v>::checking_Balance(TNode<k, v>* current)
{
	if (current->leftChild && current->rightChild)
	{
		return (current->leftChild->height - current->rightChild->height);
	}
	else if (current->leftChild)
	{
		return (current->leftChild->height);
	}
	else if (current->rightChild)
	{
		return (-1 * current->rightChild->height);
	}
	else
	{
		return 1;
	}
}

template <class k, class v>
void AVL<k, v>::left_Rotation(TNode<k, v>* current)
{
	TNode<k, v>* previous = this->find_Previous_Node(current->value);
	TNode<k, v>* temp = current->rightChild->leftChild;

	if (previous)
	{
		if (previous->leftChild == current)
		{
			previous->leftChild = current->rightChild;
		}
		else
		{
			previous->rightChild = current->rightChild;
		}
	}
	else
	{
		this->root = current->rightChild;
	}


	current->rightChild->leftChild = current;
	current = current->rightChild;
	current->leftChild->rightChild = temp;
}

template <class k, class v>
void AVL<k, v>::right_Rotation(TNode<k, v>* current)
{
	TNode<k, v>* previous = this->find_Previous_Node(current->value);
	TNode<k, v>* temp = current->leftChild->rightChild;

	if (previous)
	{
		if (previous->leftChild == current)
		{
			previous->leftChild = current->leftChild;
		}
		else
		{
			previous->rightChild = current->leftChild;
		}
	}
	else
	{
		this->root = current->leftChild;
	}

	current->leftChild->rightChild = current;
	current = current->leftChild;
	current->rightChild->leftChild = temp;
}

template <class k, class v>
void AVL<k, v>::double_Left_Rotation(TNode<k, v>* current)
{
	TNode<k, v>* previous = this->find_Previous_Node(current->value);
	TNode<k, v>* l_Chlid = current->rightChild->leftChild->leftChild;
	TNode<k, v>* r_Chlid = current->rightChild->leftChild->rightChild;

	if (previous)
	{
		if (previous->leftChild == current)
		{
			previous->leftChild = current->rightChild->leftChild;
		}
		else
		{
			previous->rightChild = current->rightChild->leftChild;
		}
	}
	else
	{
		this->root = current->rightChild->leftChild;
	}

	current->rightChild->leftChild->leftChild = current;
	current->rightChild->leftChild->rightChild = current->rightChild;
	current = current->rightChild->leftChild;
	current->leftChild->rightChild = l_Chlid;
	current->rightChild->leftChild = r_Chlid;
}

template <class k, class v>
void AVL<k, v>::double_Right_Rotation(TNode<k, v>* current)
{
	TNode<k, v>* previous = this->find_Previous_Node(current->value);
	TNode<k, v>* l_Chlid = current->leftChild->rightChild->leftChild;
	TNode<k, v>* r_Chlid = current->leftChild->rightChild->rightChild;

	if (previous)
	{
		if (previous->leftChild == current)
		{
			previous->leftChild = current->leftChild->rightChild;
		}
		else
		{
			previous->rightChild = current->leftChild->rightChild;
		}
	}
	else
	{
		this->root = current->leftChild->rightChild;
	}

	current->leftChild->rightChild->leftChild = current->leftChild;
	current->leftChild->rightChild->rightChild = current;
	current = current->leftChild->rightChild;
	current->leftChild->rightChild = l_Chlid;
	current->rightChild->leftChild = r_Chlid;
}

template <class k, class v>
bool AVL<k, v>::check_Double_Left_Rotation(TNode<k, v>* current)
{
	if (current->rightChild->leftChild && current->rightChild->rightChild)
	{
		if (current->rightChild->leftChild->height <= current->rightChild->rightChild->height)
		{
			return false;
		}
	}
	else if (current->rightChild->rightChild)
	{
		return false;
	}
	return true;
}

template <class k, class v>
bool AVL<k, v>::check_Double_Right_Rotation(TNode<k, v>* current)
{
	if (current->leftChild->leftChild && current->leftChild->rightChild)
	{
		if (current->leftChild->rightChild->height <= current->leftChild->leftChild->height)
		{
			return false;
		}
	}
	else if (current->leftChild->leftChild)
	{
		return false;
	}
	return true;
}

template <class k, class v>
void AVL<k, v>::reset_Heights()
{
	queue<TNode<k, v>*> que;
	stack<TNode<k, v>*> nodes;

	que.emplace(this->root);
	nodes.push(this->root);

	while (!que.empty())
	{
		TNode<k, v>* temp = que.front();

		que.pop();

		if (temp->leftChild)
		{
			que.emplace(temp->leftChild);
			nodes.push(temp->leftChild);
		}
		if (temp->rightChild)
		{
			que.emplace(temp->rightChild);
			nodes.push(temp->rightChild);
		}
	}

	while (!nodes.empty())
	{
		TNode<k, v>* temp = nodes.top();
		nodes.pop();
		set_Height(temp);
	}
}

template <class k, class v>
AVL<k, v>::~AVL()
{
}

int main()
{
	AVL<int, int> tree;

	for (int i = 1; i <= 100; i++)
		tree.insert(i, i);

	for (int i = -1; i >= -100; i--)
		tree.insert(i, i);

	for (int i = 150; i > 100; i--)
		tree.insert(i, i);

	for (int i = -150; i < -100; i++)
		tree.insert(i, i);

	for (int i = 150; i > 100; i--)
		tree.delete_Node(i);


	tree.inorderPrintKeys();
	cout << endl << endl;
	cout << "Tree Height: " << tree.height() << endl;

	int* val = tree.search(-100);

	if (val != nullptr)
	{
		cout << "Key= -100 found" << endl;
	}

	val = tree.search(-151);
	if (val == nullptr)
	{
		cout << "Key= -151 not found" << endl;
	}

	system("pause");
}