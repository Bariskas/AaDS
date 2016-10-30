#include "DeikstraParser.h"

using namespace std;

string DeikstraParser::parse()
{
	Token nextToken(BRACKET, "");
	arifmeticTokenType prevType = BRACKET;
	string prevBracket = "(";

	while (nextToken.type != UNKNOWN && (*input) != '\0')
	{
		nextToken = parse_token();
		auto switch_on = nextToken.type;
		switch (switch_on)
		{
		case NUMBER:
			if (prevType == switch_on)
			{
				throw "Two numbers in a row";
			}

			dequeResult.PushTop(nextToken);
			break;
		case OPERATOR:
			if (prevType == switch_on)
			{
				throw "Two operator in a row";
			}

			if (prevBracket == "(" && nextToken.token == "-")
			{
				dequeResult.PushTop(Token(NUMBER, "0"));
			}

			if (stackTemp.Empty())
			{
				stackTemp.Push(nextToken);
			}
			else if (!stackTemp.Empty() && stackTemp.Top().token == "(")
			{
				stackTemp.Push(nextToken);
			}
			else if (priorityMap[nextToken.token] >= priorityMap[stackTemp.Top().token])
			{
				stackTemp.Push(nextToken);
			}
			else if (priorityMap[nextToken.token] < priorityMap[stackTemp.Top().token])
			{
				while (priorityMap[stackTemp.Top().token] >= priorityMap[nextToken.token] && !stackTemp.Empty())
				{
					dequeResult.PushTop(stackTemp.Pop());
				}
				stackTemp.Push(nextToken);
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

					dequeResult.PushTop(stackTemp.Pop());
				}
				stackTemp.Pop();
			}
			break;
		default:
			break;
		}
		prevType = switch_on;
	}
	while (!stackTemp.Empty())
	{
		if (stackTemp.Top().type == BRACKET)
		{
			throw runtime_error("wrong expression");
		}
		dequeResult.PushTop(stackTemp.Pop());
	}

	cout << calculateResult() << endl;
	return "";
}

double DeikstraParser::calculateResult()
{
	double result;
	Token token;
	while (!dequeResult.Empty())
	{
		token = dequeResult.PopBack();
		if (token.type == OPERATOR)
		{
			double token1 = numberStack.Pop();
			double token2 = numberStack.Pop();
			numberStack.Push(performOperation(token1, token2, token.token));
		}
		else
		{
			numberStack.Push(stod(token.token));
		}
		cout << token.token << " ";
	};
	cout << endl;
	return numberStack.Pop();
}

double DeikstraParser::performOperation(double arg1, double arg2, string operation)
{
	double result;
	switch (operation.c_str()[0])
	{
	case '+':
		result = arg1 + arg2;
		break;
	case '*':
		result = arg1 * arg2;
		break;
	case '-':
		result = arg2 - arg1;
		break;
	case '/':
		result = arg2 / arg1;
		break;
	case '^':
		result = pow(arg2, arg1);
		break;
	default:
		throw invalid_argument("error operation");
		break;
	}
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

	static const std::string tokens[] = { "+", "-", "*", "/", "^", "(", ")" };
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