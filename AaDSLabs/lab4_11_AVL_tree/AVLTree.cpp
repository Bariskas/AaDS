#include "stdafx.h"
#include "AVLTree.h"

using namespace std;

AVLTree::TreeNode::TreeNode(int key)
	: key(key)
	, height(0)
	, left(nullptr)
	, right(nullptr)
{
}

AVLTree::TreeNode::TreeNode()
	: key(0)
	, height(0)
	, left(nullptr)
	, right(nullptr)
{
}

AVLTree::AVLTree()
	: m_root(nullptr)
{
}

void AVLTree::PrintTree() const
{
	RecurscivePrint(m_root, 0);
}

void AVLTree::Insert(int insertValue)
{
	m_root = RecursiveInsert(insertValue, m_root);
}

int AVLTree::NodeHeight(TreeNode* node)
{
	return (node == nullptr) ? 0 : node->height;
}

void AVLTree::FixHeight(TreeNode*& node)
{
	node->height = NodeHeight(node->left) > NodeHeight(node->right)
		? NodeHeight(node->left) + 1
		: NodeHeight(node->right) + 1;
}

int AVLTree::BalanceFactor(TreeNode* node)
{
	return NodeHeight(node->right) - NodeHeight(node->left);
}

AVLTree::TreeNode* AVLTree::RotateRight(TreeNode*& node)
{
	TreeNode* tempNode = new TreeNode();
	tempNode = node->left;
	node->left = tempNode->right;
	tempNode->right = node;
	FixHeight(node);
	FixHeight(tempNode);
	return tempNode;
}

AVLTree::TreeNode* AVLTree::RotateLeft(TreeNode*& node)
{
	TreeNode* tempNode = new TreeNode();
	tempNode = node->right;
	node->right = tempNode->left;
	tempNode->left = node;
	FixHeight(node);
	FixHeight(tempNode);
	return tempNode;
}

AVLTree::TreeNode * AVLTree::Balance(TreeNode*& node)
{
	FixHeight(node);
	if (BalanceFactor(node) == 2)
	{
		if (BalanceFactor(node->right) < 0)
		{
			node->right = RotateRight(node->right);
		}
		return RotateLeft(node);
	}
	if (BalanceFactor(node) == -2)
	{
		if (BalanceFactor(node->left) > 0)
		{
			node->left = RotateLeft(node->left);
		}
		return RotateRight(node);
	}
	return node;
}

AVLTree::TreeNode * AVLTree::RecursiveInsert(int insertValue, TreeNode*& currentNode)
{
	if (currentNode == nullptr)
	{
		return new TreeNode(insertValue);
	}
	else
	{
		if (insertValue < currentNode->key)
		{
			currentNode->left = RecursiveInsert(insertValue, currentNode->left);
		}
		else if (insertValue > currentNode->key)
		{
			currentNode->right = RecursiveInsert(insertValue, currentNode->right);
		}
		return Balance(currentNode);
	}
}

void AVLTree::RecurscivePrint(TreeNode* node, int depth)
{
	if (node != nullptr)
	{
		RecurscivePrint(node->left, depth + 1);
		string leftMargin(depth, '-');
		cout << leftMargin << node->key << endl;
		RecurscivePrint(node->right, depth + 1);
	}
}


