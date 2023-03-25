#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {

	public:
		// CONSTRUCTOR DESTRUCTOR ASSIGNMENT 
		Ice ();
		Ice (std::string const& type);
		Ice (Ice const& original);
		virtual ~Ice ();
		Ice& operator= (Ice const& rhs);

		// GETTER
		std::string const&	getType () const;

		// OTHER MB FUNCTIONS
		virtual Ice*		clone () const;
		virtual void 		use (ICharacter& target);

};


# endif