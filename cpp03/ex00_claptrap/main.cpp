#include "ClapTrap.hpp"

int	main (void)
{
	ClapTrap	Ness ("Ness");
	ClapTrap	Paula ("Paula");
	ClapTrap	Jeff ("Jeff");

	std::cout << std::endl;
	std::cout << Ness << std::endl;
	std::cout << Paula << std::endl;
	std::cout << Jeff << std::endl;
	std::cout << std::endl;

/* 	for (int i = 0; i < 11; i++)
		Ness.beRepaired (1); */
	Ness.attack ("Paula");
	if (Ness.getHP () && Ness.getPP ())
		Paula.takeDamage (Ness.getAD ());
	Jeff.attack ("Ness");
	if (Jeff.getHP () && Jeff.getPP ())
		Ness.takeDamage (Jeff.getAD ());
	Paula.beRepaired (1);

	std::cout << std::endl;
	std::cout << Ness << std::endl;
	std::cout << Paula << std::endl;
	std::cout << Jeff << std::endl;
	std::cout << std::endl;
}