#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>
# include "Brain.hpp"

class	Animal {

	protected:
		std::string	_type;

	public:
		Animal ();
		Animal (Animal const & original);
		virtual ~Animal ();

		Animal			&operator= (Animal const & right);
		
		std::string		getType () const;
		virtual void	announce (std::string const func) const;
		virtual void	makeSound () const;
};


#endif