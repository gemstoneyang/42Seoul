#include <iostream>
#include "Cat.hpp"

// Constructor & Destructor
Cat::Cat(void) {
	std::cout << "Cat: Default constructor called" << std::endl;

	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& cat)
:Animal(cat)
{
	std::cout << "Cat: Copy constructor called" << std::endl;

	this->brain = new Brain(*cat.brain);
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
	this->brain = new Brain(*cat.brain);

	return *this;
}


// Member Function
void	Cat::makeSound(void) const {
	std::cout << type << ": \"Meow~\"\t₍˄·͈༝·͈˄₎◞"  << std::endl;
}

Brain*	Cat::getBrain(void) const {
	return this->brain;
}
