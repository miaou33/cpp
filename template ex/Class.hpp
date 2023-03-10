#ifndef CLASS_HPP
# define CLASS_HPP

# include <string>
# include <iostream>

class	Class {

	private:


	public:

		// CONSTRUCTORS / DESTRUCTOR
		Class ();
		Class (Class const& original);
		~Class ();
	 
	 	// OPERATORS
		Class&	operator= (Class const& source);
		
		// GETTERS / SETTERS
		
};


#endif