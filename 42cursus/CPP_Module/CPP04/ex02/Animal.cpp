#include <iostream>
#include "Animal.hpp"

// Constructor & Destructor
Animal::Animal(void)
:type("Animal")
{
	std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(const Animal& animal) {
	std::cout << "Animal: Copy constructor called" << std::endl;

	this->type = animal.type;
}

Animal::~Animal(void) {
	std::cout << "Animal: Destructor called" << std::endl;
}


// Operator Overloading
Animal& Animal::operator=(const Animal& animal) {
	std::cout << "Animal: Copy assignment operator called" << std::endl;

	this->type = animal.type;

	return *this;
}


// Member Function
const std::string&	Animal::getType(void) const {
	return this->type;
}
