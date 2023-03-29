#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class	Animal {

	protected:
		std::string		_type;

	public:
		// CONSTRUCTORS / DESTRUCTOR / OPERATOR= OVERLOAD
		Animal ();
		Animal (Animal const& original);
		virtual ~Animal ();
		Animal&	operator= (Animal const& right);
		
		// GETTER
		std::string const& 	getType () const;

		// OTHER
		virtual void		announce (std::string const func) const;
		virtual void		makeSound () const;
};


#endif