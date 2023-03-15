#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"

class	Dog : public Animal {

	public:
		// CONSTRUCTORS / DESTRUCTOR / OPERATOR= OVERLOAD
		Dog ();
		Dog (Dog const & original);
		virtual ~Dog ();
		Dog& operator= (Dog const & right);

		// OTHER
		virtual void	announce (std::string const func) const;
		virtual void	makeSound () const;

};


#endif