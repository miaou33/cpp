# include "Analyzer.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

Analyzer::Analyzer () {

	_type = -1;
	_char_cast = 0;
	_int_cast = 0;
	_double_cast = 0.0;
	_float_cast = 0.0f;
}

Analyzer::Analyzer (Analyzer const& original) {

	*this = original;
}

Analyzer::~Analyzer () {}

Analyzer& Analyzer::operator= (Analyzer const& rhs) {

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

int					Analyzer::getType () const { return _type; }

char				Analyzer::getCharCast () const { return _char_cast; }

int					Analyzer::getIntCast () const { return _int_cast; }

double				Analyzer::getDoubleCast () const { return _double_cast; }

float				Analyzer::getFloatCast () const { return _float_cast; }

/******************************************************************************************************/
/*	CONVERT																							  */
/******************************************************************************************************/

void				Analyzer::convert (std::string const& input) {

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
		throw Analyzer::InvalidInput ();

	
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

void				Analyzer::convert (char c) {

	_char_cast = c;
	_int_cast = c - 48;
}

void				Analyzer::convert (int i) {

	_char_cast = isascii (i) ? i : 0;
	_int_cast = i;
	_double_cast = static_cast <double> (i);
}

void				Analyzer::convert (double d) {

	_char_cast = 0;
//	_int_cast = d >= INT_MIN && d <= INT_MAX ? d : ;
	_double_cast = d;
}

/******************************************************************************************************/
/*	PRINT																							  */
/******************************************************************************************************/

void				Analyzer::print () const {

	try {
		isprint (_char_cast) ? 
			std::cout << "Char: \'" << _char_cast << "\'" << std::endl
			: throw Analyzer::NonDisplayableChar ();		
	}
	catch (std::exception& e) {
		std::cout << e.what () << std::endl;
	}
	
}

/******************************************************************************************************/
/*	EXCEPTIONS																						  */
/******************************************************************************************************/

char const*			Analyzer::WrongArgument::what () const throw () {

	return ("Wrong argument. Format : ./convert <literal>");
}

char const*			Analyzer::InvalidInput::what () const throw () {

	return ("Invalid input. Please enter a literal");
}

char const*			Analyzer::NonDisplayableChar::what () const throw () {

	return ("Char: Non displayable");
}