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
		return ;
	}
	
	char	*p;
	long	res;
/* 	if (input.firs) */ // search if f a la fin
	if (res = std::strtod (input.c_str (), &p, 10))
	{
		if (res >= INT_MIN && res <= INT_MAX)
		{
		    _type = isint;
		    _int_cast = static_cast <int> (res);
		    convert (_int_cast);
		    return ;
		}
		_type = double;
		convert (res);

	}
}

void				Analyzer::convert (char c) {

	_char_cast = c;
	_int_cast = c - 48;
}

void				Analyzer::convert (int d) {

	_char_cast = isascii (d) ? d : 0;
	_int_cast = d;
}

void				Analyzer::print () const {

	print (_char_cast);
	print (_int_cast);
}

/******************************************************************************************************/
/*	PRINT																							  */
/******************************************************************************************************/

void				Analyzer::print (char c) const {

	std::cout << "Char : ";
	
/* 	std::cout << "\'" << c << "\'" << std::endl; */
	isprint (c) ? 
		std::cout << "\'" << c << "\'" << std::endl
		: std::cout << "Not printable" << std::endl;
}

void				Analyzer::print (int d) const {

	std::cout << "Int : " << d << std::endl;
}

/******************************************************************************************************/
/*	EXCEPTIONS																						  */
/******************************************************************************************************/

char const*			Analyzer::WrongArgument::what () const throw () {

	return ("Format : ./convert <literal>");
}