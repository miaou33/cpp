# include "ScalarConverter.hpp"

/******************************************************************************************************/
/*    CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR                                                      */
/******************************************************************************************************/

ScalarConverter::ScalarConverter () {}

ScalarConverter::ScalarConverter (ScalarConverter const& original) { (void) original; }

ScalarConverter::~ScalarConverter () {}

ScalarConverter& ScalarConverter::operator= (ScalarConverter const& rhs) {

    (void) rhs;
    return *this;
}
/******************************************************************************************************/
/*    CONVERT                                                                                         */
/******************************************************************************************************/

void                ScalarConverter::convert (std::string const& input) {

    try {
        int type = findType (input);
        errno = 0;
        switch (_type)
        {
            case charType:
                _c = input [0];
                break;
            case intType:
                _i = atoi (input.c_str ());
                break;
            case floatType:
                _f = std::strtof (input.c_str (), NULL);
                break;
            case doubleType:
                _d = std::strtod (input.c_str (), NULL);
                break;
            default:
                throw InvalidLitteral ();
        }
        errno == ERANGE ?
            throw OutOfRangeValue ()
            : convert ();

    }
    catch (std::exception& e) {
        display_exception (e);
    }
}

int                ScalarConverter::findType (std::string const& input) {

    switch (input.length ())
    {
        case 0:
            return charType;
        case 1:
            return (std::isdigit (input [0]) ? intType : charType);
        default:
            return (input.find_first_not_of ("-0123456789.f") != std::string::npos ?
                specialParse () 
                : digitParse ());
    }
}