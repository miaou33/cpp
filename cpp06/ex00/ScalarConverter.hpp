#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <bits/stdc++.h>
# include <iostream>
# include <limits>
# include <stdlib.h>
# include <stdio.h>
# include <string>

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
        ScalarConverter (ScalarConverter const& original);
        virtual ~ScalarConverter ();
        ScalarConverter& operator= (ScalarConverter const& rhs);

        static void         convert (std::string const& input);


        class WrongArgument : public std::exception {

            virtual char const*    what () const throw ();
        };
        class InvalidInput : public std::exception {

            virtual char const*    what () const throw ();
        };
        class NonDisplayable : public std::exception {

            virtual char const*    what () const throw ();
        };
        class OutOfRangeValue: public std::exception {

            virtual char const*    what () const throw ();
        };
    
    private:

        static std::string     _input;
        static size_t          _input_length;
        static const char*     _input_c_str;
        static int             _type;
        static char            _c;
        static int             _i;
        static float           _f;
        static double          _d;

        operator char ();
        operator int ();
        operator float ();
        operator double ();

        static void            displayCasts ();
        static void            initCasts ();
        static void            findType ();
        static void            findScientNotationType (std::string const& input);
        static void            findDigitType (std::string const& input);

        static void            toChar ();
        static void            toInt ();
        static void            toFloat ();
        static void            toDouble ();
};


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