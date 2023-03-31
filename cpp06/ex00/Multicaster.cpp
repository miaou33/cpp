# include "Multicaster.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

Multicaster::Multicaster () {

	_type = -1;
	_char_cast = 0;
	_int_cast = 0;
	_double_cast = 0.0;
	_float_cast = 0.0f;
}

Multicaster::Multicaster (Multicaster const& original) {

	*this = original;
}

Multicaster::~Multicaster () {}

Multicaster& Multicaster::operator= (Multicaster const& rhs) {

	if (this != &rhs)
	{
		_type = rhs.getType ();
		_char_cast = rhs.getCharCast ();
		_int_cast = rhs.getIntCast ();
		_double_cast = rhs.getDoubleCast ();
		_float_cast = rhs.getFloatCast ();
	}
	return *this;
}

/******************************************************************************************************/
/*	GETTERS SETTERS																	  				  */
/******************************************************************************************************/

int					Multicaster::getType () const { return _type; }

char				Multicaster::getCharCast () const { return _char_cast; }

int					Multicaster::getIntCast () const { return _int_cast; }

double				Multicaster::getDoubleCast () const { return _double_cast; }

float				Multicaster::getFloatCast () const { return _float_cast; }

/******************************************************************************************************/
/*	CONVERT																							  */
/******************************************************************************************************/

void				Multicaster::convert (std::string const& input) {

	if (input.length () == 1)
	{
		isdigit (input [0]) ?
			convert ((int) (input [0] - 48))
			: convert (input [0]);
	}
	else
	{
	static std::string const valid_characters = "0123456789.f";

	if (input.find_first_not_of (valid_characters) != std::string::npos)
		throw Multicaster::InvalidInput ();

	
/* 	char	*p;
	double	res;
 	if (input.firs)  // search if f a la fin
	if ((res = std::strtod (input.c_str (), &p)))
	{
		if (res >= INT_MIN && res <= INT_MAX)
		{
			if (!input.find_first_of ('.', 
		    _type = isint;
		    _int_cast = static_cast <int> (res);
		    convert (_int_cast);
		    return ;
		}
		_type = isdouble;
		convert (res);

	} */
	}
	print ();
}

void				Multicaster::convert (char c) {

	_char_cast = c;
	_int_cast = c - 48;
}

void				Multicaster::convert (int i) {

	_char_cast = isascii (i) ? i : 0;
	_int_cast = i;
	_double_cast = static_cast <double> (i);
}

void				Multicaster::convert (double d) {

	_char_cast = 0;
//	_int_cast = d >= INT_MIN && d <= INT_MAX ? d : ;
	_double_cast = d;
}

/******************************************************************************************************/
/*	PRINT																							  */
/******************************************************************************************************/

void				Multicaster::print () const {

	try {
		isprint (_char_cast) ? 
			std::cout << "Char: \'" << _char_cast << "\'" << std::endl
			: throw Multicaster::NonDisplayableChar ();		
	}
	catch (std::exception& e) {
		std::cout << e.what () << std::endl;
	}
	
}

/******************************************************************************************************/
/*	EXCEPTIONS																						  */
/******************************************************************************************************/

char const*			Multicaster::WrongArgument::what () const throw () {

	return ("Wrong argument. Format : ./convert <literal>");
}

char const*			Multicaster::InvalidInput::what () const throw () {

	return ("Invalid input. Please enter a literal");
}

char const*			Multicaster::NonDisplayableChar::what () const throw () {

	return ("Char: Non displayable");
}