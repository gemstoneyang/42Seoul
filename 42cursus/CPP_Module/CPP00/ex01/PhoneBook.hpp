#pragma once
#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include "Contact.hpp"

class PhoneBook {

public:
	PhoneBook(void);

	void	addContact(void);
	void	searchContact(void);

private:
	int		contactCount;
	Contact	contactArray[8];

	void		printContactArray(void);
	std::string	textFormatting(std::string str);
	int			getUserInputIndex(void);

};

#endif