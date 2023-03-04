#ifndef NEWCLASS_HPP
# define NEWCLASS_HPP

# include <string>
# include <iostream>

class	newClass {

	private:


	public:

		// CONSTRUCTORS / DESTRUCTOR
		newClass ();
		newClass (newClass const& original);
		~newClass ();
	 
	 	// OPERATORS
		newClass&	operator= (newClass const& right);
		
		// GETTERS / SETTERS
		
};


#endif