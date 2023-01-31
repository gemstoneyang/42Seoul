#include <iostream>
#include "PhoneBook.hpp"

int	main(void) {
	PhoneBook	phoneBook;
	std::string	command;

	while (!std::cin.eof()) {
		std::cout << "> Enter command (ADD, SEARCH, EXIT)" << std::endl;
		std::getline(std::cin, command);
		if (command == "ADD") {
			phoneBook.addContact();
		}
		else if (command == "SEARCH") {
			phoneBook.searchContact();
		}
		else if (command == "EXIT") {
			std::cout << "Bye!" << std::endl;
			break;
		}
		else if (command == "") {
			continue;
		}
		else {
			std::cout << "Command not found : " << command << std::endl;
		}
	}

	return 0;
}