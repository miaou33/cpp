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

static __uint8_t	level_index (std::string level) {

	std::string	levels[4] = {"DEBUG", "INFOS", "WARNING", "ERROR"};

	for (__uint8_t i = 0; i < 4; ++i)
	{
		if (levels[i] == level)
			return (i);
	}
	return (NOT_VALID);
}

typedef void	(Harl::*complainPtr) (void);

void	Harl::complain (std::string level) {

	__uint8_t	i;
	complainPtr	HarlComplain[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	if (level.empty ())
		return ;
	i = level_index(level);
	if (i != NOT_VALID)
		(this->*HarlComplain[i]) ();
}
