#include "ScalarConverter.hpp"

int    main (int ac, char **av)
{
    try {
        
        if (ac != 2)
            throw ScalarConverter::WrongArgument ();
        
        ScalarConverter::convert (av [1]);
    }
    
    catch (std::exception& e) {

        display_exception (e); 
        return 1;
    }

    return 0;
}