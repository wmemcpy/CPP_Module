#include "RPN.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: wrong number of arguments." << std::endl;
		return 1;
	}

	RPN calculator;
	try
	{
		std::cout << calculator.evaluate(argv[1]) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
