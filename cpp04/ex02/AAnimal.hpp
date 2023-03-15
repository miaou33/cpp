#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>
# include <iostream>

class	AAnimal {

	protected:
		std::string	_type;

	public:
		// CONSTRUCTORS / DESTRUCTOR / OPERATOR= OVERLOAD
		AAnimal ();
		AAnimal (AAnimal const & original);
		virtual ~AAnimal ();
		AAnimal&	operator= (AAnimal const & right);

		// GETTER
		virtual std::string getType () const = 0;
		
		// OTHER
		virtual void	announce (std::string const func) const;
		virtual void	makeSound () const = 0;
};


#endif