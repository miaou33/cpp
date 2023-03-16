#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class	Brain {

	private:
		std::string _ideas [100];

	public:
		Brain ();
		Brain (Brain const & original);
		~Brain ();

		Brain		&operator= (Brain const & source);
		
		std::string	getIdea (int i) const;
		void		announce (std::string const func) const;
};


#endif