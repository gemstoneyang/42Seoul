#pragma once
#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed {

public:
	Fixed(void);
	Fixed(const Fixed &fixed);
	~Fixed(void);

	Fixed&	operator=(const Fixed &fixed);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int					raw;
	static const int	bit;

};

#endif