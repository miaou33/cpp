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
		Cat ();
		Cat (Cat const & original);
		virtual ~Cat ();

		Cat				&operator= (Cat const & source);

		Brain			*getBrain () const;
		std::string		getIdea (int i) const;
		void			setIdea (int i, std::string idea);
		void			displayIdea (int i) const;
		virtual void	announce (std::string const func) const;
		virtual void	makeSound () const;
};


#endif