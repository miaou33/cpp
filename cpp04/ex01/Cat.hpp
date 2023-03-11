#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal {

	private:
		Brain*	_brain;

	public:

		// CONSTRUCTORS / DESTRUCTOR
		Cat ();
		Cat (Cat const& original);
		~Cat ();
		Cat& operator= (Cat const& source);

		// GETTER
		Brain*	getBrain () const;
};


#endif