#pragma once
#include "stdafx.h"
#include "MyBinTree.h"

class ArifmExpressionConverter
{
public: 
	ArifmExpressionConverter(string expression) : m_expression(expression) {};
	void Convert();
private:
	string m_expression;
	vector<string> m_parsedExr;
	MyBinTree<string>* m_tree;

	void ProcessPart(int from, int to);
	int GetCountBracketsFromBegin(int from, int to);
	int GetCountBracketsFromEnd(int from, int to);
	int GetInternalBracketsCount(int from, int to);
};