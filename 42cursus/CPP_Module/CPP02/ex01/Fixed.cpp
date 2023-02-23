#include <iostream>
#include <cmath>
#include "Fixed.hpp"

// Static variable initialize
const int	Fixed::bit = 8;

// Constructor & Destructor
Fixed::Fixed(void)
:raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) {
	std::cout << "Copy constructor called" << std::endl;
	this->raw = fixed.getRawBits();
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	this->raw = num << Fixed::bit;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;

	float	fix = num * (1 << Fixed::bit);
	
	this->raw = roundf(fix);
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

// Operator overload
Fixed&	Fixed::operator=(const Fixed& fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->raw = fixed.getRawBits();
	return *this;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& c) {
	os << c.toFloat();
	return os;
}

// Member function
int	Fixed::getRawBits(void) const {
	return this->raw;
}

void	Fixed::setRawBits(int const raw) {
	this->raw = raw;
}

float	Fixed::toFloat(void) const {
	float	flt = static_cast<float>(raw);

	return flt / (1 << Fixed::bit);
}

int		Fixed::toInt(void) const {
	return raw >> 8;
}
