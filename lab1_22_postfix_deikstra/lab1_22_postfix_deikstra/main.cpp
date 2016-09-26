#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "DeikstraParser.h"

using namespace std;

//22. В строке текстового файла  задано  выражение  из  целых
//чисел и операций '+', '-', '*', '/', '^'.Порядок  вычислений
//определяется приоритетом операций и круглыми скобками.Возможен
//одноместный минус в начале  выражения  или  после  открывающей
//скобки.Преобразовать выражение в постфиксную  форму(алгоритм
//	Дейкстры) и вычислить его значение.Показать этапы  выполнения
//	(11).

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

	DeikstraParser parser(expression.c_str());
	try
	{
		postFixExpression = parser.parse();
	}
	catch (string i)
	{
		cout << "Error parse" + i << endl;
	}

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
			process(userInput);
		}
	}
	while (userInput != "exit");
}