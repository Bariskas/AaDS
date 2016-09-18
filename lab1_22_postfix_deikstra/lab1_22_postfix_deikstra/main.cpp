#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "LinkedList.h"
#include "Parser.h"

using namespace std;

//22. В строке текстового файла  задано  выражение  из  целых
//чисел и операций '+', '-', '*', '/', '^'.Порядок  вычислений
//определяется приоритетом операций и круглыми скобками.Возможен
//одноместный минус в начале  выражения  или  после  открывающей
//скобки.Преобразовать выражение в постфиксную  форму(алгоритм
//	Дейкстры) и вычислить его значение.Показать этапы  выполнения
//	(11).


string deikstraParse(string expression)
{
	charStack myStack;
	string postFixExpression;

	Parser parser(expression.c_str());
	cout << parser.parse().token;
	cout << parser.parse().token;
	cout << parser.parse().token;
	cout << "\n";
	/*
	bool isNumber = false;
	for (char& c : expression)
	{
		if (isdigit(c))
		{
			postFixExpression += c;
			isNumber = true;
		}
		else if (isspace(c) && isdigit)
		{
			postFixExpression += ' ';
		}
		else if (c == '(')
		{
			myStack.push(c);
		}
		else if (c == ')')
		{
			while (myStack.current() != '(')
			{
				if (myStack.empty())
				{
					throw "wrong (\n";
				}
				postFixExpression += myStack.current();
				myStack.pop();
			}
		}
	}
	*/
	return "dummy return";
}

int process(string fileName)
{
	string expression;
	string postFixExpression;

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

	postFixExpression = deikstraParse(expression);

	return 0;
}

int main()
{
	string userInput("");
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
			process(userInput);
		}
	}
	while (userInput != "exit");
}