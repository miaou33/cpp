#ifndef _CLAPTRAP_HPP_
# define _CLAPTRAP_HPP_

# include <string>
# include <iostream>
# include <limits.h>
# include "colors.hpp"

class	ClapTrap {

	protected:
		std::string			_name;
		unsigned int		_HP;
		unsigned int		_PP;
		unsigned int		_AD;

	public:

		// CONSTRUCTORS / DESTRUCTOR
		ClapTrap (std::string name);
		ClapTrap (ClapTrap const& original);
		~ClapTrap ();
	 
	 	// OPERATORS
		ClapTrap&	operator= (ClapTrap const& source);
		
		// GETTERS / SETTERS
		std::string const	getName () const;
		unsigned int 		getHP () const;
		unsigned int		getPP () const;
		unsigned int		getAD () const;

		// OTHERS
		void				attack (const std::string& target);
		void				takeDamage (unsigned int amount);
		void				beRepaired (unsigned int amount);
		
};


#endif