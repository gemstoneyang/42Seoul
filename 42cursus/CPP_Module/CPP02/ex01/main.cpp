#include <iostream>
#include <cmath>
#include "Fixed.hpp"

int main( void ) {
	float	a = 7.625f;

	std::cout << a << std::endl;
	a *= 256;
	std::cout << a << std::endl;
	a = roundf(a);
	std::cout << a << std::endl;
	a /= 256;
	std::cout << a << std::endl;

	return 0;
}