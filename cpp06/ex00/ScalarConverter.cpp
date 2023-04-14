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
    
std::string     ScalarConverter::_input = "";
size_t          ScalarConverter::_input_len = 0;
int             ScalarConverter::_type = noType;
char            ScalarConverter::_c = 0;
int             ScalarConverter::_i = 0;
double          ScalarConverter::_d = 0.0;
float           ScalarConverter::_f = 0.0f;

/******************************************************************************************************/
/*   SETTERS                                                                                 */
/******************************************************************************************************/

void            ScalarConverter::setInput (std::string const& param) { _input = param; }

void            ScalarConverter::setInputLen (size_t len) { _input_len = len; }

void            ScalarConverter::setType (int type) { _type = type; }

void            ScalarConverter::setChar (char c) { _c = c; }

void            ScalarConverter::setInt (int i) { _i = i; }

void            ScalarConverter::setFloat (float f) { _f = f; }

void            ScalarConverter::setDouble (double d) { _d = d; }

/******************************************************************************************************/
/*    EXCEPTIONS                                                                                      */
/******************************************************************************************************/

char const*     ScalarConverter::WrongArgument::what () const throw () {

    return ("Error: Wrong argument. Format : ./convert <literal>");
}

char const*     ScalarConverter::InvalidLitteral::what () const throw () {

    return ("Error: Invalid string. Please enter a literal thas is either a char, an int, a float or a double");
}

char const*     ScalarConverter::Impossible::what () const throw () {

    return ("Impossible");
}

char const*     ScalarConverter::NonDisplayable::what () const throw () {

    return ("Non displayable");
}

char const*     ScalarConverter::OutOfRangeValue::what () const throw () {

    return ("Error: Out of range value");
}

/******************************************************************************************************/
/*    CONVERT                                                                                         */
/******************************************************************************************************/

void                ScalarConverter::convert (std::string const& input) {

    setInput (input);
    setInputLen (input.length ());

    findType ();
    errno = 0;
    switch (_type)
    {
        case charType:
            setChar(_input [0]);
            break;
        case intType:
            setInt (atoi (_input.c_str ()));
            break;
        case floatType:
            setFloat (std::strtof (_input.c_str (), NULL));
            break;
        case doubleType:
            setDouble (std::strtod (_input.c_str (), NULL));
            break;
        default:
            throw InvalidLitteral ();
    }
    if (errno == ERANGE)
        throw OutOfRangeValue ();
    toChar ();
    toInt ();
    toFloat ();
    toDouble ();
}

void                ScalarConverter::toChar () {

    try {
        announce ("Char: ");
        switch (_type)
        {
            case charType:
                display (_c);
                break;
            case intType:
                isascii (_i) ?
					display (static_cast <char> (_i)) : throw Impossible ();
                break;
            case floatType:
                isascii (static_cast <int> (_f)) ?
					display (static_cast <char> (_f)) : throw Impossible (); 
                break;
            case doubleType:
                isascii (static_cast <int> (_d)) ?
					display (static_cast <char> (_d)) : throw Impossible (); 
                break;
            default:
                throw InvalidLitteral ();
                break;
        }
    }
    catch (std::exception& e) { 
        display_exception (e); 
    }
}

void                ScalarConverter::toInt () {

    try {
        announce ("Int: ");
        switch (_type)
        {
            case charType:
                display (static_cast <int> (_c));
                break;
            case intType:
                display (_i);
                break;
            case floatType:
                (_f >= (float) INT_MIN && _f <= (float) INT_MAX) ?
					display (static_cast <int> (_f)) : throw Impossible ();
                break;
            case doubleType:
                (_d >= (double) INT_MIN && _d <= (double) INT_MAX) ? 
					display (static_cast <int> (_d)) : throw Impossible (); 
                break;
            default:
                throw InvalidLitteral ();
                break;
        }
    }
    catch (std::exception& e) { 
        display_exception (e); 
    }
}

void                ScalarConverter::toFloat () {

    try {
        announce ("Float: ");
        switch (_type)
        {
            case charType:
                display (static_cast <float> (_c)); 
                break;
            case intType:
                display (static_cast <float> (_i)); 
                break;
            case floatType:
                display (_f);
                break;
            case doubleType:
                (_d >= FLT_MIN && _d <= FLT_MAX) ?
                    display (static_cast <float> (_d)) : throw Impossible (); 
                break;
            default:
                throw InvalidLitteral ();
                break;
        }
    }
    catch (std::exception& e) { 
        display_exception (e); 
    }
}

void                ScalarConverter::toDouble () {

    try {
        announce ("Double: ");
        switch (_type)
        {
            case charType:
                display (static_cast <double> (_c)); 
                break;
            case intType:
                display (static_cast <double> (_i)); 
                break;
            case floatType:
                display (static_cast <double> (_f)); 
                break;
            case doubleType:
                display (_d);
                break;
            default:
                throw InvalidLitteral ();
                break;
        }
    }
    catch (std::exception& e) { 
        display_exception (e); 
    }
}

void                ScalarConverter::findType () {

    switch (_input_len)
    {
        case 0:
            setType (charType);
            break;
        case 1:
            setType (std::isdigit (_input [0]) ? intType : charType);
            break;
        default:
            _input.find_first_not_of ("-0123456789.f") != std::string::npos ? specialParse () : digitParse ();
    }
}

void                ScalarConverter::digitParse () {

    neg_lex (_input); 
    setType ((float_lex (_input, _input_len) == true) ?
		floatType : _type);
    setType ((_type == noType && double_lex (_input) == true) ?
		doubleType : _type);
    setType ((_type == noType && int_lex (_input) == true) ?
		intType : _type);
}

void                ScalarConverter::specialParse () {

    pseudo_litteral_lex (_input);
    setType (std::strtof (_input.c_str (), NULL) ?
		floatType : _type);
    setType (_type = (_type == noType && std::strtod (_input.c_str (), NULL)) ?
		doubleType : _type);
}

