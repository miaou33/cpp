#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class	Dog : virtual public AAnimal {

	private:
		Brain*	_brain;

	public:

		// CONSTRUCTORS / DESTRUCTOR / OPERATOR= OVERLOAD
		Dog ();
		Dog (Dog const& original);
		virtual ~Dog ();
		Dog& operator= (Dog const& right);

		// GETTER
		virtual std::string getType () const;
		Brain*	getBrain () const;

		// OTHER
		virtual void	announce (std::string const func) const;
		virtual void	makeSound () const;

};


#endif