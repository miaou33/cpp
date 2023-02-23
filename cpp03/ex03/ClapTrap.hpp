#ifndef _CLAPTRAP_HPP_
# define _CLAPTRAP_HPP_

# include <string>
# include <iostream>
# include <limits.h>
# include "colors.hpp"

typedef unsigned long t_ul;
typedef long long t_ll;

class	ClapTrap {

	protected:
		std::string			_name;
		unsigned int		_HP;
		unsigned int		_PP;
		unsigned int		_AD;

	public:

		// CONSTRUCTORS / DESTRUCTOR
		ClapTrap ();
		ClapTrap (std::string name);
		ClapTrap (ClapTrap const& original);
		virtual ~ClapTrap ();
	 
	 	// OPERATORS
		ClapTrap& operator= (ClapTrap const& source);
		
		// GETTERS
		std::string const	getName () const;
		unsigned int 		getHP () const;
		unsigned int		getPP () const;
		unsigned int		getAD () const;

	  	// SETTERS
		void				setDefaultHP ();
		void				setDefaultPP ();
		void				setDefaultAD ();

		// OTHERS
		void				attack (const std::string& target);
		void				takeDamage (unsigned int amount);
		void				beRepaired (unsigned int amount);
		
};

std::ostream&	operator<< (std::ostream& o, ClapTrap const& source);

#endif