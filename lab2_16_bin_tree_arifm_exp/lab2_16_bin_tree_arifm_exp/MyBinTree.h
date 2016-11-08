#pragma once
#include "stdafx.h"

template <typename T>
struct TreeNode
{
	TreeNode<T>() : value(), left(nullptr), right(nullptr), parent(nullptr) {};
	TreeNode<T>(T newVal, TreeNode* parent) : value(newVal), left(nullptr), right(nullptr), parent(parent) {};

	T value;
	struct TreeNode *left;
	struct TreeNode *right;
	struct TreeNode *parent;
};

template <typename T>
class MyBinTree
{
public:
	MyBinTree() : m_currentNode(nullptr), m_root(nullptr) {};
	void CreateRoot();
	void AddNode(bool isLeft = true);
	void GoToParent();
	void SetValueToCurrentNode(T value);
	void WriteFromUpToDown(TreeNode<T>* node, int depth = 0);
	void WriteFromDownToUp(TreeNode<T>* node, int depth = 0);
	void WriteFromLeftToRight(TreeNode<T>* node, int depth = 0);
	T GetCurrentValue();
	TreeNode<T>* GetRoot();

private:
	TreeNode<T>* m_currentNode;
	TreeNode<T>* m_root;
};

using namespace std;

template<typename T>
T MyBinTree<T>::GetCurrentValue()
{
	return m_currentNode->value;
}

template<typename T>
void MyBinTree<T>::CreateRoot()
{
	if (m_root == nullptr)
	{
		m_currentNode = new TreeNode<T>();
		m_root = m_currentNode;
	}
	else
	{
		throw logic_error("root already exist");
	}
}

template <typename T>
void MyBinTree<T>::AddNode(bool isLeft = true)
{
	if (m_currentNode == nullptr)
	{
		m_currentNode = new TreeNode<T>();
		m_root = m_currentNode;
	}
	else
	{
		TreeNode<T>* NewNode = new TreeNode<T>();
		NewNode->parent = m_currentNode;
		if (isLeft && m_currentNode->left == nullptr)
		{
			m_currentNode->left = NewNode;
		}
		else if (!isLeft && m_currentNode->right == nullptr)
		{
			m_currentNode->right = NewNode;
		}
		else
		{
			cout << "Can't add new node, cause already created node" << endl;
			delete NewNode;
			return;
		}
		m_currentNode = NewNode;
	}
}

template <typename T>
void MyBinTree<T>::GoToParent()
{
	if (m_currentNode->parent != nullptr)
	{
		m_currentNode = m_currentNode->parent;
	}
	else
	{
		// debug operator to show that we entered in root node
		//cout << "This node is root" << endl;
		return;
	}
}

template <typename T>
void MyBinTree<T>::SetValueToCurrentNode(T value)
{
	m_currentNode->value = value;
}

template <typename T>
void MyBinTree<T>::WriteFromUpToDown(TreeNode<T>* node, int depth = 0)
{
	if (node != nullptr)
	{
		cout << string(depth, '-') << node->value << endl;
		WriteFromUpToDown(node->left, depth + 1);
		WriteFromUpToDown(node->right, depth + 1);
	}
}

template <typename T>
void MyBinTree<T>::WriteFromDownToUp(TreeNode<T>* node, int depth = 0)
{
	if (node != nullptr)
	{
		WriteFromDownToUp(node->left, depth + 1);
		WriteFromDownToUp(node->right, depth + 1);
		cout << string(depth, '-') << node->value << endl;
	}
}

template <typename T>
void MyBinTree<T>::WriteFromLeftToRight(TreeNode<T>* node, int depth = 0)
{
	if (node != nullptr)
	{
		WriteFromLeftToRight(node->left, depth + 1);
		cout << string(depth, '-') << node->value << endl;
		WriteFromLeftToRight(node->right, depth + 1);
	}
}

template <typename T>
TreeNode<T>* MyBinTree<T>::GetRoot()
{
	return m_root;
}