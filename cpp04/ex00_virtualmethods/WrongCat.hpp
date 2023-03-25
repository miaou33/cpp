#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <string>
# include <iostream>
# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {

	public:
		// CONSTRUCTORS / DESTRUCTOR / OPERATOR= OVERLOAD
		WrongCat ();
		WrongCat (WrongCat const& original);
		virtual ~WrongCat ();
		WrongCat& operator= (WrongCat const& rhs);

		// OTHER
		void	announce (std::string const func) const;
		void	makeSound () const;
};


#endif