#include "Point.hpp"

// Constructor & Destructor
Point::Point(void)
:x(0),
 y(0)
{}

Point::Point(const float x, const float y)
:x(x),
 y(y)
{}

Point::Point(const Point& point)
:x(point.getX()),
 y(point.getY())
{}

Point::~Point(void)
{}

// Member function
const Fixed	Point::getX(void) const {
	return this->x;
}

const Fixed	Point::getY(void) const {
	return this->y;
}

// Operator overload
Point&	Point::operator=(const Point& point) {
	const_cast<Fixed&>(this->x) = point.getX();
	const_cast<Fixed&>(this->y) = point.getY();
	return *this;
}

std::ostream&	operator<<(std::ostream& os, const Point& c) {
	os << "x: " << c.getX() << ", y: " << c.getY();
	return os;
}
