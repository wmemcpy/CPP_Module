#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	void setContact();
	void printContact() const;
	void displayContact() const;
};

void take_input(const std::string str, std::string &input);

#endif
