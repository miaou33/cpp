#include "whatever.hpp"

int	main (void)
{
    int a = 2;
    int b = -3;

    std::cout << std::endl;
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

    std::string s1 = "meow";
    std::string s2 = "miaou";

    std::cout << std::endl;
    std::cout << "s1 = " << s1 << std::endl;
    std::cout << "s2 = " << s2 << std::endl;
    std::cout << "min (s1, s2) = " << ::min (s1, s2) << std::endl;
    std::cout << "max (s1, s2) = " << ::max (s1, s2) << std::endl;

    std::cout << "\nswapping s1 and s2 ..." << std::endl;
    ::swap (&s1, &s2);
    std::cout << "s1 = " << s1 << std::endl;
    std::cout << "s2 = " << s2 << std::endl;
    std::cout << "min (s1, s2) = " << ::min (s1, s2) << std::endl;
    std::cout << "max (s1, s2) = " << ::max (s1, s2) << std::endl;
    return 0;
}