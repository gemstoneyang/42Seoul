#include "Contact.hpp"

// Constructor
Contact::Contact(void) {}

Contact::Contact(int idx): index(idx) {}

Contect::Contect(int idx, std:string phoneNumber, std::string firstName,
std::string	lastName, std::string nickName, std::string darkestSecret)
	: index(idx),
	  phoneNumber(phoneNumber),
	  firstName(firstName),
	  lastName(lastName),
	  nickName(nickName),
	  darkestSecret(darkestSecret) {}

// Getter
int	Contect::getIndex(void) {
	return index;
}

std::string	Contect::getPhoneNumber(void) {
	return phoneNumber;
}

std::string	Contect::getFirstName(void) {
	return firstName;
}

std::string	Contect::getLastName(void) {
	return lastName;
}

std::string	Contect::getNickName(void) {
	return nickName;
}
