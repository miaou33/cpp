#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <iostream>

void    display (char c);
void    display (int i);
void    display (float f);
void    display (double d);
void    display (std::string const& s);
void    display (std::exception& e);

# endif