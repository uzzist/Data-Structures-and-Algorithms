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
template<typename k, typename v>
class BST
{
public:
	BST()
	{
		root = nullptr;
	}
	void insertRec(k const key, v const value)
	{
		root = insertRec2(root, key, value);
	}
	TNode<k,v>* insertRec2(TNode<k, v>* current, k const key, v const value)
	{
		if (current == nullptr)
		{
			TNode<k, v>* temp = new TNode<k, v>;
			temp->key = key;
			temp->value = value;
			temp->rightChild = nullptr;
			temp->leftChild = nullptr;
			current = temp;
		}
		if (key < current->key)
		{
			current->leftChild = insertRec2(current->leftChild, key, value);
		}
		else if (key > current->key)
		{
			current->rightChild = insertRec2(current->rightChild, key, value);
		}
		else
		{
			current->key = key;
			current->value = value;
		}
		return current;
	}
	void insert(k const key, v const value)
	{
		TNode<k, v>* temp = new TNode<k, v>;
		temp->key = key;
		temp->value = value;
		temp->rightChild = nullptr;
		temp->leftChild = nullptr;
		TNode<k, v>* current = root;
		TNode<k, v>* rootNode = nullptr;
		if (root == nullptr)
		{
			root = temp;
			return;
		}
		while (current != nullptr)
		{
			rootNode = current;
			if (key < current->key)
			{
				current = current->leftChild;
			}
			else
			{
				current = current->rightChild;
			}
		}
		if (key > rootNode->key)
		{
			rootNode->rightChild = temp;
		}
		else
		{
			rootNode->leftChild = temp;
		}
	}
	void inorderPrintKeysRec()
	{
		inOrder(root);
	}
	void inOrder(TNode<k, v>* current)
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
		stack<TNode<k, v>*> s;
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
	void preOrder(TNode<k, v>* current)
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
		stack<TNode<k, v>*> s;
		s.push(root);
		while (!s.empty())
		{
			TNode<k, v>* n = s.top();
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
	void postOrder(TNode<k, v>* current)
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

		stack<TNode<k, v>*> s1, s2;
		s1.push(root);
		TNode<k, v>* node;

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
	int countNodes(TNode<k, v>* current)
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
			return true;
		}
		if (ancestorNodes(current->rightChild, key) || ancestorNodes(current->leftChild, key))
		{
			cout << current->value << " ";
			return true;
		}
		return false;
	}
	~BST()
	{
		deleteBST(root);
	}
	void deleteBST(TNode<k, v>* current)
	{
		if (current->leftChild != nullptr)
		{
			deleteBST(current->leftChild);
		}
		if (current->rightChild != nullptr)
		{
			deleteBST(current->rightChild);
		}
		delete current;
	}
	bool deleteIterative(v const value)
	{
		
	}
	bool deleteRec(v const value)
	{
		root = deleteRec2(root, value);
		if (root)
		{
			return true;
		}
		return false;
	}
	TNode<k, v>* deleteRec2(TNode<k, v>* current, v const value)
	{
		if (current == nullptr)
		{
			return current;
		}
		if (value < current->value)
		{
			current->leftChild = deleteRec2(current->leftChild, value);
		}
		else if (value > current->value)
		{
			current->rightChild = deleteRec2(current->rightChild, value);
		}
		else
		{
			if (current->leftChild == nullptr)
			{
				TNode<k, v>* temp = current->leftChild;
				delete current;
				return temp;
			}
			else if (current->rightChild == nullptr)
			{
				TNode<k, v>* temp = current->rightChild;
				delete current;
				return temp;
			}
		}
		TNode<k, v>* temp2;
		TNode<k, v>* curr = current->rightChild;
		while (curr && curr->leftChild != nullptr)
		{
			curr = curr->leftChild;
		}
		temp2 = curr;
		current->key = temp2->key;
		current->value = temp2->value;
		current->rightChild = deleteRec2(current->rightChild, temp2->value);
	}
private:
	TNode<k, v>* root;
};

int main()
{
	BST<int, int>obj;
	obj.insert(9,9);
	obj.insert(7,7);
	obj.insert(10,10);
	obj.postorderPrintKeysRec();
	bool del = obj.deleteRec(7);
	if (del)
	{
		cout << "Node has been deleted\n";
	}
	else
	{
		cout << "Node not deleted\n";
	}
	return 0;
}