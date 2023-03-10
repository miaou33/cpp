#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class	Brain {

	private:
		std::string ideas [100] ;

	public:

		// CONSTRUCTORS / DESTRUCTOR
		Brain ();
		Brain (Brain const& original);
		~Brain ();
	 
	 	// OPERATORS
		Brain&	operator= (Brain const& source);
		
		// GETTERS / SETTERS
		std::string	*getIdeas ();
		
};


#endif