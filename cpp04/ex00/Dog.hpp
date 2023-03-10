#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"

class	Dog : public Animal {

	public:

		// CONSTRUCTORS / DESTRUCTOR
		Dog ();
		Dog (Dog const& original);
		~Dog ();
	 
	 	// OPERATORS
		Dog&	operator= (Dog const& right);
		
		// GETTERS / SETTERS
		
};


#endif