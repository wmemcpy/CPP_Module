#pragma once

#include <string>

class RPN
{
private:
	int performOperation(int a, int b, char op);

public:
	RPN();
	RPN(const RPN &other);
	~RPN();
	RPN &operator=(const RPN &other);

	int evaluate(const std::string &expression);
};

