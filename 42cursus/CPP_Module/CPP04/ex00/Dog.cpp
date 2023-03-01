#include <iostream>
#include "Dog.hpp"

// Constructor & Destructor
Dog::Dog(void)
{
	std::cout << "Dog: Default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& dog)
:Animal(dog)
{
	std::cout << "Dog: Copy constructor called" << std::endl;
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
void	Dog::makeSound(void) const {
	std::cout << type << ": \"Baw-wow!\"\tฅ^•ﻌ•^ฅ"  << std::endl;
}
