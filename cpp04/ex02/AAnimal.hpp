#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>
# include <iostream>

class	AAnimal {

	protected:
		std::string	_type;

	public:
		AAnimal ();
		AAnimal (AAnimal const & original);
		virtual ~AAnimal ();
		
		AAnimal		&operator= (AAnimal const & right);

		virtual std::string getType () const = 0;
		virtual void		announce (std::string const func) const;
		virtual void		makeSound () const = 0;
};


#endif