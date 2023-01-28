#include "PhoneBook.hpp"

// Constructor
PhoneBook(void): contactCount(0) {}

// Instance Method
bool	PhoneBook::addContact(void) {
	int	idx = contactCount % 8;
	Contact	contact(idx);

	// make setter
	contact
}