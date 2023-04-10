# include "Multicaster.hpp"

/******************************************************************************************************/
/*    CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR                                                      */
/******************************************************************************************************/

Multicaster::Multicaster () {

    _param = "";
    _param_len = 0;
    initCasts ();
}

Multicaster::Multicaster (std::string const& string) {

    _param = string;
    _param_len = string.length ();
    initCasts ();
}

Multicaster::Multicaster (Multicaster const& original) {

    *this = original;
}

Multicaster::~Multicaster () {}

Multicaster& Multicaster::operator= (Multicaster const& rhs) {

    if (this != &rhs)
    {
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

char                Multicaster::getCharCast () const { return _c; }

int                 Multicaster::getIntCast () const { return _i; }

double              Multicaster::getDoubleCast () const { return _d; }

float               Multicaster::getFloatCast () const { return _f; }

void                Multicaster::initCasts () {

    _type = -1;
    _c = 0;
    _i = 0;
    _d = 0.0;
    _f = 0.0f;
}

/******************************************************************************************************/
/*    DISPLAY                                                                                         */
/******************************************************************************************************/

void                Multicaster::displayCasts () {

    try {
        findType ();
/*         switch (_type)
        {
            case charType:
                display ("CHAR TYPE");
                break;
            case intType:
                display ("INT TYPE");
                break;
            case floatType:
                display ("FLOAT TYPE");
                break;
            case doubleType:
                display ("DOUBLE TYPE");
                break;
            default:
                throw InvalidString ();
        } */
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
        errno == ERANGE ? throw OutOfRangeValue () : convert ();

    }
    catch (std::exception& e) {
        displayException (e);
    }
}

void                Multicaster::convert () {
    
    toChar ();
    toInt ();
    toFloat ();
    toDouble ();
}

void                Multicaster::toChar () {

    try {
        announce ("Char: ");
        switch (_type)
        {
            case charType:
                display (_c);
                break;
            case intType:
                isascii (_i) ? display (static_cast <char> (_i)) : throw Impossible ();
                break;
            case floatType:
                isascii (static_cast <int> (_f)) ? display (static_cast <char> (_f)) : throw Impossible (); 
                break;
            case doubleType:
                isascii (static_cast <int> (_d)) ? display (static_cast <char> (_d)) : throw Impossible (); 
                break;
            default:
                throw InvalidString ();
                break;
        }
    }
    catch (std::exception& e) { 
        displayException (e); 
    }
}

void                Multicaster::toInt () {

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
                (_f >= (float) INT_MIN && _f <= (float) INT_MAX) ? display (static_cast <int> (_f)) : throw Impossible ();
                break;
            case doubleType:
                (_d >= (double) INT_MIN && _d <= (double) INT_MAX) ? display (static_cast <int> (_d)) : throw Impossible (); 
                break;
            default:
                throw InvalidString ();
                break;
        }
    }
    catch (std::exception& e) { 
        displayException (e); 
    }
}

void                Multicaster::toFloat () {

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
                (_d >= (double) FLT_MIN && _d <= (double) FLT_MAX) ?
                    display (static_cast <float> (_d)) : throw Impossible (); 
                break;
            default:
                throw InvalidString ();
                break;
        }
    }
    catch (std::exception& e) { 
        displayException (e); 
    }
}

void                Multicaster::toDouble () {

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
        displayException (e); 
    }
}

/******************************************************************************************************/
/*    CONVERT                                                                                         */
/******************************************************************************************************/

void                Multicaster::findType () {

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

void                Multicaster::digitParse () {

    size_t    found;

    std::cout << "Digit param parse" << std::endl;

    if (((found = _param.find_first_of ('-')) != std::string::npos) 
            && (found != 0 || _param.find_last_of ('-') != found))
    {
        throw InvalidString ();
    }
    
    if ((found = _param.find_first_of ('f')) != std::string::npos)
    {
        if (found != _param_len - 1 || _param.find_last_of ('f') != found)
            throw InvalidString ();
        _type = floatType;
        return;
    }

    if ((found = _param.find_first_of ('.')) != std::string::npos)
    {
        if (_param.find_last_of ('.') != found)
            throw InvalidString ();
        _type = doubleType;
        return;
    }
    
    char *p;
    long n = std::strtol (_param.c_str (), &p, 10);
    if (errno == ERANGE || n < std::numeric_limits<int>::min ()
                        || n > std::numeric_limits<int>::max ()) {
        throw InvalidString ();
    }
    _type = intType;
}

void                Multicaster::specialParse () {

    std::cout << "Special param parse" << std::endl;
}

/******************************************************************************************************/
/*    EXCEPTIONS                                                                                      */
/******************************************************************************************************/

char const*            Multicaster::WrongArgument::what () const throw () {

    return ("Wrong argument. Format : ./convert <literal>");
}

char const*            Multicaster::InvalidString::what () const throw () {

    return ("Invalid string. Please enter a literal thas is either a char, an int, a float or a double");
}

char const*            Multicaster::Impossible::what () const throw () {

    return ("Impossible");
}

char const*            Multicaster::NonDisplayable::what () const throw () {

    return ("Non displayable");
}

char const*            Multicaster::OutOfRangeValue::what () const throw () {

    return ("Out of range value");
}