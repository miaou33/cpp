#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class	Cat : virtual public AAnimal {

	private:
		Brain*	_brain;

	public:

		// CONSTRUCTORS / DESTRUCTOR / OPERATOR= OVERLOAD
		Cat ();
		Cat (Cat const& original);
		virtual ~Cat ();
		Cat& operator= (Cat const& source);

		// GETTER
		virtual std::string getType () const;
		Brain*	getBrain () const;

		// OTHER
		virtual void	announce (std::string const func) const;
		virtual void	makeSound () const;
};


#endif