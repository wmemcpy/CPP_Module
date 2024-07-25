#include <iostream>
#include <limits>
#include <cstdlib>
#include "PhoneBook.hpp"

void take_input(const std::string str, std::string &input)
{
	std::cout << str;
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		exit(EXIT_FAILURE);
	}
}

int main(void)
{
	PhoneBook phonebook;
	std::string command;

	while (true)
	{
		take_input("Enter command (ADD, SEARCH, EXIT): ", command);
		if (command == "EXIT")
			break;
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else
			std::cout << "Invalid command!" << std::endl;
	}
	return (0);
}
