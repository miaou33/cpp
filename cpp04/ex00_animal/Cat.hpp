#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"

class	Cat : public Animal {

	public:

		// CONSTRUCTORS / DESTRUCTOR
		Cat ();
		Cat (Cat const& original);
		~Cat ();
	 
	 	// OPERATORS
		Cat&	operator= (Cat const& source);
};


#endif