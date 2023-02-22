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
	 
	 	// OPERATORS
		FragTrap&	operator= (FragTrap const& right);
		
		// GETTERS / SETTERS : inherited by ClapTrap

		void	highFivesGuys (void);
};


#endif