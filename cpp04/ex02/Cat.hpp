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
		Cat ();
		Cat (Cat const & original);
		virtual ~Cat ();
		Cat& operator= (Cat const & source);

		virtual std::string getType () const;
		Brain*	getBrain () const;
		virtual void		announce (std::string const func) const;
		virtual void		makeSound () const;
};


#endif