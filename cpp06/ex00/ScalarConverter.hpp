#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <bits/stdc++.h>
# include <iostream>
# include <limits>
# include <stdlib.h>
# include <stdio.h>
# include <string>

class ScalarConverter {

    public:

        ScalarConverter ();
        ScalarConverter (std::string const& string);
        ScalarConverter (ScalarConverter const& original);
        virtual ~ScalarConverter ();

        ScalarConverter&        operator= (ScalarConverter const& rhs);

        std::string const&  getParam () const;
        size_t              getParamLen () const;
        int                 getType () const;
        char                getCharCast () const;
        int                 getIntCast () const;
        double              getDoubleCast () const;
        float               getFloatCast () const;

        void                displayCasts ();
    
        class WrongArgument : public std::exception {

            virtual char const*    what () const throw ();
        };
        class InvalidString : public std::exception {

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


    private:

        enum e_type {
            noType = -1,
            charType,
            intType,
            floatType,
            doubleType
        };

        std::string     _param;
        size_t          _param_len;
        int             _type;
        char            _c;
        int             _i;
        float           _f;
        double          _d;

        void            initCasts ();
        void            findType ();
        void            specialParse ();
        void            digitParse ();

        void            convert ();
        void            toChar ();
        void            toInt ();
        void            toFloat ();
        void            toDouble ();
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