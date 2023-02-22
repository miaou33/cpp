#include "Fixed.hpp"

int	main (void)
{
	Fixed a ;
	std::cout << "a = " << a << std::endl;
	std::cout << std::endl;

	Fixed const b (Fixed (5.05f)  * Fixed (2));
	std::cout << "b (Fixed (5.05f) * Fixed (2)) = " << b << std::endl;
	std::cout << std::endl;

	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl ;
	std::cout << std::endl;

	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << std::endl;

	std::cout << "max (a, b) = " << Fixed::max (a, b)  << std::endl;
	std::cout << "min (a, b) = " << Fixed::min (a, b) << std::endl;
	std::cout << std::endl;


	Fixed e (2.0098f);

	std::cout << "e (2) = " << e << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << std::endl;

	std::cout << "e - b = " << e - b << std::endl;
	std::cout << std::endl;
	
	std::cout << "e + b = " << e + b << std::endl;
	std::cout << std::endl;
	
	std::cout << "e * b = " << e * b << std::endl;
	std::cout << std::endl;

	std::cout << "e / b = " << e / b << std::endl;
	std::cout << std::endl;

	Fixed const zero (0);
	std::cout << "e / 0 = " << e / zero;
	std::cout << std::endl;

}