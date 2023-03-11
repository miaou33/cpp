#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal {

	private:
		Brain*	_brain;

	public:

		// CONSTRUCTORS / DESTRUCTOR / OPERATOR= OVERLOAD
		Dog ();
		Dog (Dog const& original);
		~Dog ();
		Dog& operator= (Dog const& right);

		// GETTER
		Brain*	getBrain () const;

};


#endif