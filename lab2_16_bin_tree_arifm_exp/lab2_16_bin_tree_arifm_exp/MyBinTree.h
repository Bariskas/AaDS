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
	void AddNode(bool isLeft);
	void GoToParent();
	void SetValueToCurrentNode(T value);
	void WriteFromUpToDown(TreeNode<T>* node, int depth);
	void WriteFromDownToUp(TreeNode<T>* node, int depth);
	void WriteFromLeftToRight(TreeNode<T>* node, int depth);
	TreeNode<T>* GetRoot();

private:
	TreeNode<T>* m_currentNode;
	TreeNode<T>* m_root;
};