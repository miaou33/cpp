#ifndef MULTICASTER_HPP
# define MULTICASTER_HPP

# include <bits/stdc++.h>
# include <cstddef>
# include <iostream>
# include <limits>
# include <stdlib.h>
# include <stdio.h>
# include <string>

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
			charType = 0,
			intType,
			floatType,
			doubleType
		};

  		std::string		_param;
		size_t			_param_len;
		int				_type;
		char			_c;
		int				_i;
		float			_f;
		double			_d;

		void			initCasts ();
		void			convert ();
		void			strParse ();
		void			digitParse ();
		void			fromChar ();
		void			fromInt ();
		void			fromFloat ();
		void			fromDouble ();
		void			display () const;
		
		void 			displayException (std::exception& e) const;
		
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
		class Impossible : public std::exception {

			virtual char const*	what () const throw ();
		};
};


# endif