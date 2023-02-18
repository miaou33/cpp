#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include "ClapTrap.hpp"

class	ClapTrap {

	private:


	public:

		// CONSTRUCTORS / DESTRUCTOR
		ClapTrap ();
		ClapTrap (ClapTrap const& original);
		~ClapTrap ();
	 
	 	// OPERATORS
		ClapTrap&	operator= (ClapTrap const& right);
		
		// GETTERS / SETTERS
		
};


#endif