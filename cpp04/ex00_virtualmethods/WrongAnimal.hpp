#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class	WrongAnimal {

	protected:
		std::string	_type;

	public:
		// CONSTRUCTORS / DESTRUCTOR / OPERATOR= OVERLOAD
		WrongAnimal ();
		WrongAnimal (WrongAnimal const& original);
		virtual ~WrongAnimal ();
		WrongAnimal&	operator= (WrongAnimal const& right);
		
		// GETTER
		std::string const& 	getType () const;

		// OTHER
		void	announce (std::string const func) const;
		void	makeSound () const;
};


#endif