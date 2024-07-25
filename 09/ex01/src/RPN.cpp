#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <stdexcept>

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
	if (this != &other)
		*this = other;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		*this = other;
	return *this;
}

int RPN::performOperation(int a, int b, char op)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		if (b == 0)
			throw std::runtime_error("Division by zero");
		return a / b;
	default:
		throw std::runtime_error("Unknown operation"); // Should never happen
	}
}

static inline int stringToInt(const std::string &str)
{
	if (str.length() > 1)
		throw std::runtime_error("Invalid number (not a single digit): " + str);
	return str[0] - '0';
}

int RPN::evaluate(const std::string &expression)
{
	std::istringstream iss(expression);
	std::stack<int> stack;
	std::string token;

	while (iss >> token)
	{
		if (isdigit(token[0]))
			stack.push(stringToInt(token));
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (stack.size() < 2)
				throw std::runtime_error("Invalid expression");
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			stack.push(performOperation(a, b, token[0]));
		}
		else
			throw std::runtime_error("Invalid token in expression");
	}

	if (stack.size() != 1)
		throw std::runtime_error("Invalid expression");

	return stack.top();
}
