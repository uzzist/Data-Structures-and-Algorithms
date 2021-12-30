#include<iostream>
#include<stack>
using namespace std;
#pragma once
template<typename k, typename v>
class TNode
{
public:
	k key;
	v value;
	TNode<k, v>* leftChild;
	TNode<k, v>* rightChild;
};
#pragma once
template<typename k,typename v>
class BST
{
public:
	BST()
	{
		root = nullptr;
	}
	void insertRec(k const key, v const value)
	{
		if (!root)
		{
			root = new TNode<k, v>;;			
			root->value = value;
			root->key = key;
			root->leftChild = nullptr;
			root->rightChild = nullptr;
		}
		else if(key > root->key)
		{
			insertRight(root->rightChild, key, value);
		}
		else if(key < root->key)
		{
			insertLeft(root->leftChild, key, value);
		}
		else
		{
			root->key = key;
			root->value = value;
		}
	}
	void insertRight(TNode<k, v>* root, k key, v value)
	{
		if (!root)
		{
			root = new TNode<k, v>;
			root->value = value;
			root->key = key;
			root->leftChild = nullptr;
			root->rightChild = nullptr;
		}
		else if (key > root->key)
		{
			insertRight(root->rightChild, key, value);
		}
		else if(key < root->key)
		{
			insertLeft(root->leftChild, key, value);
		}
		else
		{
			root->key = key;
			root->value = value;
		}
	}
	void insertLeft(TNode<k, v>* root, k key, v value)
	{
		if (!root)
		{
			root = new TNode<k, v>;
			root->value = value;
			root->key = key;
			root->leftChild = nullptr;
			root->rightChild = nullptr;
		}
		else if (key > root->key)
		{
			insertRight(root->rightChild, key, value);
		}
		else if(key < root->key)
		{
			insertLeft(root->leftChild, key, value);
		}
		else
		{
			root->key = key;
			root->value = value;
		}
	}
	void insert(k const key, v const value)
	{
		if (!root)
		{
			root = new TNode<k, v>;
			root->key = key;
			root->value = value;
			root->leftChild = nullptr;
			root->rightChild = nullptr;

		}
		else
		{
			TNode<k, v>* current = root;
			TNode<k, v>* temp = new TNode<k, v>;
			temp->key = key;
			temp->value = value;
			temp->rightChild = nullptr;
			temp->leftChild = nullptr;
			int flag = 0;
			while (!current->leftChild || !current->rightChild)
			{
				if (key > current->key)
				{
					current = current->rightChild;
				}
				else if (key < current->key)
				{
					current = current->leftChild;
				}
				else
				{
					current->key = key;
					current->value = value;
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				if (key > current->key)
				{
					current->rightChild = temp;
				}
				else if (key < current->key)
				{
					current->leftChild = temp;
				}
				else
				{
					current->key = key;
					current->value = value;
				}
			}
		}
	}
	v* search(k key)
	{
		if (key == root->key || root == nullptr)
		{
			v temp = root->value;
			return &temp;
		}
		if (key > root->key)
		{
			v* temp = search2(root->rightChild, key);
			return temp;
		}
		if(key < root->key)
		{
			v* temp = search2(root->leftChild, key);
			return temp;
		}
	}
	v* search2(TNode<k, v>* root, k key)
	{
		if (root->key == key || !root)
		{
			return root;
		}
		if (key > root->key)
		{
			return search2(root->rightChild, key);
		}
		if (key < root->key)
		{
			return search2(root->leftChild, key);
		}
	}
	void inorderPrintKeysRec()
	{
		inOrder(root);
	}
	void inOrder(TNode<k,v>* current)
	{
		if (current == nullptr)
		{
			return;
		}
		inOrder(current->leftChild);
		cout << current->value << " ";
		inOrder(current->rightChild);
	}
	void inorderPrintKeys()
	{
		TNode<k, v>* current = root;
		if (current == nullptr)
		{
			return;
		}
		stack<TNode<k,v>*> s;
		while (current != nullptr && !s.empty())
		{
			while (current != nullptr)
			{
				s.push(current);
				current = current->leftChild;
			}
			current = s.top();
			s.pop();
			cout << current->value << " ";
			current = current->rightChild;
		}
	}
	void preorderPrintKeysRec()
	{
		preOrder(root);
	}
	void preOrder(TNode<k,v>* current)
	{
		if (current)
		{
			cout << current->value << " ";
			preOrder(current->leftChild);
			preOrder(current->rightChild);
		}
	}
	void preorderPrintKeys()
	{
		if (root == nullptr)
		{
			return;
		}
		stack<TNode<k,v>*> s;
		s.push(root);
		while (!s.empty())
		{
			TNode<k,v>* n = s.top();
			cout << n->value << " ";			
			s.pop();
			if (n->rightChild)
			{
				s.push(n->rightChild);
			}
			if (n->leftChild)
			{
				s.push(n->leftChild);
			}
		}
	}
	void postorderPrintKeysRec()
	{
		postOrder(root);
	}
	void postOrder(TNode<k,v>* current)
	{
		if (current)
		{
			postOrder(current->leftChild);
			postOrder(current->rightChild);
			cout << current->value << " ";
		}
	}
	void postorderPrintKeys()
	{
		if (root == NULL)
			return;

		stack<TNode<k,v>*> s1, s2;
		s1.push(root);
		TNode<k,v>* node;

		while (!s1.empty())
		{
			node = s1.top();
			s1.pop();
			s2.push(node);
			if (node->leftChild)
				s1.push(node->leftChild);
			if (node->rightChild)
				s1.push(node->rightChild);
		}
		while (!s2.empty()) {
			node = s2.top();
			s2.pop();
			cout << node->value << " ";
		}
	}
	int length()
	{
		TNode<k, v>* current = root;
		if (current == nullptr)
		{
			return 0;
		}
		int count = countNodes(current);
		return count;
	}
	int countNodes(TNode<k,v>* current)
	{
		static int nodeCount = 0;
		if (current)
		{
			countNodes(current->leftChild);
			nodeCount++;
			countNodes(current->rightChild);
		}
		return nodeCount;
	}
	void printAllAncestors(k const key)
	{
		if (root == nullptr)
		{
			cout << "BST is empty\n";
			return;
		}
		if (root->key == key)
		{
			cout << root->key << endl;
			return;
		}
		ancestorNodes(root, key);
	}
	bool ancestorNodes(TNode<k, v>* current, k const key)
	{
		if (current == nullptr)
		{
			return false;
		}
		if (current->key == key)
		{
			cout << current->value << endl;
			return true;
		}
		if (ancestorNodes(current->rightChild, key) || ancestorNodes(current->leftChild, key))
		{
			cout << current->value << " ";
			return true;
		}
		return false;
	}
private:
	TNode<k,v>* root;
};

int main()
{
	BST<int, int> tree; //the key and value both are of type int 

	tree.insert(500, 500);  
	tree.insertRec(1000, 1000);  
	tree.insert(1, 1);  
	tree.insert(600, 600);  
	tree.insertRec(700, 700);  
	tree.insert(10, 10);  
	tree.insert(30, 30);  
	tree.insertRec(9000, 9000);  
	tree.insert(50000, 50000);  
	tree.insertRec(20, 20);


	cout << "Printing keys using iterative in-order traversal: ";  
	tree.inorderPrintKeys();    
	cout << endl << endl << "Printing keys using recursive in-order traversal: ";  
	tree.inorderPrintKeysRec();                
	cout << endl << endl << "Printing keys using iterative pre-order traversal: ";  
	tree.preorderPrintKeys();    
	cout << endl << endl << "Printing keys using recursive pre-order traversal: ";  
	tree.preorderPrintKeysRec();


	cout << endl << endl << "Printing keys using iterative post-order traversal: ";  
	tree.postorderPrintKeys();
	cout << endl << endl << "Printing keys using recursive post-order traversal: ";  
	tree.postorderPrintKeysRec();



	cout << endl << endl << "Tree Length: " << tree.length() << endl << endl;

	int* val = tree.search(1);

	if (val != nullptr) { cout << "1 found" << endl; }

	val = tree.search(123);

	if (val == nullptr) { cout << "123 not found" << endl; }

	cout << endl << "Printing the keys of ancestor nodes of 20";  
	tree.printAllAncestors(20);

	system("pause");
}