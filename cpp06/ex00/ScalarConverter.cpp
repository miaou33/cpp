# include "ScalarConverter.hpp"

/******************************************************************************************************/
/*    CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR                                                      */
/******************************************************************************************************/

ScalarConverter::ScalarConverter () {}

ScalarConverter::ScalarConverter (ScalarConverter const& original) {

    *this = original;
}

ScalarConverter::~ScalarConverter () {}

ScalarConverter& ScalarConverter::operator= (ScalarConverter const& rhs) {

    return *this;
}

/******************************************************************************************************/
/*    EXCEPTIONS                                                                                      */
/******************************************************************************************************/

char const*            ScalarConverter::WrongArgument::what () const throw () {

    return ("Wrong argument. Format : ./convert <literal>");
}

char const*            ScalarConverter::InvalidInput::what () const throw () {

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
/*    CONVERT                                                                                         */
/******************************************************************************************************/

void                ScalarConverter::convert (std::string const& input) {

    _input = input;
    _input_c_str = input.c_str ();
    _input_length = input.length ();

    findType ();
    try {
        switch (_type)
        {
            case charType:
                _c = _input [0];
                break;
            case intType:
                _i = std::stoi (_input.c_str ());
                break;
            case floatType:
                _f = std::stof (_input.c_str ());
                break;
            case doubleType:
                _d = std::stod (_input.c_str ());
                break;
        }
    }
    catch (std::out_of_range& o) {
        display_exception (o);
    }
    toChar ();
    toInt ();
    toFloat ();
    toDouble ();
}

void                ScalarConverter::findType () {
    
    switch (_input_length)
    {
        case 0:
            _type = charType;
            break;
        case 1:
            _type = std::isdigit (_input [0]) ? intType : charType;
            break;
        default:
            _input.find_first_not_of ("-0123456789.f") != std::string::npos ? 
                                                            findScientNotationType (_input)
                                                            : findDigitType (_input);
    }

}

void                ScalarConverter::toChar () {

    announce ("Char: ");
    switch (_type)
    {
        case charType:
            display (_c);
            break;
        case intType:
            isascii (_i) ?
                display (static_cast <char> (_i)) : display ("Impossible");
            break;
        case floatType:
            isascii (static_cast <int> (_f)) ?
                display (static_cast <char> (_f)) : display ("Impossible"); 
            break;
        case doubleType:
            isascii (static_cast <int> (_d)) ?
                display (static_cast <char> (_d)) : display ("Impossible"); 
            break;
    }
}

void                ScalarConverter::toInt () {

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
                display (static_cast <int> (_f)) : display ("Impossible");
            break;
        case doubleType:
            (_d >= (double) INT_MIN && _d <= (double) INT_MAX) ? 
                display (static_cast <int> (_d)) : display ("Impossible"); 
            break;
    }
}

void                ScalarConverter::toFloat () {

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
                display (static_cast <float> (_d)) : display ("Impossible"); 
            break;
    }
}

void                ScalarConverter::toDouble () {

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
    }
}

void                ScalarConverter::findDigitType (std::string const& _input) {

    neg_parse (_input); 
    _type = (float_parse (_input, _input_length) == true) ?
		floatType : _type;
    _type = (_type == noType && double_parse (_input) == true) ?
		doubleType : _type;
    _type = (_type == noType && int_parse (_input) == true) ?
		intType : _type;
}

void                ScalarConverter::findScientNotationType (std::string const& _input) {

    special_float_double_parse (_input);
    _type = std::strtof (_input.c_str (), NULL) ?
		floatType : _type;
    _type = (_type == noType && std::strtod (_input.c_str (), NULL)) ?
		doubleType : _type;
}

