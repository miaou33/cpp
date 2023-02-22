#include "Point.hpp"

bool bsp (Point const a, Point const b, Point const c, Point const point); 

int	main (void)
{
	Point	point (0.5, 0.5);
	Point	a (0, 0);
	Point	b (0, 2);
	Point	c (2, 0);

	std::cout << "a " << a << std::endl;
	std::cout << std::endl;

	std::cout << "b " << b << std::endl;
	std::cout << std::endl;

	std::cout << "c " << c << std::endl;
	std::cout << std::endl;

	std::cout << bsp (a, b, c, point) << std::endl;
	std::string isInTriangle = bsp (a, b, c, point) ?
					" is " : " is not ";
	std::cout << point << isInTriangle << "in triangle" << std::endl;
}