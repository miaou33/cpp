#include "ClapTrap.hpp"

int	main (void)
{
	ClapTrap	Ness("Ness");
	ClapTrap	Paula("Paula");
	ClapTrap	Jeff("Jeff");

	std::cout << std::endl;
	std::cout << Ness << std::endl;
	std::cout << Paula << std::endl;
	std::cout << Jeff << std::endl;
	std::cout << std::endl;

	Ness.attack ("Paula");
	Paula.takeDamage (Ness.getAD ());
	Paula.beRepaired (2);
	Jeff.attack ("Ness");
	Ness.takeDamage (Jeff.getAD ());

	std::cout << std::endl;
	std::cout << Ness << std::endl;
	std::cout << Paula << std::endl;
	std::cout << Jeff << std::endl;
	std::cout << std::endl;
}