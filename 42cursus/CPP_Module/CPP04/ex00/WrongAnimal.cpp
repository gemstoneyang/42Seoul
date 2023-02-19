#include <iostream>
#include "WrongAnimal.hpp"

// Constructor & Destructor
WrongAnimal::WrongAnimal(void)
:type("WrongAnimal")
{
	std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wrongAnimal) {
	std::cout << "WrongAnimal: Copy constructor called" << std::endl;

	this->type = wrongAnimal.type;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal: Destructor called" << std::endl;
}


// Operator Overloading
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wrongAnimal) {
	std::cout << "WrongAnimal: Copy assignment operator called" << std::endl;

	this->type = wrongAnimal.type;

	return *this;
}


// Member Function
const std::string&	WrongAnimal::getType(void) const {
	return this->type;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal: **WrongAnimal Sound**"  << std::endl;
}
// todo : ㅇㅣ르ㅁ 출출력력으으로 바바꾸꾸기
