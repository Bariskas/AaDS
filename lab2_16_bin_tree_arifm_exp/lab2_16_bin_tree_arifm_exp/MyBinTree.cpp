#include "stdafx.h"
#include "MyBinTree.h"

using namespace std;

template <typename T>
void MyBinTree<T>::AddNode(bool isLeft)
{
	if (currentNode == nullptr)
	{
		TreeNode* currentNode = new Node();
		m_root = currentNode;
	}
	else
	{
		TreeNode* NewNode = new TreeNode();
		NewNode->parent = m_currentNode;
		if (isLeft && m_currentNode->left != nullptr)
		{
			m_currentNode->left = NewNode;
		}
		else if (!isLeft && m_currentNode->right != nullptr)
		{
			m_currentNode->right = NewNode;
		}
		else
		{
			cout << "Can't add new node, cause already created lead" << endl;
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
		cout << "This node is root" << endl;
		return;
	}
}

template <typename T>
void MyBinTree<T>::SetValueToCurrentNode(T value)
{
	m_currentNode = value;
}

template <typename T>
void MyBinTree<T>::WriteFromUpToDown(TreeNode<T>* node, int depth)
{
	if (node != nullptr)
	{
		cout << string(depth, '-') << node->value << endl;
		WriteFromUpToDown(node->left);
		WriteFromUpToDown(node->right);
	}
}

template <typename T>
void MyBinTree<T>::WriteFromDownToUp(TreeNode<T>* node, int depth)
{
	if (node != nullptr)
	{
		WriteFromUpToDown(node->left);
		WriteFromUpToDown(node->right);
		cout << string(depth, '-') << node->value << endl;
	}
}

template <typename T>
void MyBinTree<T>::WriteFromLeftToRight(TreeNode<T>* node, int depth)
{
	if (node != nullptr)
	{
		WriteFromUpToDown(node->left);
		cout << string(depth, '-') << node->value << endl;
		WriteFromUpToDown(node->right);
	}
}

template <typename T>
TreeNode<T>* MyBinTree<T>::GetRoot()
{
	return m_root;
}