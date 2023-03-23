#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"

class	Cat : public Animal {

	public:
		// CONSTRUCTORS / DESTRUCTOR / OPERATOR= OVERLOAD
		Cat ();
		Cat (Cat const& original);
		virtual ~Cat ();
		Cat& operator= (Cat const& toBecome);

		// OTHER
		virtual void	announce (std::string const func) const;
		virtual void	makeSound () const;
};


#endif