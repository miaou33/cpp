#ifndef ANALYZER_HPP
# define ANALYZER_HPP

# include <string>
# include <iostream>
# include "colors.hpp"

class Analyzer {

	public:

		// CONSTRUCTOR DESTRUCTOR ASSIGNMENT 
		Analyzer (std::string input);
		Analyzer (Analyzer const& original);
		virtual ~Analyzer ();
		Analyzer& operator= (Analyzer const& rhs);

		// GETTER
		std::string const&	getInput () const;
		char				getCharCast () const;
		int					getIntCast () const;
		double				getDoubleCast () const;
		float				getFloatCast () const;

		// OTHER MB FUNCTIONS
	
	private:

		enum e_type {
			ischar = 0,
			isint,
			isfloat,
			isdouble
		};

		std::string		_input;
		char			_char_cast;
		int				_int_cast;
		float			_float_cast;
		double			_double_cast;
	
	public:

		class WrongArgument : public std::exception {

			virtual char const*	what () const throw ();
		};
};


# endif