#include <iostream>
#include "Cat.hpp"

// Constructor & Destructor
Cat::Cat(void)
{
	std::cout << "Cat: Default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& cat) {
	std::cout << "Cat: Copy constructor called" << std::endl;

	this->type = cat.type;
}

Cat::~Cat(void) {
	std::cout << "Cat: Destructor called" << std::endl;
}


// Operator Overloading
Cat& Cat::operator=(const Cat& cat) {
	std::cout << "Cat: Copy assignment operator called" << std::endl;

	this->type = cat.type;

	return *this;
}


// Member Function
const std::string&	Cat::getType(void) const{
	return this->type;
}

void	Cat::makeSound(void) const {
	std::cout << "Cat: \"Meow~\"\t₍˄·͈༝·͈˄₎◞"  << std::endl;
}

