#include "Multicaster.hpp"

void    announce (std::string const& s) {

    std::cout << s;
}

void    display (char c) {

    if (!isprint (c))
        throw Multicaster::NonDisplayable ();
    std::cout << "\'" << c << "\'" << std::endl;
}

void    display (int i) {

    std::cout << i << std::endl;
}

void    display (float f) {

    std::cout << std::fixed << std::setprecision (1) << f << "f" << std::endl;
}

void    display (double d) {

    std::cout << std::fixed << std::setprecision (1) << d << std::endl;
}

void    display (std::string const& s) {

    std::cout << s << std::endl;
}

void    display_exception (std::exception& e) {

    std::cout << e.what () << std::endl;
}

void    special_float_double_parse (std::string const& s) {

    static std::string  valid_specials [] = {"nan", "nanf", "inf", "inff", "-inf", "-inff", "+inf", "+inff"}; 
    
    for (size_t i = 0; i < 8; i++)
    {
        if (s == valid_specials [i])
            return;
    }
    throw Multicaster::InvalidString ();
}

void    neg_parse (std::string const& s) {

    size_t    found;

    if (((found = s.find_first_of ('-')) != std::string::npos) 
            && (found != 0 || s.find_last_of ('-') != found))
    {
        throw Multicaster::InvalidString ();
    }
} 

bool    float_parse (std::string const& s, size_t s_len) {

    size_t    found;

    if ((found = s.find_first_of ('f')) != std::string::npos)
    {
        if (found != s_len - 1 || s.find_last_of ('f') != found)
            throw Multicaster::InvalidString ();
        return true;
    }
    return false;
}

bool    double_parse (std::string const& s) {

    size_t    found;

    if ((found = s.find_first_of ('.')) != std::string::npos)
    {
        if (s.find_last_of ('.') != found)
            throw Multicaster::InvalidString ();
        return true;
    }
    return false;
}

bool    int_parse (std::string const& s) {

    char *p;
    long n = std::strtol (s.c_str (), &p, 10);

    if (errno == ERANGE || n < std::numeric_limits<int>::min ()
                        || n > std::numeric_limits<int>::max ())
    {
        throw Multicaster::InvalidString ();
    }
    return true;
}