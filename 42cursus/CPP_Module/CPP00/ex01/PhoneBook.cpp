#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

// Constructor
PhoneBook::PhoneBook(void): contactCount(0) {}

// Private Function
void	PhoneBook::printContactInfo(Contact contact) {
	std::cout << "First name : " << contact.getFirstName() << '\n'
			  << "Last name : " << contact.getLastName() << '\n'
			  << "Nick name : " << contact.getNickName() << '\n'
			  << "Phone number : " << contact.getPhoneNumber() << std::endl;
}

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
	if (contactCount == 0)
		return;

	int	idx = -1;
	std::cout << "Enter index : " << std::flush;
	std::cin >> idx;
	std::cout << idx << std::endl;

	std::cin.ignore(1000, '\n');
	std::cin.clear();
	if (idx < 0 or idx >= 8
		or (contactCount < 8 and contactCount <= idx)
		or (contactCount == 0 and idx == 0)) {
		std::cout << "Invalid index" << std::endl;
		return;
	}
	printContactInfo(contactArray[idx]);
}

// Instance Method
bool	PhoneBook::addContact(void) {
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

	std::cout << "Enter new contact information" << std::endl;
	std::cout << "> First name : " << std::flush;
	std::getline(std::cin, firstName);
	if (std::cin.eof())
		return false;
	std::cout << "> Last name : " << std::flush;
	std::getline(std::cin, lastName);
	if (std::cin.eof())
		return false;
	std::cout << "> Nick name : " << std::flush;
	std::getline(std::cin, nickName);
	if (std::cin.eof())
		return false;
	std::cout << "> Phone number : " << std::flush;
	std::getline(std::cin, phoneNumber);
	if (std::cin.eof())
		return false;
	std::cout << "> Your darkest secret... : " << std::flush;
	std::getline(std::cin, darkestSecret);
	if (std::cin.eof())
		return false;

	if (firstName.empty() or lastName.empty() or nickName.empty()
		or phoneNumber.empty() or darkestSecret.empty())
	{
		std::cout << "Invalid Contact Field" << std::endl;
		return false;
	}

	Contact contact(phoneNumber, firstName, lastName, nickName, darkestSecret);
	int		idx = contactCount % 8;

	contactArray[idx] = contact;
	contactCount++;
	return true;
}
