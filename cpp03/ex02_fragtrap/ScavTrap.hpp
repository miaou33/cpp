#ifndef _SCAVTRAP_HPP_
# define _SCAVTRAP_HPP_

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap {

	public:

		// CONSTRUCTORS / DESTRUCTOR
		ScavTrap (std::string name);
		ScavTrap (ScavTrap const& original);
		~ScavTrap ();

	  	// SETTER
		void	setDefaultHP ();
		void	setDefaultPP ();
		void	setDefaultAD ();

	 	// OPERATORS
		ScavTrap&	operator= (ClapTrap const& source);
		
		void	attack (const std::string& target);
		void	guardGate (void);
};


#endif