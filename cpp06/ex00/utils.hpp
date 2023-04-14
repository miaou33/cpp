#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <iostream>

void    special_float_double_parse (std::string const& s);
void    neg_parse (std::string const& s);
bool    float_parse (std::string const& s, size_t s_len);
bool    double_parse (std::string const& s);
bool    int_parse (std::string const& s);

void    announce (std::string const& s);
void    display (char c);
void    display (int i);
void    display (float f);
void    display (double d);
void    display (std::string const& s);
void    display_exception (std::exception& e);

# endif