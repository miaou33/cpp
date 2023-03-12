#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"

class AMateria {

	protected:
		std::string const	_type;

	public:
		AMateria ();
		AMateria (AMateria const & original);
		AMateria (std::string const & type);
		~AMateria ();
		AMateria & operator = (AMateria const & source);

		std::string const &	getType () const;

};


# endif