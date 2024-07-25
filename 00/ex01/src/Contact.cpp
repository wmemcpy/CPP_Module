#include <iostream>
#include <iomanip>
#include "Contact.hpp"

void Contact::setContact()
{
	take_input("Enter first name: ", first_name);
	take_input("Enter last name: ", last_name);
	take_input("Enter nickname: ", nickname);
	take_input("Enter phone number: ", phone_number);
	take_input("Enter darkest secret: ", darkest_secret);
}

static void print_field(const std::string field)
{
	if (field.length() > 10)
		std::cout << field.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << field << "|";
}

void Contact::printContact() const
{
	print_field(first_name);
	print_field(last_name);
	print_field(nickname);
	std::cout << std::endl;
}

void Contact::displayContact() const
{
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
}
