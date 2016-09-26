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
	Token();
	Token(arifmeticTokenType type, string token) : type(type), token(token) {}
	arifmeticTokenType type;
	string token;
};

class DeikstraParser {

public:
	explicit DeikstraParser(const char* input) : input(input) {}
	string parse();
private:
	Token parse_token();
	const char* input;
};

string DeikstraParser::parse()
{
	Token nextToken = parse_token();
	while (nextToken.type != UNKNOWN && (*input) != '\0')
	{
		auto switch_on = nextToken.type;
		switch (switch_on)
		{
		default:
			break;
		}
	}
}

Token DeikstraParser::parse_token()
{
	while (isspace(*input)) ++input;

	if (isdigit(*input)) {
		std::string number;
		while (isdigit(*input) || *input == '.') number.push_back(*input++);
		return Token(NUMBER, number);
	}

	static const std::string tokens[] =	{ "+", "-", "*", "/", "(", ")" };
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