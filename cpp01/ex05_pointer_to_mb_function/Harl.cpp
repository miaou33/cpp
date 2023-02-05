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
	void (Harl::*p[4]) () = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i = 0;

	while (i < not_valid && s[i].compare(level) != 0)
		i++;
	if (i != not_valid)
		(this->*p[i]) ();
}
