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
std::string	Contact::getPhoneNumber(void) {
	return phoneNumber;
}

std::string	Contact::getFirstName(void) {
	return firstName;
}

std::string	Contact::getLastName(void) {
	return lastName;
}

std::string	Contact::getNickName(void) {
	return nickName;
}
