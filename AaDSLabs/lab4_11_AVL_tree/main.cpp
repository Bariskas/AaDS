// lab4_11_AVL_tree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "AVLTree.h"

AVLTree* initTree(std::istream& is);

int main()
{
	std::stringstream inputValues("5 10 15 16 4 20 30 40");
	AVLTree* avlTree = initTree(inputValues);
    return 0;
}

AVLTree* initTree(std::istream& is)
{
	auto avlTree = new AVLTree;
	while (!is.eof())
	{
		int nextValue;
		is >> nextValue;
		avlTree->Insert(nextValue);
	}
	avlTree->PrintTree();
	getchar();
	return avlTree;
}

