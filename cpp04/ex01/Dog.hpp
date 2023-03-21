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
		Dog ();
		Dog (Dog const& original);
		virtual ~Dog ();

		Dog				&operator= (Dog const& source);

		Brain			*getBrain () const;
		std::string		getIdea (int i) const;
		void			setIdea (int i, std::string idea);
		void			displayIdea (int i) const;
		virtual void	announce (std::string const func) const;
		virtual void	makeSound () const;
};


#endif