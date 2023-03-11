#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class	Brain {

	private:
		std::string _ideas [100];

	public:

		// CONSTRUCTORS / DESTRUCTOR / OPERATOR= OVERLOAD
		Brain ();
		Brain (Brain const& original);
		~Brain ();
		Brain&	operator= (Brain const& source);
		
		// GETTER
		std::string	getIdea (int i) const;

		// OTHER
		void	announce (std::string const who, std::string const what) const;
};


#endif