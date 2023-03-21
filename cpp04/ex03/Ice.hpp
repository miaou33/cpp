#ifndef ICE_HPP
# define ICE_HPP

# include "ICharacter.hpp"

class Ice {

	protected:
		std::string const	_type;

	public:
		// CONSTRUCTOR DESTRUCTOR ASSIGNMENT 
		Ice (std::string const & type);
		Ice (Ice const & original);
		virtual ~Ice ();
		Ice& operator = (Ice const & source);

		// GETTER
		std::string const &	getType () const;

		// MEMBER FUNCTIONS
		virtual Ice *	clone () const;
		virtual void use (ICharacter & target);

};


# endif