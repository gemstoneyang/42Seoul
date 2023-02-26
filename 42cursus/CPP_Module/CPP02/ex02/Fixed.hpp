#pragma once
#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed {

public:
	Fixed(void);
	Fixed(const Fixed& fixed);
	Fixed(const int num);
	Fixed(const float num);
	~Fixed(void);

	Fixed&	operator=(const Fixed& fixed);
	bool	operator>(const Fixed& fixed);
	bool	operator<(const Fixed& fixed);
	bool	operator>=(const Fixed& fixed);
	bool	operator<=(const Fixed& fixed);
	bool	operator==(const Fixed& fixed);
	bool	operator!=(const Fixed& fixed);

	Fixed	operator+(const Fixed& fixed);
	Fixed	operator-(const Fixed& fixed);
	Fixed	operator*(const Fixed& fixed);
	Fixed	operator/(const Fixed& fixed);

	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	static Fixed&		min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&		max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);

private:
	int					raw;
	static const int	bit;

};

std::ostream&	operator<<(std::ostream& os, const Fixed& c);


#endif