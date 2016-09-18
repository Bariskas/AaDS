#pragma once
#include <string>
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
	Token(arifmeticTokenType type, string token) : type(type), token(token) {}
	arifmeticTokenType type;
	string token;
};

class Parser {
public:
	explicit Parser(const char* input) : input(input) {}
	Token parse(); // Основная функция парсинга
private:
	const char* input; // Кусок строки, который еще не распарсили
};

Token Parser::parse()
{
	while (isspace(*input)) ++input;

	if (isdigit(*input)) {
		std::string number;
		while (isdigit(*input) || *input == '.') number.push_back(*input++);
		return Token(NUMBER, number);
	}

	static const std::string tokens[] =
	{ "+", "-", "**", "*", "/", "mod", "abs", "sin", "cos", "(", ")" };
	for (auto& t : tokens) {
		if (std::strncmp(input, t.c_str(), t.size()) == 0) {
			input += t.size();

			if (t == "(" || t == ")")
			{
				return Token(BRACKET, t);
			}
			else
			{
				return Token(OPERATOR, t);
			}
		}
	}

	return Token(UNKNOWN, "");
}