#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "PhoneBook.hpp"

// Constructor
PhoneBook::PhoneBook(void): contactCount(0) {}

// Private Function
std::string	PhoneBook::textFormatting(std::string str) {
	if (str.length() > 10) {
		str[9] = '.';
		return str.substr(0, 10);
	}
	return str;
}

void	PhoneBook::printContactArray(void) {
	std::cout << std::setw(10) << "Index"
			  << "|" << std::setw(10) << "FirstName"
			  << "|" << std::setw(10) << "LastName"
			  << "|" << std::setw(10) << "NickName" << std::endl;

	int	displayNum = 8;
	if (contactCount < 8)
		displayNum = contactCount;
	for (int i = 0; i < displayNum; i++) {
		Contact	contact = contactArray[i];
		std::cout << std::setw(10) << i
			<< "|" << std::setw(10) << textFormatting(contact.getFirstName())
			<< "|" << std::setw(10) << textFormatting(contact.getLastName())
			<< "|" << std::setw(10) << textFormatting(contact.getNickName())
			<< std::endl;
	}
}

int	PhoneBook::getUserInputIndex(void) {
	std::string	str;
	char		*endptr;
	int			index;

	std::cout << "Enter index : " << std::flush;
	std::getline(std::cin, str);
	index = strtol(str.c_str(), &endptr, 10);

	if (std::cin.eof())
		return -1;
	else if (*endptr != '\0' or str.empty() or index < 0 or index >= 8
		or (contactCount < 8 and contactCount <= index)) {
		std::cout << "Error : Invalid index" << std::endl;
		return -1;
	}
	return index;
}

// Instance Method
void	PhoneBook::searchContact(void) {
	if (contactCount == 0)
	{
		std::cout << "Error : No contact in phonebook" << std::endl;
		return;
	}
	printContactArray();

	int	idx = getUserInputIndex();
	if (idx == -1)
		return;
	contactArray[idx].printContactInfo();
}

void	PhoneBook::addContact(void) {
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

	std::cout << "[Enter new contact information]" << std::endl;
	std::cout << "> First name : " << std::flush;
	std::getline(std::cin, firstName);
	if (std::cin.eof())
		return;
	std::cout << "> Last name : " << std::flush;
	std::getline(std::cin, lastName);
	if (std::cin.eof())
		return;
	std::cout << "> Nick name : " << std::flush;
	std::getline(std::cin, nickName);
	if (std::cin.eof())
		return;
	std::cout << "> Phone number : " << std::flush;
	std::getline(std::cin, phoneNumber);
	if (std::cin.eof())
		return;
	std::cout << "> Your darkest secret... : " << std::flush;
	std::getline(std::cin, darkestSecret);
	if (std::cin.eof())
		return;

	if (firstName.empty() or lastName.empty() or nickName.empty()
		or phoneNumber.empty() or darkestSecret.empty())
	{
		std::cout << "Error : Invalid contact field" << std::endl;
		return;
	}

	Contact contact(phoneNumber, firstName, lastName, nickName, darkestSecret);
	int		idx = contactCount % 8;

	contactArray[idx] = contact;
	contactCount++;
	return;
}
