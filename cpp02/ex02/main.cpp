#include "Fixed.hpp"

int	main (void)
{
	Fixed a;
	Fixed const b( Fixed( 435.05f ) * Fixed( 25435 ) );
	Fixed const c (Fixed (5.05f));
	float d = c.toFloat ();
	Fixed const e (2);

	std::cout << "e = " << e << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "max (a, b) = " << Fixed::max( a, b ) << std::endl;
	std::cout << "min (a, b) = " << Fixed::min (a, b) << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
}