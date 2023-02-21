#include "Fixed.hpp"

int	main (void)
{
	Fixed a (-2);
	std::cout << "a = " << a << std::endl;
	Fixed const b (Fixed (5.05f)  * Fixed (2));
	std::cout << "b (Fixed (5.05f) * Fixed (2)) = " << b << std::endl;
	Fixed const c (Fixed (5.05f));
	std::cout << "c (Fixed(5.05f)) = " << c << std::endl;
	float d = c.toFloat ();
	std::cout << "d = c.toFloat () = " << d << std::endl;
	Fixed e (2);
	std::cout << "e (2) = " << e << std::endl;
	Fixed const f (Fixed (5322.432f)  * Fixed (10000.0f));
	std::cout << "f (Fixed (5322.432f)  * Fixed (1000.0f)) = " << f << std::endl;

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

	std::cout << "e - b = " << e - b << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << std::endl;
	
	std::cout << "e + b = " << e + b << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << std::endl;
	
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << std::endl;

	std::cout << "a / b = " << a / b << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << std::endl;
}