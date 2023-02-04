#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

enum e_Levels {
	debug = 0,
	infos,
	warning,
	error,
	not_valid
};

class	Harl {

	private:

		void	debug (void);
		void	info (void);
		void	warning (void);
		void	error (void);

	public:
	
		void	complain (std::string level);
};


#endif