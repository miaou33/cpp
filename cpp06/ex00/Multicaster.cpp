# include "Multicaster.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
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
/*	GETTERS SETTERS																	  				  */
/******************************************************************************************************/

char				Multicaster::getCharCast () const { return _c; }

int					Multicaster::getIntCast () const { return _i; }

double				Multicaster::getDoubleCast () const { return _d; }

float				Multicaster::getFloatCast () const { return _f; }

void				Multicaster::initCasts () {

	_type = -1;
	_c = 0;
	_i = 0;
	_d = 0.0;
	_f = 0.0f;
}

/******************************************************************************************************/
/*	CONVERT																							  */
/******************************************************************************************************/

void				Multicaster::findType () {

	switch (_param_len)
	{
		case 0:
			_type = charType;
			break;
		case 1:
			_type = std::isdigit (_param [0]) ?
				intType
				: charType;
			break;
		default:
			_param.find_first_not_of ("-0123456789.f") != std::string::npos ?
				specialParse ()
				: digitParse ();
	}

}

void				Multicaster::digitParse () {

	size_t	found;

	std::cout << "Digit param parse" << std::endl;

	if ((found = _param.find_first_of ('-')) != std::string::npos)
	{
		if (found != 0 || _param.find_last_of ('-') != found)
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
		_type = doubleType;
		return;
	}
	_type = intType;
}

void				Multicaster::specialParse () {

	std::cout << "Special param parse" << std::endl;
}

void				Multicaster::fromChar () {

/* 	switch (_type)
	{
	case charType:
		break;
	case intType:
		isascii (
	
	default:
		break;
	}	 */
	_c = _param [0];


}

void				Multicaster::fromInt () {

	_i = atoi (_param.c_str ());
/* 	_c = isascii (_i) ? _i : 0;
	_f = static_cast <float> (_i);
	_d = static_cast <double> (_i); */
}

void				Multicaster::fromFloat () {

	_f = std::strtof (_param.c_str (), NULL);
	if (errno == ERANGE)
		throw OutOfRangeValue ();
}

void				Multicaster::fromDouble () {

	_d = std::strtod (_param.c_str (), NULL);
	if (errno == ERANGE)
		throw OutOfRangeValue ();
}





/******************************************************************************************************/
/*	DISPLAY																							  */
/******************************************************************************************************/

void				Multicaster::displayCasts () {


	void	(Multicaster::*fromType [4]) () = {
													&Multicaster::fromChar, 
													&Multicaster::fromInt,
													&Multicaster::fromFloat,
													&Multicaster::fromDouble
												};
	try {
		findType ();
		_type != -1 ? (this->*fromType [_type]) () : throw InvalidString ();
		displayCasts ();
	}
	catch (std::exception& e) {
		displayException (e);
	}
}

void				Multicaster::displayCasts () {
	
 	std::cout << "DISPLAY:" << std::endl;
	try {
		std::cout << "Char: ";
		toChar ();
	}
	catch (std::exception& e) { 
		displayException (e); 
	}
	try {
		std::cout << "Int: ";
		_i != std::numeric_limits <int> :: max () ?
			std::cout << _i << std::endl
			: throw Impossible ();
	}
	catch (std::exception& e) { 
		displayException (e); 
	}
	std::cout << "Float: " << _f << std::endl;
	std::cout << "Double: " << _d << std::endl;
}

void				Multicaster::toChar () {

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

void				Multicaster::toInt () {

	switch (_type)
	{
		case charType:
		 	display (static_cast <int> (_c));
			break;
		case intType:
			display (_i);
			break;
		case floatType:
		 	(_f >= INT_MIN && _f <= INT_MAX) ? display (static_cast <int> (_f)) : throw Impossible ();
			break;
		case doubleType:
			(_d >= INT_MIN && _d <= INT_MAX) ? display (static_cast <char> (_d)) : throw Impossible (); 
			break;
		default:
		 	throw InvalidString ();
			break;
	}
/* 	_c = isascii (_i) ? _i : 0;
	_f = static_cast <float> (_i);
	_d = static_cast <double> (_i); */
}

void				Multicaster::toFloat () {

/* 	if (_f >= std::numeric_limits<int>::min () && _f <= std::numeric_limits<int>::max ())
		_i = static_cast <int> (_f);
	else
		throw OutOfRangeValue (); */
}

void				Multicaster::toDouble () {

}

void				Multicaster::display (char c) const {

	if (!isprint (c))
		throw NonDisplayable ();
	std::cout << c << std::endl;
}

void				Multicaster::display (int i) const {

	std::cout << i << std::endl;
}

void				Multicaster::display (float f) const {

	std::cout << f << std::endl;
}

void				Multicaster::display (double d) const {

	std::cout << d << std::endl;
}

/******************************************************************************************************/
/*	EXCEPTIONS																						  */
/******************************************************************************************************/

void				Multicaster::displayException (std::exception& e) const {

	std::cout << e.what () << std::endl;
}

char const*			Multicaster::WrongArgument::what () const throw () {

	return ("Wrong argument. Format : ./convert <literal>");
}

char const*			Multicaster::InvalidString::what () const throw () {

	return ("Invalid string. Please enter a literal");
}

char const*			Multicaster::Impossible::what () const throw () {

	return ("Impossible");
}

char const*			Multicaster::NonDisplayable::what () const throw () {

	return ("Non displayable");
}

char const*			Multicaster::OutOfRangeValue::what () const throw () {

	return ("Out of range value");
}