# include "Analyzer.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

Analyzer::Analyzer (std::string input) : _input (input) {

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
		_input = rhs.getInput ();
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

std::string const&	Analyzer::getInput () const { return _input; }

char				Analyzer::getCharCast () const { return _char_cast; }

int					Analyzer::getIntCast () const { return _int_cast; }

double				Analyzer::getDoubleCast () const { return _double_cast; }

float				Analyzer::getFloatCast () const { return _float_cast; }

/******************************************************************************************************/
/*	OTHER MB FUNCTIONS																				  */
/******************************************************************************************************/
