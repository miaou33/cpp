#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class	Brain {

	private:
		std::string	_ideas [100];

	public:
		Brain ();
		Brain (Brain const & original);
		~Brain ();
		Brain&	operator= (Brain const & source);
		
		std::string		getIdea (int i) const;
		void			setIdea (int i, std::string idea); 
		void			announce (std::string const func) const;
		void			displayIdea (int i) const;
};


#endif