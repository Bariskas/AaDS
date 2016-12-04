#pragma once

class AVLTree
{
	struct TreeNode
	{
		TreeNode(int key);
		TreeNode();
		int key;
		int height;
		TreeNode* left;
		TreeNode* right;
	};

public:
	AVLTree();
	void PrintTree() const;
	void Insert(int insertValue);
private:
	static int NodeHeight(TreeNode* node);
	static void FixHeight(TreeNode*& node);
	static int BalanceFactor(TreeNode* node);
	static TreeNode * RotateRight(TreeNode*& node);
	static TreeNode * RotateLeft(TreeNode*& node);
	static TreeNode * Balance(TreeNode*& node);
	static TreeNode * RecursiveInsert(int insertValue, TreeNode*& currentNode);
	static void RecurscivePrint(TreeNode* node, int depth);

	TreeNode* m_root;
};	
