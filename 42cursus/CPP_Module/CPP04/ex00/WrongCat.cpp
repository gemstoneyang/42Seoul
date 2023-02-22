#include <iostream>
#include "WrongCat.hpp"

// Constructor & Destructor
WrongCat::WrongCat(void)
{
	std::cout << "WrongCat: Default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& wrongCat)
:WrongAnimal(wrongCat)
{
	std::cout << "WrongCat: Copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat: Destructor called" << std::endl;
}


// Operator Overloading
WrongCat& WrongCat::operator=(const WrongCat& wrongCat) {
	std::cout << "WrongCat: Copy assignment operator called" << std::endl;

	this->type = wrongCat.type;

	return *this;
}


// Member Function
const std::string&	WrongCat::getType(void) const{
	return this->type;
}

void	WrongCat::makeSound(void) const {
	std::cout << type << ": \"Wrong Meow~\"\t₍˄·͈༝·͈˄₎◞"  << std::endl;
}
