#include <iostream>
#include "Point.hpp"

int main( void ) {
	Point	a = Point(0, 0);
	Point	b = Point(4, 0);
	Point	c = Point(0, 4);

	Point	p1 = Point(1, 1);
	Point	p2 = Point(2, 0);

	std::cout << bsp(a, b, c, p1) << std::endl;
	std::cout << bsp(a, b, c, p2) << std::endl;

	return 0;
}