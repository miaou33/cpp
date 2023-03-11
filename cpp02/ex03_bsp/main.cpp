#include "Point.hpp"

bool bsp (Point const a, Point const b, Point const c, Point const point); 

int	main (void)
{
	Point	a (0, 0);
	Point	b (0, 2);
	Point	c (2, 0);

	std::cout << "Triangle ABC, with: " << std::endl;
	std::cout << "\t\tA " << a << std::endl;
	std::cout << "\t\tB " << b << std::endl;
	std::cout << "\t\tC " << c << std::endl;
	std::cout << std::endl;

	Point	point (0.5, 0.5);
	std::string isInTriangle = bsp (a, b, c, point) ?
					" is " : " is not ";
	std::cout << "point " << point << isInTriangle << "in triangle" << std::endl;

	Point	point1 (3, 3);
	isInTriangle = bsp (a, b, c, point1) ?
					" is " : " is not ";
	std::cout << "point1 " << point1 << isInTriangle << "in triangle" << std::endl;

	Point	point2 (0, 0);
	isInTriangle = bsp (a, b, c, point2) ?
					" is " : " is not ";
	std::cout << "point2 " << point2 << isInTriangle << "in triangle" << std::endl;
}