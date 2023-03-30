#ifndef ANALYZER_HPP
# define ANALYZER_HPP

# include <string>
# include <iostream>
# include <stdlib.h>
# include <stdio.h>
# include <bits/stdc++.h>
# include "colors.hpp"

class Analyzer {

	public:

		// CONSTRUCTOR DESTRUCTOR ASSIGNMENT 
		Analyzer ();
		Analyzer (Analyzer const& original);
		virtual ~Analyzer ();
		Analyzer& operator= (Analyzer const& rhs);

		// GETTER
		int				getType () const;
		char			getCharCast () const;
		int				getIntCast () const;
		double			getDoubleCast () const;
		float			getFloatCast () const;

		// OTHER MB FUNCTIONS
		void			convert (std::string const& input);

		void			print () const;
	
	private:

		enum e_type {
			ischar = 0,
			isint,
			isfloat,
			isdouble
		};

		int				_type;
		char			_char_cast;
		int				_int_cast;
		float			_float_cast;
		double			_double_cast;
		
		void			convert (char c);
		void			convert (int d);
		
		void			print (char c) const;
		void			print (int d) const;
	
	public:

		class WrongArgument : public std::exception {

			virtual char const*	what () const throw ();
		};
};


# endif