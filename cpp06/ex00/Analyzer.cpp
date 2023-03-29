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
/*	OTHER MB FUNCTIONS																				  */
/******************************************************************************************************/

void				Analyzer::findType (std::string const& input) {

	if (input.length () == 1 && input [0] == '0')
	{
		_type = isint;
		_int_cast = 0;
		return ;
	}
	
	char	*p;
	long	res;

	if ((res = strtod (input.c_str (), &p, 10)) && res > INT32_MIN && res <= INT32_MAX)
	{

	}
	_int_cast = *p ? 0 : 
//	{
		_type = ischar;
/* 		return ;
	}
	if ( */

	std::cout << _type << std::endl;	
}

/******************************************************************************************************/
/*	EXCEPTIONS																						  */
/******************************************************************************************************/

char const*			Analyzer::WrongArgument::what () const throw () {

	return ("Format : ./convert <literal>");
}