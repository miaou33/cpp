#ifndef MULTICASTER_HPP
# define MULTICASTER_HPP

# include <string>
# include <iostream>
# include <stdlib.h>
# include <stdio.h>
# include <cstddef>
# include <bits/stdc++.h>
# include "colors.hpp"

class Multicaster {

	public:

		// CONSTRUCTOR DESTRUCTOR ASSIGNMENT 
		Multicaster ();
		Multicaster (std::string const& string);
		Multicaster (Multicaster const& original);
		virtual ~Multicaster ();
		Multicaster& operator= (Multicaster const& rhs);

		// GETTER
		char			getCharCast () const;
		int				getIntCast () const;
		double			getDoubleCast () const;
		float			getFloatCast () const;

		// OTHER MB FUNCTIONS
		void			displayCasts ();
	
	private:

		enum e_type {
			ischar = 0,
			isint,
			isfloat,
			isdouble
		};

  		std::string		_param;
		size_t			_param_len;
		char			_c;
		int				_i;
		float			_f;
		double			_d;

		void			initCasts ();
		void			parse ();
		void			convert ();
		void			fromChar ();
		void			fromInt ();
		void			display () const;
		
		void 	displayException (std::exception& e);
		
	public:

		class WrongArgument : public std::exception {

			virtual char const*	what () const throw ();
		};
		class InvalidString : public std::exception {

			virtual char const*	what () const throw ();
		};
		class NonDisplayable : public std::exception {

			virtual char const*	what () const throw ();
		};
};


# endif