#include <iostream>
#include "Contact.hpp"

// Constructor
Contact::Contact(void) {}

Contact::Contact(std::string phoneNumber, std::string firstName,
	std::string	lastName, std::string nickName, std::string darkestSecret)
	: phoneNumber(phoneNumber),
	  firstName(firstName),
	  lastName(lastName),
	  nickName(nickName),
	  darkestSecret(darkestSecret) {}

// Getter
std::string	Contact::getPhoneNumber(void) const {
	return phoneNumber;
}

std::string	Contact::getFirstName(void) const {
	return firstName;
}

std::string	Contact::getLastName(void) const {
	return lastName;
}

std::string	Contact::getNickName(void) const {
	return nickName;
}

// Instance Method
void	Contact::printContactInfo(void) const {
	std::cout << "First name : " << getFirstName() << '\n'
			  << "Last name : " << getLastName() << '\n'
			  << "Nick name : " << getNickName() << '\n'
			  << "Phone number : " << getPhoneNumber() << std::endl;
}
