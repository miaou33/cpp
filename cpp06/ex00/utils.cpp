#include "Multicaster.hpp"

void    announce (std::string const& s) {

    std::cout << s;
}

void    display (char c) {

    if (!isprint (c))
        throw Multicaster::NonDisplayable ();
    std::cout << c << std::endl;
}

void    display (int i) {

    std::cout << i << std::endl;
}

void    display (float f) {

    std::cout << f;
    if (f - (int)f == 0)
       std::cout << ".0";
    std::cout << "f" << std::endl;
}

void    display (double d) {

    std::cout << d;
    if (d - (int)d == 0)
       std::cout << ".0";
    std::cout << std::endl;
}

void    display (std::string const& s) {

    std::cout << s << std::endl;
}

void    displayException (std::exception& e) {

    std::cout << e.what () << std::endl;
}
