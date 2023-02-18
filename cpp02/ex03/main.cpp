#include "Point.hpp"

bool bsp (Point const a, Point const b, Point const c, Point const point); 

int	main (void)
{
	Point	a;
	Point	b(1.5, 1.2);
	Point	c(b);

	std::cout << a.getX () << std::endl;
	std::cout << a.getY () << std::endl;
	std::cout << b.getX () << std::endl;
	std::cout << b.getY () << std::endl;
	std::cout << c.getX () << std::endl;
	std::cout << c.getY () << std::endl;
	c = a;
	std::cout << c.getX () << std::endl;
	std::cout << c.getY () << std::endl;
	std::cout << a.getX () << std::endl;
	std::cout << a.getY () << std::endl;
}