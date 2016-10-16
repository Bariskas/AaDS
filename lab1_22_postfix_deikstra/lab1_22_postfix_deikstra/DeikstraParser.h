#pragma once
#include <string>
#include <map>
#include <memory>
#include <iostream>
#include "MyStack.h"
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
	const char* input;
	MyStack<Token> stackResult;
	MyStack<Token> stackTemp;

	map <string, int> priorityMap = { 
		{ "+", 1 },
		{ "-", 1 },
		{ "*", 2 },
		{ "/", 2 },
		{ "^", 3 },
	};
};