#ifndef NCLASS_HPP
# define NCLASS_HPP

# include <string>
# include <iostream>

class nClass {

	public:

		nClass ();
		nClass (nClass const& original);
		nClass& operator= (nClass const& rhs);
		~nClass ();

	private:

};

# endif
