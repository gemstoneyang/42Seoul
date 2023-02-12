#include <iostream>
#include <cmath>
#include "Fixed.hpp"

// Static variable initialize
const int	Fixed::bit = 8;

// Constructor & Destructor
Fixed::Fixed(void)
:raw(0)
{}

Fixed::Fixed(const Fixed& fixed) {
	this->raw = fixed.getRawBits();
}

Fixed::Fixed(const int num) {
	this->raw = num << Fixed::bit;
}

Fixed::Fixed(const float num) {
	float	fix = num * (1 << Fixed::bit);
	
	this->raw = roundf(fix);
}

Fixed::~Fixed(void) {}

// Operator overload
Fixed&	Fixed::operator=(const Fixed& fixed) {
	this->raw = fixed.getRawBits();
	return *this;
}

bool	Fixed::operator>(const Fixed& fixed) {
	return this->raw > fixed.getRawBits();
}

bool	Fixed::operator<(const Fixed& fixed) {
	return this->raw < fixed.getRawBits();
}

bool	Fixed::operator>=(const Fixed& fixed) {
	return this->raw >= fixed.getRawBits();
}

bool	Fixed::operator<=(const Fixed& fixed) {
	return this->raw <= fixed.getRawBits();
}

bool	Fixed::operator==(const Fixed& fixed) {
	return this->raw == fixed.getRawBits();
}

bool	Fixed::operator!=(const Fixed& fixed) {
	return this->raw != fixed.getRawBits();
}


Fixed	operator+(const Fixed& a, const Fixed& b) {
	Fixed	tmp(a.toFloat() + b.toFloat());

	return tmp;
}

Fixed	operator-(const Fixed& a, const Fixed& b) {
	Fixed	tmp(a.toFloat() - b.toFloat());

	return tmp;
}

Fixed	operator*(const Fixed& a, const Fixed& b) {
	Fixed	tmp(a.toFloat() * b.toFloat());

	return tmp;
}

Fixed	operator/(const Fixed& a, const Fixed& b) {
	Fixed	tmp(a.toFloat() / b.toFloat());

	return tmp;
}


Fixed&	Fixed::operator++(void) {
	++raw;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp = *this;
	++raw;
	return tmp;
}

Fixed&	Fixed::operator--(void) {
	--raw;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp = *this;
	++raw;
	return tmp;
}


// Static member function
Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
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
	float	flt;
	
	flt = static_cast<float>(raw);
	return flt / (1 << Fixed::bit);
}

int		Fixed::toInt(void) const {
	return raw >> 8;
}
