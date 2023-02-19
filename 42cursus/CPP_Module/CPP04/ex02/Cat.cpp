#include <iostream>
#include "Cat.hpp"

// Constructor & Destructor
Cat::Cat(void) {
	std::cout << "Cat: Default constructor called" << std::endl;

	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& cat) {
	std::cout << "Cat: Copy constructor called" << std::endl;

	this->type = cat.type;

	delete brain;
	Brain*	newBrain(cat.brain);
	this->brain = newBrain;
}

Cat::~Cat(void) {
	std::cout << "Cat: Destructor called" << std::endl;

	delete brain;
}


// Operator Overloading
Cat& Cat::operator=(const Cat& cat) {
	std::cout << "Cat: Copy assignment operator called" << std::endl;

	this->type = cat.type;

	delete brain;
	Brain*	newBrain(cat.brain);
	this->brain = newBrain;

	return *this;
}


// Member Function
const std::string&	Cat::getType(void) const{
	return this->type;
}

void	Cat::makeSound(void) const {
	std::cout << type << ": \"Meow~\"\t₍˄·͈༝·͈˄₎◞"  << std::endl;
}

const Brain*	Cat::getBrain(void) const {
	return this->brain;
}
