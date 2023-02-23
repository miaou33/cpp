#include "ScavTrap.hpp"

int	main (void)
{
	int i = 0;
	ClapTrap	CLAPTRAP("CLAPT");
	ScavTrap	NESS("\033[0;31mNESS\033[0m");
	ScavTrap	PAULA("\033[0;33mPAULA\033[0m");
	
	std::cout << std::endl;
	std::cout << NESS << std::endl;
	std::cout << PAULA << std::endl;
	std::cout << CLAPTRAP << std::endl;
	
	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i << std::endl;
	PAULA.guardGate ();
	NESS.attack ("PAULA");
	if (NESS.getHP () && NESS.getPP ())
		PAULA.takeDamage (NESS.getAD ());
	CLAPTRAP.attack ("NESS");
	if (CLAPTRAP.getHP () && CLAPTRAP.getPP ())
		NESS.takeDamage (CLAPTRAP.getAD());

	std::cout << std::endl;
	std::cout << NESS << std::endl;
	std::cout << PAULA << std::endl;
	std::cout << CLAPTRAP << std::endl;	

	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i <<  std::endl;
	PAULA.beRepaired (2);
	NESS.guardGate ();
	CLAPTRAP.beRepaired (1);
	
	std::cout << std::endl;
	std::cout << NESS << std::endl;
	std::cout << PAULA << std::endl;
	std::cout << CLAPTRAP << std::endl;
	
/* 	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i << std::endl;
	PAULA.attack ("NESS");
	if (PAULA.getHP () && PAULA.getPP ())
		NESS.takeDamage (PAULA.getAD ());
	NESS.attack ("PAULA");
	if (NESS.getHP () && NESS.getPP ())
		PAULA.takeDamage (NESS.getAD ());
	CLAPTRAP.beRepaired (1);

	std::cout << std::endl;
	std::cout << NESS << std::endl;
	std::cout << PAULA << std::endl;
	std::cout << CLAPTRAP << std::endl;

	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i << std::endl;
	PAULA.attack ("NESS");
	if (PAULA.getHP () && PAULA.getPP ())
		NESS.takeDamage (PAULA.getAD ());
	NESS.attack ("PAULA");
	if (NESS.getHP () && NESS.getPP ())
		PAULA.takeDamage (NESS.getAD ());
	CLAPTRAP.beRepaired (1);

	std::cout << std::endl;
	std::cout << NESS << std::endl;
	std::cout << PAULA << std::endl;
	std::cout << CLAPTRAP << std::endl;

	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i << std::endl;
	PAULA.attack ("NESS");
	if (PAULA.getHP () && PAULA.getPP ())
		NESS.takeDamage (PAULA.getAD ());
	NESS.attack ("PAULA");
	if (NESS.getHP () && NESS.getPP ())
		PAULA.takeDamage (NESS.getAD ());
	CLAPTRAP.beRepaired (1);

	std::cout << std::endl;
	std::cout << NESS << std::endl;
	std::cout << PAULA << std::endl;
	std::cout << CLAPTRAP << std::endl;

	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i << std::endl;
	PAULA.attack ("NESS");
	if (PAULA.getHP () && PAULA.getPP ())
		NESS.takeDamage (PAULA.getAD ());
	NESS.attack ("PAULA");
	if (NESS.getHP () && NESS.getPP ())
		PAULA.takeDamage (NESS.getAD ());
	CLAPTRAP.beRepaired (1);

	std::cout << std::endl;
	std::cout << NESS << std::endl;
	std::cout << PAULA << std::endl;
	std::cout << CLAPTRAP << std::endl;

	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i << std::endl;
	PAULA.attack ("NESS");
	if (PAULA.getHP () && PAULA.getPP ())
		NESS.takeDamage (PAULA.getAD ());
	NESS.guardGate ();
	CLAPTRAP.beRepaired (1);

	std::cout << std::endl;
	std::cout << NESS << std::endl;
	std::cout << PAULA << std::endl;
	std::cout << CLAPTRAP << std::endl; */

	std::cout << std::endl;
}