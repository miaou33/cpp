# include "ScalarConverter.hpp"

/******************************************************************************************************/
/*    CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR                                                      */
/******************************************************************************************************/

ScalarConverter::ScalarConverter () {

    _param = "";
    _param_len = 0;
    initCasts ();
}

ScalarConverter::ScalarConverter (std::string const& string) {

    _param = string;
    _param_len = string.length ();
    initCasts ();
}

ScalarConverter::ScalarConverter (ScalarConverter const& original) {

    *this = original;
}

ScalarConverter::~ScalarConverter () {}

ScalarConverter& ScalarConverter::operator= (ScalarConverter const& rhs) {

    if (this != &rhs)
    {
        _param = rhs.getParam ();
        _type = rhs.getType ();
        _c = rhs.getCharCast ();
        _i = rhs.getIntCast ();
        _d = rhs.getDoubleCast ();
        _f = rhs.getFloatCast ();
    }
    return *this;
}

/******************************************************************************************************/
/*    GETTERS SETTERS                                                                                 */
/******************************************************************************************************/

std::string const&  ScalarConverter::getParam () const { return _param; }

size_t              ScalarConverter::getParamLen () const { return _param_len; }

int                 ScalarConverter::getType () const { return _type; }

char                ScalarConverter::getCharCast () const { return _c; }

int                 ScalarConverter::getIntCast () const { return _i; }

double              ScalarConverter::getDoubleCast () const { return _d; }

float               ScalarConverter::getFloatCast () const { return _f; }

void                ScalarConverter::initCasts () {

    _type = noType;
    _c = 0;
    _i = 0;
    _d = 0.0;
    _f = 0.0f;
}

/******************************************************************************************************/
/*    EXCEPTIONS                                                                                      */
/******************************************************************************************************/

char const*            ScalarConverter::WrongArgument::what () const throw () {

    return ("Wrong argument. Format : ./convert <literal>");
}

char const*            ScalarConverter::InvalidString::what () const throw () {

    return ("Invalid string. Please enter a literal thas is either a char, an int, a float or a double");
}

char const*            ScalarConverter::Impossible::what () const throw () {

    return ("Impossible");
}

char const*            ScalarConverter::NonDisplayable::what () const throw () {

    return ("Non displayable");
}

char const*            ScalarConverter::OutOfRangeValue::what () const throw () {

    return ("Out of range value");
}

/******************************************************************************************************/
/*    DISPLAY                                                                                         */
/******************************************************************************************************/

void                ScalarConverter::displayCasts () {

    try {
        findType ();
        errno = 0;
        switch (_type)
        {
            case charType:
                _c = _param [0];
                break;
            case intType:
                _i = atoi (_param.c_str ());
                break;
            case floatType:
                _f = std::strtof (_param.c_str (), NULL);
                break;
            case doubleType:
                _d = std::strtod (_param.c_str (), NULL);
                break;
            default:
                throw InvalidString ();
        }
        errno == ERANGE ?
            throw OutOfRangeValue ()
            : convert ();

    }
    catch (std::exception& e) {
        display_exception (e);
    }
}

/******************************************************************************************************/
/*    CONVERT                                                                                         */
/******************************************************************************************************/

void                ScalarConverter::convert () {
    
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
                throw InvalidString ();
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
                throw InvalidString ();
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
                throw InvalidString ();
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
                throw InvalidString ();
                break;
        }
    }
    catch (std::exception& e) { 
        display_exception (e); 
    }
}

void                ScalarConverter::findType () {

    switch (_param_len)
    {
        case 0:
            _type = charType;
            break;
        case 1:
            _type = std::isdigit (_param [0]) ? intType : charType;
            break;
        default:
            _param.find_first_not_of ("-0123456789.f") != std::string::npos ? specialParse () : digitParse ();
    }
}

void                ScalarConverter::digitParse () {

    neg_parse (_param); 
    _type = (float_parse (_param, _param_len) == true) ?
		floatType : _type;
    _type = (_type == noType && double_parse (_param) == true) ?
		doubleType : _type;
    _type = (_type == noType && int_parse (_param) == true) ?
		intType : _type;
}

void                ScalarConverter::specialParse () {

    special_float_double_parse (_param);
    _type = std::strtof (_param.c_str (), NULL) ?
		floatType : _type;
    _type = (_type == noType && std::strtod (_param.c_str (), NULL)) ?
		doubleType : _type;
}

