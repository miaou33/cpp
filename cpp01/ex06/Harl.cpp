#include "Harl.hpp"

void	Harl::debug (void) {

	std::cout << "my love having extra bacon" << std::endl;
}

void	Harl::info (void) {

	std::cout << "wut ? extra bacon costs more money" << std::endl;
}

void	Harl::warning (void) {

	std::cout << "give me bacon for free stp i come often" << std::endl;
}

void	Harl::error (void) {

	std::cout << ".>-<. wanna speak to manager rn" << std::endl;
}

void	Harl::complain (std::string level) {

	std::string	s[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int lvl = 0;

	while (lvl < 4 && s[lvl].compare(level) != 0)
		lvl++;
	if (lvl == 4)
		return ;
	switch (lvl)
	{
		case ERROR:
			error ();
		case WARNING:
			warning ();
		case INFO:
			info ();
		case DEBUG:
			debug ();
	}
}
