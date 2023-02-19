#include <iostream>
#include "Dog.hpp"

// Constructor & Destructor
Dog::Dog(void) {
	std::cout << "Dog: Default constructor called" << std::endl;

	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& dog) {
	std::cout << "Dog: Copy constructor called" << std::endl;

	this->type = dog.type;
	this->brain = new Brain(*dog.brain);
}

Dog::~Dog(void) {
	std::cout << "Dog: Destructor called" << std::endl;

	delete brain;
}


// Operator Overloading
Dog& Dog::operator=(const Dog& dog) {
	std::cout << "Dog: Copy assignment operator called" << std::endl;

	this->type = dog.type;

	delete brain;
	Brain*	newBrain = new Brain(*dog.brain);
	this->brain = newBrain;

	return *this;
}


// Member Function
const std::string&	Dog::getType(void) const {
	return this->type;
}

void	Dog::makeSound(void) const {
	std::cout << type << ": \"Baw-wow!\"\tฅ^•ﻌ•^ฅ"  << std::endl;
}

Brain*	Dog::getBrain(void) const {
	return this->brain;
}
