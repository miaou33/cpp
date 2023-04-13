#include "whatever.hpp"

int	main (void)
{
    int a = 2;
    int b = -3;

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "min (a, b) = " << ::min (a, b) << std::endl;
    std::cout << "max (a, b) = " << ::max (a, b) << std::endl;

    std::cout << "\nswapping a and b ..." << std::endl;
    ::swap (&a, &b);
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "min (a, b) = " << ::min (a, b) << std::endl;
    std::cout << "max (a, b) = " << ::max (a, b) << std::endl;
    return 0;
}