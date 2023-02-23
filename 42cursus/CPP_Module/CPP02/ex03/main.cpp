#include <iostream>
#include "Point.hpp"

int main( void ) {
	Point	a = Point(0, 0);
	Point	b = Point(4, 0);
	Point	c = Point(0, 4);

	Point	p1 = Point(1.125f, 1);
	Point	p2 = Point(2, 0);

	std::cout << "[ Triangle points ]" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;

	std::cout << "[ Check point]" << std::endl;
	std::cout << "p1: " << p1;
	if (bsp(a, b, c, p1))
		std::cout << " is inside point" << std::endl;
	else
		std::cout << " is outside point" << std::endl;

	std::cout << "p2: " << p2;
	if (bsp(a, b, c, p2))
		std::cout << " is inside point" << std::endl;
	else
		std::cout << " is outside point" << std::endl;

	return 0;
}