#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "LinkedList.h"

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
	if (sourceFile.is_open())
	{
		getline(sourceFile, expression);
		sourceFile.close();
	}
	else
	{
		cout << "Error opening file";
	}

	charStack myStack;
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
					throw 
				}
				postFixExpression += myStack.current();
				myStack.pop();
			}
		}
	}
	return 0;
}

int main()
{
	string userInput("");
	do
	{
		cout << "Enter file name with arifmetic row.\n";
		cin >> userInput;
		process(userInput);
		std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
	}
	while (userInput != "exit");
}