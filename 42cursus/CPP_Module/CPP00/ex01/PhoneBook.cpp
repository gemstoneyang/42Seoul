#include <iostream>
#include "PhoneBook.hpp"

// Constructor
PhoneBook::PhoneBook(void): contactCount(0) {}

// Private Function


// Instance Method
bool	PhoneBook::addContact(void) {
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

	std::cout << "Enter new contact information" << std::endl;
	std::cout << "First name : ";
	std::getline(std::cin, firstName);
	std::cout << "Last name : ";
	std::getline(std::cin, lastName);
	std::cout << "Nick name : ";
	std::getline(std::cin, nickName);
	std::cout << "Phone number : ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Your darkest secret... : ";
	std::getline(std::cin, darkestSecret);

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
