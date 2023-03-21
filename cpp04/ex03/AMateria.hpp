#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"

class AMateria {

	protected:
		std::string		_type;

	public:
		// CONSTRUCTOR DESTRUCTOR ASSIGNMENT 
		AMateria (std::string const& type);
		AMateria (AMateria const& original);
		virtual ~AMateria ();
		AMateria& operator= (AMateria const& source);

		// GETTER
		std::string const&	getType () const;

		// MEMBER FUNCTIONS
		virtual AMateria*	clone () const = 0;
 		virtual void		use (ICharacter& target);

};


# endif