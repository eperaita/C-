#include "Point.hpp"

int main()
{
	Point a( 10, 30);
	Point b( 0, 0);
	Point c( 20, 0);
	Point point( 10, -29.0f);
	bsp(a, b, c, point);
	return 0;
}


