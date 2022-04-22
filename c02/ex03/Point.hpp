#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;

	public:
		Point(void);
		Point(float const x, float const y);
		~Point(void);
		Point(Point const &point);

		Point &operator=(Point const &point);

		float getX(void) const;
		float getY(void) const;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);
float get_area(Point const a, Point const b, Point const c);

#endif
