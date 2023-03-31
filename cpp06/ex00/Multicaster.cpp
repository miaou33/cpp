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

	_c = 0;
	_i = 0;
	_d = 0.0;
	_f = 0.0f;
}

/******************************************************************************************************/
/*	CONVERT																							  */
/******************************************************************************************************/

void				Multicaster::convert () {

	switch (_param_len)
	{
		case 0:
			fromInt ();
			break;
		case 1:
			std::isdigit (_param [0]) ? fromInt () : fromChar ();
			break;
		default:
			parse ();
	}

}

void				Multicaster::fromChar () {

	std::cout << "Type is char" << std::endl;
	_c = _param [0];
	_i = static_cast <int> (_c);
	_f = static_cast <float> (_c);
	_d = static_cast <double> (_c);

}

void				Multicaster::fromInt () {

	std::cout << "Type is int" << std::endl;
	_i = std::atoi (_param.c_str ());
	_c = isascii (_i) ? _i : 0;
	_f = static_cast <float> (_i);
	_d = static_cast <double> (_i);
}

void				Multicaster::parse () {

	std::cout << "Parse" << std::endl;
}

/******************************************************************************************************/
/*	displayCasts																							  */
/******************************************************************************************************/

void				Multicaster::displayCasts () {


	try {
		convert ();
		display ();
	}
	catch (std::exception& e) {
		displayException (e);
	}
}

void				Multicaster::display () {
	
	try {
		std::cout << "Char: ";
		isprint (_c) ?
			std::cout << _c << std::endl
			: throw NonDisplayable ();
	}
	catch (std::exception& e) {

		displayException (e);
	}
	std::cout << "Int: " << _i << std::endl;
	std::cout << "Float: " << _f << std::endl;
	std::cout << "Double: " << _d << std::endl;
}

/******************************************************************************************************/
/*	EXCEPTIONS																						  */
/******************************************************************************************************/

void				Multicaster::displayException (std::exception& e) {

	std::cout << e.what () << std::endl;
}

char const*			Multicaster::WrongArgument::what () const throw () {

	return ("Wrong argument. Format : ./convert <literal>");
}

char const*			Multicaster::InvalidString::what () const throw () {

	return ("Invalid string. Please enter a literal");
}

char const*			Multicaster::NonDisplayable::what () const throw () {

	return ("Non displayable");
}