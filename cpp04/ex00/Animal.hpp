#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class	Animal {

	protected:
		std::string	_type;


	public:

		// CONSTRUCTORS / DESTRUCTOR
		Animal ();
		Animal (Animal const& original);
		~Animal ();
	 
	 	// OPERATORS
		Animal&	operator= (Animal const& right);
		
		// GETTERS / SETTERS
		std::string getType () const;

		// OTHER
		void		announce (Animal const &animal, std::string announceType) const;
};


#endif