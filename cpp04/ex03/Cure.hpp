#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {

	public:
		// CONSTRUCTOR DESTRUCTOR ASSIGNMENT 
		Cure ();
		Cure (std::string const& type);
		Cure (Cure const& original);
		virtual ~Cure ();
		Cure& operator= (Cure const& toBecome);

		// GETTER
		std::string const&	getType () const;

		// MEMBER FUNCTIONS
		virtual Cure*		clone () const;
		virtual void 		use (ICharacter& target);

};


# endif