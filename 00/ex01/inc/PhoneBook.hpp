#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook
{
private:
	int current_index;
	Contact contacts[MAX_CONTACTS];

public:
	PhoneBook();
	void addContact();
	void searchContact() const;
};

#endif
