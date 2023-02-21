#ifndef NEWCLASS_HPP
# define NEWCLASS_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap {

	public:

		// CONSTRUCTORS / DESTRUCTOR
		ScavTrap (std::string name);
		ScavTrap (ScavTrap const& original);
		~ScavTrap ();
	 
	 	// OPERATORS
		ScavTrap&	operator= (ScavTrap const& right);
		
		// GETTERS / SETTERS : inherited by ClapTrap

		void	highFivesGuys (void);
		
};


#endif