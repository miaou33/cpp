#ifndef _FRAGTRAP_HPP_
# define _FRAGTRAP_HPP_

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap {

	public:

		// CONSTRUCTORS / DESTRUCTOR
		FragTrap (std::string name);
		FragTrap (FragTrap const& original);
		~FragTrap ();
	 
	  	// SETTER
		void	setDefaultHP ();
		void	setDefaultPP ();
		void	setDefaultAD ();

	 	// OPERATORS
		FragTrap&	operator= (ClapTrap const& source);
		
		void	highFivesGuys (void);
};


#endif