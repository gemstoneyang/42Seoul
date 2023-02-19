#include <iostream>
#include "Dog.hpp"

// Constructor & Destructor
Dog::Dog(void)
:type("Dog")
{
	std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::Dog(const Dog& dog) {
	std::cout << "Dog: Copy constructor called" << std::endl;

	this->type = dog.type;
}

Dog::~Dog(void) {
	std::cout << "Dog: Destructor called" << std::endl;
}


// Operator Overloading
Dog& Dog::operator=(const Dog& dog) {
	std::cout << "Dog: Copy assignment operator called" << std::endl;

	this->type = dog.type;

	return *this;
}


// Member Function
const std::string&	Dog::getType(void) {
	return this->type;
}

void	Dog::makeSound(void) {
	std::cout << "Dog: \"Baw-wow!\""  << std::endl;
}

