#include "DeikstraParser.h"

using namespace std;

string DeikstraParser::parse()
{
	Token nextToken(BRACKET, "");
	arifmeticTokenType prevType = BRACKET;
	while (nextToken.type != UNKNOWN && (*input) != '\0')
	{
		nextToken = parse_token();
		auto switch_on = nextToken.type;
		switch (switch_on)
		{
		case NUMBER:
			//result += nextToken.token;
			if (prevType == switch_on)
			{
				throw "Two numbers in a row";
			}

			stackResult.Push(nextToken);
			break;
		case OPERATOR:
			if (prevType == switch_on)
			{
				throw "Two operator in a row";
			}

			if (stackTemp.Empty())
			{
				stackTemp.Push(nextToken);
			}
			else if (!stackTemp.Empty() && stackTemp.Top().token == "(")
			{
				stackTemp.Push(nextToken);
			}
			else if (priorityMap[nextToken.token] > priorityMap[stackTemp.Top().token])
			{
				stackTemp.Push(nextToken);
			}
			else if (priorityMap[nextToken.token] <= priorityMap[stackTemp.Top().token])
			{
				while (priorityMap[stackTemp.Top().token] >= priorityMap[nextToken.token] && !stackTemp.Empty())
				{
					stackResult.Push(stackTemp.Pop());
				}
				stackTemp.Push(stackTemp.Pop());
			}
			break;
		case BRACKET:
			if (nextToken.token == "(")
			{
				stackTemp.Push(nextToken);
			}
			else if (nextToken.token == ")")
			{
				while (stackTemp.Top().token != "(")
				{
					if (stackTemp.Empty())
					{
						throw "Wrong )";
					}

					stackResult.Push(stackTemp.Pop());
				}
			}
			break;
		default:
			break;
		}
		prevType = switch_on;
	}
	while (!stackTemp.Empty())
	{
		stackResult.Push(stackTemp.Pop());
	}

	string result;
	string token;
	while (!stackResult.Empty())
	{
		token = stackResult.Pop().token;
		result += token;
		cout << token << " ";
	};
	return result;
}

Token DeikstraParser::parse_token()
{
	while (isspace(*input)) ++input;

	if (isdigit(*input))
	{
		std::string number;
		while (isdigit(*input))
		{
			number.push_back(*input++);
		}
		return Token(NUMBER, number);
	}

	static const std::string tokens[] = { "+", "-", "*", "/", "(", ")" };
	for (auto& t : tokens)
	{
		if (std::strncmp(input, t.c_str(), t.size()) == 0)
		{
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