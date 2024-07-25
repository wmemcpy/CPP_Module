#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : current_index(0) {}

void PhoneBook::addContact()
{
	contacts[current_index % MAX_CONTACTS].setContact();
	current_index++;
}

void PhoneBook::searchContact() const
{
	if (current_index == 0)
	{
		std::cout << "No contacts in the phonebook!" << std::endl;
		return;
	}
	std::cout << std::setw(10) << "Index"
			  << "|";
	std::cout << std::setw(10) << "First name"
			  << "|";
	std::cout << std::setw(10) << "Last name"
			  << "|";
	std::cout << std::setw(10) << "Nickname"
			  << "|\n";
	for (int i = 0; i < current_index && i < MAX_CONTACTS; i++)
	{
		std::cout << std::setw(10) << i << "|";
		contacts[i].printContact();
	}
	std::string index;
	take_input("Enter index: ", index);
	if (index.length() == 1 && index[0] >= '0' && index[0] <= '7' && index[0] - '0' < current_index)
		contacts[index[0] - '0'].displayContact();
	else
		std::cout << "Invalid index!" << std::endl;
}
