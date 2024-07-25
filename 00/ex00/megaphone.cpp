#include <iostream>
#include <locale>

int main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		std::locale loc;
		for (int i = 1; i < argc; ++i)
		{
			const char *argument = argv[i];
			while (*argument)
			{
				std::cout << std::toupper(*argument, loc);
				++argument;
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
