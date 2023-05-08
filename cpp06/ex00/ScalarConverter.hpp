#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <bits/stdc++.h>
# include <iostream>
# include <limits>
# include <stdlib.h>
# include <stdio.h>
# include <string>

# include "utils.hpp"

class ScalarConverter {

    public:

        /* CONVERSION METHOD */
        static void         convert (std::string const& input);
    
        /* EXCEPTIONS */
        class WrongArgument : public std::exception { virtual char const* what () const throw (); };
        class InvalidLitteral : public std::exception { virtual char const* what () const throw (); };
        class NonDisplayable : public std::exception { virtual char const* what () const throw (); };
        class Impossible : public std::exception { virtual char const* what () const throw (); };
        class OutOfRangeValue : public std::exception { virtual char const* what () const throw (); };

    private:

        ScalarConverter ();
        ScalarConverter (ScalarConverter const& original);
        virtual ~ScalarConverter ();
        ScalarConverter& operator= (ScalarConverter const& rhs);

        enum e_type {
            noType = -1,
            charType,
            intType,
            floatType,
            doubleType
        };

        static std::string        _input;
        static size_t             _input_len;
        static int                _type;
        static char               _c;
        static int                _i;
        static float              _f;
        static double             _d;

        static void               setInput (std::string const& param);
        static void               setInputLen (size_t len);
        static void               setType (int type);
        static void               setChar (char c);
        static void               setInt (int i);
        static void               setFloat (float f);
        static void               setDouble (double d);

        static void               findType ();
        static void               specialParse ();
        static void               digitParse ();

        static void               toChar ();
        static void               toInt ();
        static void               toFloat ();
        static void               toDouble ();
};




# endif
