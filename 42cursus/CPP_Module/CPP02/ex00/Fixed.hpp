#pragma once
#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed {

public:
	Fixed(void);
	Fixed(const Fixed &fixed);
	Fixed(const int num);
	Fixed(const float num);
	~Fixed(void);

	Fixed&			operator=(const Fixed &fixed);
	std::ostream&	operator<<(std::ostream& os, const Complex& c)

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	int					raw;
	static const int	bit;

};

#endif