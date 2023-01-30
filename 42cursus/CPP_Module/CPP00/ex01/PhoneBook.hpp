#pragma once
#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include "Contact.hpp"

class PhoneBook {

public:
	PhoneBook(void);
	bool	addContact(void);
	void	printContactArray(void);

private:
	int		contactCount;
	Contact	contactArray[8];

	void		printContactInfo(Contact contact);
	std::string	textFormatting(std::string str);

};

#endif