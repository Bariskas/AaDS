// lab2_16_bin_tree_arifm_exp.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "MyBinTree.h"

using namespace std;

int process(string fileName)
{
	string expression;

	ifstream sourceFile(fileName);
	if (!sourceFile.is_open())
	{
		cout << "Failed to open " << fileName << " for writing\n";
		return 1;
	}

	getline(sourceFile, expression);
	sourceFile.close();

	if (expression.empty())
	{
		cout << "Empty string in a first row\n";
		return 1;
	}

	static const vector<string> operators = { "+", "-", "*", "/" };
	vector<string> inputVector(istream_iterator<string>(stringstream(expression)), (istream_iterator<string>()));
	MyBinTree<string>* tree = new MyBinTree<string>();
	auto isLeft = true;
	tree->AddNode(isLeft);
	for (size_t i = 0; i < inputVector.size(); i++)
	{
		auto currentToken = inputVector[i];
		if (currentToken == "(")
		{
			tree->AddNode(isLeft);
		}
		else if (currentToken == ")")
		{
			tree->GoToParent();
		}
		else if (std::any_of(operators.begin(), operators.end(), [&](string oper) { return oper == currentToken; }))
		{
			tree->SetValueToCurrentNode(currentToken);
			tree->AddNode(!isLeft);
		}
		else if (std::all_of(currentToken.begin(), currentToken.end(), [](char sym) { return isdigit(sym); }))
		{
			tree->SetValueToCurrentNode(currentToken);
			tree->GoToParent();
		}
		else
		{
			cout << "error input " << endl;
			return 1;
		}

		tree->WriteFromUpToDown(tree->GetRoot());
		cout << endl;
	}


	getchar();
	return 0;
}

int main()
{
	string userInput;
	do
	{
		cout << "Enter file name with first arifmetic row.\n\"exit\" to exit from program\n";
		cin >> userInput;

		std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

		if (userInput == "exit")
		{
			return 0;
		}
		else
		{
			try
			{
				process(userInput);
			}
			catch (const exception& e)
			{
				cout << e.what() << endl;
			}
		}
	} while (true);
    return 0;
}

