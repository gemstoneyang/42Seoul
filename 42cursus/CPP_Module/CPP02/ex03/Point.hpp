#pragma once
#ifndef __POINT_HPP__
#define __POINT_HPP__

#include "Fixed.hpp"

class Point {

public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point& point);
	~Point(void);

	Point&	operator=(const Point& point);

	const Fixed	getX(void) const;
	const Fixed	getY(void) const;

private:
	const Fixed	x;
	const Fixed	y;

};

std::ostream&	operator<<(std::ostream& os, const Point& c);

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif