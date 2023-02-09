#include <iostream>
#include "Fixed.hpp"

// Static variable initialize
const int	Fixed::bit = 8;

// Constructor & Destructor
Fixed::Fixed(void)
:raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->raw = fixed.getRawBits();
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

// Operator overload
Fixed&	Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->raw = fixed.getRawBits();
	return *this;
}

// Member function
int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return raw;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->raw = raw;
}
