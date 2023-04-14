#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <bits/stdc++.h>
# include <iostream>
# include <limits>
# include <stdlib.h>
# include <stdio.h>
# include <string>

# include "utils.hpp"

enum e_type {
                noType = -1,
                charType,
                intType,
                floatType,
                doubleType
            };

class ScalarConverter {

    public:

        ScalarConverter ();
        ScalarConverter (std::string const& string);
        ScalarConverter (ScalarConverter const& original);
        ~ScalarConverter ();

        ScalarConverter&    operator= (ScalarConverter const& rhs);

        static void         convert (std::string const& input);
        static int          findType (std::string const& input);

        operator char ();
        operator int ();
        operator float ();
        operator double ();

        class WrongArgument : public std::exception {

            virtual char const*    what () const throw ();
        };
        class InvalidLitteral : public std::exception {

            virtual char const*    what () const throw ();
        };
        class NonDisplayable : public std::exception {

            virtual char const*    what () const throw ();
        };
        class Impossible : public std::exception {

            virtual char const*    what () const throw ();
        };
        class OutOfRangeValue: public std::exception {

            virtual char const*    what () const throw ();
        };
};


# endif