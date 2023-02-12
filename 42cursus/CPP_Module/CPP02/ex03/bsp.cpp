#include "Point.hpp"

static Point	getVector(const Point& start, const Point& end) {
	float	a = (start.getX() - end.getY()).toFloat();
	float	b = (start.getX() - end.getY()).toFloat();

	return Point(a, b);
}

static Fixed	crossProduct(const Point& va, const Point& vb) {
	Fixed res = va.getX() * vb.getY() - va.getY() * vb.getX();
	return res;
}

static bool	isClockWise(Fixed res) {
	return res < Fixed(0);
}

static int	check(const Point& start, const Point& end, const Point& p) {
	Point	v1 = getVector(start, end);
	Point	v2 = getVector(start, p);

	Fixed	res = crossProduct(v1, v2);
	if (res == Fixed(0))
		return 0;
	else if (isClockWise(res))
		return 1;
	return -1;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	int	res = 0;

	res += check(a, b, point);
	res += check(b, c, point);
	res += check(c, a, point);

	if (res == 3 or res == -3)
		return true;
	return false;
}
