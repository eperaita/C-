#include "Point.hpp"
#include <cmath>
#include <iostream>


Point::Point(void): _x(0), _y(0) {}


Point::~Point(void){}


Point::Point(Point const &point)
{
	*this = point;
}

Point::Point(float const x, float const y): _x(x), _y(y) {}

Point &Point::operator=(Point const &point) //  =
{
    //std::cout << "Assignation operator called" << std::endl;
	*(Fixed*)&this->_x = point.getX();
	*(Fixed*)&this->_y = point.getY();
	return (*this);
}

///////////////////////////

float Point::getX(void) const
{
	return (_x.toFloat());
}
float Point::getY(void) const
{
	return (_y.toFloat());
}




///////////////////////////


float get_area(Point const a, Point const b, Point const c)
{
	//AREA = [ x1(y2 - y3) + x2(y3 - y1) + x3(y1-y2)] / 2
	std::cout << "A:" << a.getX() << " - " <<  a.getY() << std::endl;	
	std::cout << "B:" << b.getX() << " - " << b.getY() << std::endl;	
	std::cout << "C:" << c.getX() << " - " << c.getY() << std::endl;	
	std::cout << "--------------" <<  std::endl;	
	std::cout << "--> ("<< a.getX() << " * (" << b.getY() << " - " << c.getY() << ") + ";	
	std::cout << b.getX() << " * (" << c.getY() << " - " << a.getY() << ") + ";	
	std::cout << c.getX() << " * (" << a.getY() << " - " << b.getY() << ") ) / 2" << std::endl;	
	return (fabs(a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	//std::cout << "TOTAL AREA" << std::endl;	
	Fixed area(get_area(a, b, c));
	/*std::cout << "TOTAL AREA =" << area.toFloat() << std::endl;	
	std::cout << "--------------" <<  std::endl;	
	std::cout << "PAB" << std::endl;	*/
	Fixed PAB(get_area(point, a, b));
	/*std::cout << "PAB =" << PAB.toFloat() << std::endl;	
	std::cout << "--------------" <<  std::endl;	
	std::cout << "PBC" << std::endl;	*/
	Fixed PBC(get_area(point, b, c));
	/*std::cout << "PBC =" << PBC.toFloat() << std::endl;	
	std::cout << "--------------" <<  std::endl;	
	std::cout << "PAC" << std::endl;*/	
	Fixed PAC(get_area(point, a, c));
	/*std::cout << "PAC =" << PAC.toFloat() << std::endl;	
	std::cout << "--------------" <<  std::endl;	*/	

/*	std::cout << "A x= " << a.getX() << "/ y=" << a.getY() << std::endl;	
	std::cout << "Area =" << area.toFloat() << std::endl;	*/
	if (PAB == 0 || PBC == 0 || PAC == 0)
	{
		std::cout << "You are in BORDERLINE!" <<  std::endl;	
		return (false);
	}
	else if (PAB + PBC + PAC == area)
	{
		std::cout << "You are IN!" <<  std::endl;	
		return (true);
	}
	else 
	{
		std::cout << "You are OUT!" <<  std::endl;	
		return (false);
	}	
}


