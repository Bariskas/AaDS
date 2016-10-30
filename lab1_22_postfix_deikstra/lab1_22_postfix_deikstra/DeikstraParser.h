#pragma once
#include <string>
#include <map>
#include <memory>
#include <iostream>
#include <cmath>
#include "MyStack.h"
#include "MyDeque.h"
using namespace std;

enum arifmeticTokenType
{
	NUMBER,
	OPERATOR, 
	BRACKET,
	UNKNOWN
};

struct Token
{
	Token() : type(UNKNOWN) { token = ""; }
	Token(arifmeticTokenType type, string token) : type(type), token(token) {}

	arifmeticTokenType type;
	string token;
};

class DeikstraParser 
{

public:
	explicit DeikstraParser(const char* input) : input(input) {}
	string parse();
private:
	Token parse_token();
	double calculateResult();
	double performOperation(double arg1, double arg2, string operation);
	const char* input;
	MyDeque<Token> dequeResult;
	MyStack<Token> stackTemp;
	MyStack<double> numberStack;

	map <string, int> priorityMap = { 
		{ "+", 1 },
		{ "-", 1 },
		{ "*", 2 },
		{ "/", 2 },
		{ "^", 3 },
	};
};