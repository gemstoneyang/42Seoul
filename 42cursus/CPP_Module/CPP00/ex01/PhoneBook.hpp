#pragma once
#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include <cctype>
#include "Contact.hpp"

class PhoneBook {

public:
	PhoneBook(void);
	bool	addContact(void);

private:
	int		contactCount;
	Contact	contactArray[8];

};

#endif