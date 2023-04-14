#include "ScalarConverter.hpp"

int    main (int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: Wrong argument" << std::endl;
        return 1;
    }
    ScalarConverter s;

    s.convert (av [1]);

    return 0;
}