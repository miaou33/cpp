#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class	Animal {

	protected:
		std::string	_type;


	public:

		// CONSTRUCTORS / DESTRUCTOR / OPERATOR= OVERLOAD
		Animal ();
		Animal (Animal const& original);
		~Animal ();
		Animal&	operator= (Animal const& right);
		
		// GETTER
		std::string getType () const;

		// OTHER
		void	announce (std::string const who, std::string const what) const;
		void	makeSound ();
};


#endif