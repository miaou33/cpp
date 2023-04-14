#include "utils.hpp"

void    display (char c) {

    std::cout << c << std::endl;
}

void    display (int i) {

    std::cout << i << std::endl;
}

void    display (float f) {

    std::cout << f << "f" << std::endl;
}

void    display (double d) {

    std::cout << d << std::endl;
}

void    display (std::string const& s) {

    std::cout << s << std::endl;
}

void    display (std::exception& e) {

    std::cout << e.what () << std::endl;
}
