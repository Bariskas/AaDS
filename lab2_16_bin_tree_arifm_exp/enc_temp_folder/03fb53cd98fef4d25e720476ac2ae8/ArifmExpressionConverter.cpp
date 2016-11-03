#include "stdafx.h"
#include "MyBinTree.h"
#include "ArifmExpressionConverter.h"

using namespace std;

void ArifmExpressionConverter::Convert()
{
	static const vector<string> operators = { "+", "-", "*", "/" };
	vector<string> parsedExr(istream_iterator<string>(stringstream(m_expression)), (istream_iterator<string>()));
	copy(istream_iterator<string>(stringstream(m_expression)), istream_iterator<string>(), back_inserter(m_parsedExr));
	m_tree = new MyBinTree<string>();
	m_tree->CreateRoot();
	copy(parsedExr.begin(), parsedExr.end(), ostream_iterator<string>(cout, ", "));
	ProcessPart(0, m_parsedExr.size() - 1);
	
	m_tree->WriteFromUpToDown(m_tree->GetRoot());

	delete m_tree;
	m_tree = nullptr;
}

void ArifmExpressionConverter::ProcessPart(int from, int to)
{
	bool isOperand = (to - from == 0);
	if (isOperand)
	{
		m_tree->SetValueToCurrentNode(m_parsedExr[from]);
		m_tree->GoToParent();
	}
	else
	{
		auto leftBracketsCount = GetCountBracketsFromBegin(from, to);
		auto rightBracketsCount = GetCountBracketsFromEnd(from, to);
		auto sideBracketsCount = min(leftBracketsCount, rightBracketsCount);
		auto internalBracketsCount = GetInternalBracketsCount(from + sideBracketsCount, to - sideBracketsCount);

		auto unnecessaryBracketsCount = sideBracketsCount + internalBracketsCount;

		auto normilizedBegin = from + unnecessaryBracketsCount;
		auto normilizedEnd = to - unnecessaryBracketsCount;

		bool isOperatorFinded = false;
		int operatorIndex = 0;
		int bracketsCounter = 0;
		for (int i = normilizedEnd; i > normilizedBegin; --i)
		{
			if ((m_parsedExr[i] == "+" || m_parsedExr[i] == "-") && bracketsCounter == 0)
			{
				isOperatorFinded = true;
				operatorIndex = i;
			}
			if (m_parsedExr[i] == "(")
			{
				++bracketsCounter;
			}
			else if (m_parsedExr[i] == ")")
			{
				--bracketsCounter;
			}
		}

		if (!isOperatorFinded)
		{
			bracketsCounter = 0;
			for (int i = to - unnecessaryBracketsCount; i > from + unnecessaryBracketsCount; --i)
			{
				if (m_parsedExr[i] == "*" || m_parsedExr[i] == "/")
				{
					isOperatorFinded = 0;
					operatorIndex = i;
				}
				if (m_parsedExr[i] == "(")
				{
					++bracketsCounter;
				}
				else if (m_parsedExr[i] == ")")
				{
					--bracketsCounter;
				}
			}
		}

		bool isLeft{ true };
		m_tree->SetValueToCurrentNode(m_parsedExr[operatorIndex]);
		m_tree->AddNode(isLeft);
		ProcessPart(normilizedBegin, operatorIndex - 1);
		m_tree->AddNode(!isLeft);
		ProcessPart(operatorIndex + 1, normilizedEnd);
		auto currentValue = m_tree->GetCurrentValue();
		if (!std::all_of(currentValue.begin(), currentValue.end(), ::isdigit))
		{
			m_tree->GoToParent();
		}
	}
}

int ArifmExpressionConverter::GetInternalBracketsCount(int from, int to)
{
	int result{ 0 };
	int currentValue{ 0 };
	for (int i = from; i < to; ++i)
	{
		if (m_parsedExr[i] == "(")
		{
			++currentValue;
		}
		else if (m_parsedExr[i] == ")")
		{
			--currentValue;
			if (currentValue < result)
			{
				result = currentValue;
			}
		}
	}

	return result;
}

int ArifmExpressionConverter::GetCountBracketsFromBegin(int from, int to)
{
	int result{ 0 };
	for (int i = from; i < to; ++i)
	{
		if (m_parsedExr[i] == "(")
		{
			++result;
		}
		else
		{
			break;
		}
	}
	return result;
}

int ArifmExpressionConverter::GetCountBracketsFromEnd(int from, int to)
{
	int result{ 0 };
	for (int i = to; i > from; --i)
	{
		if (m_parsedExr[i] == ")")
		{
			++result;
		}
		else
		{
			break;
		}
	}
	return result;
}