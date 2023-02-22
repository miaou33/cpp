#include "ScavTrap.hpp"

int	main (void)
{
	int i = 0;
	ClapTrap	CLAPTRAP("weakCLAPTRAP");
	ScavTrap	NESS("\033[0;31mNESS\033[0m");
	ScavTrap	PAULA("\033[0;33mPAULA\033[0m");

	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i << std::endl;
	PAULA.highFivesGuys ();
	NESS.attack ("PAULA");
	if (NESS.getHP () && NESS.getPP ())
		PAULA.takeDamage (NESS.getAttackDamage ());
	CLAPTRAP.attack ("NESS");
	if (CLAPTRAP.getHP () && CLAPTRAP.getPP ())
		NESS.takeDamage (CLAPTRAP.getAttackDamage());
	
	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i <<  std::endl;
	PAULA.beRepaired (2);
	NESS.highFivesGuys ();
	CLAPTRAP.beRepaired (1);
	
	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i << std::endl;
	PAULA.attack ("NESS");
	if (PAULA.getHP () && PAULA.getPP ())
		NESS.takeDamage (PAULA.getAttackDamage ());
	NESS.attack ("PAULA");
	if (NESS.getHP () && NESS.getPP ())
		PAULA.takeDamage (NESS.getAttackDamage ());
	CLAPTRAP.beRepaired (1);

	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i << std::endl;
	PAULA.attack ("NESS");
	if (PAULA.getHP () && PAULA.getPP ())
		NESS.takeDamage (PAULA.getAttackDamage ());
	NESS.attack ("PAULA");
	if (NESS.getHP () && NESS.getPP ())
		PAULA.takeDamage (NESS.getAttackDamage ());
	CLAPTRAP.beRepaired (1);

	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i << std::endl;
	PAULA.attack ("NESS");
	if (PAULA.getHP () && PAULA.getPP ())
		NESS.takeDamage (PAULA.getAttackDamage ());
	NESS.attack ("PAULA");
	if (NESS.getHP () && NESS.getPP ())
		PAULA.takeDamage (NESS.getAttackDamage ());
	CLAPTRAP.beRepaired (1);

	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i << std::endl;
	PAULA.attack ("NESS");
	if (PAULA.getHP () && PAULA.getPP ())
		NESS.takeDamage (PAULA.getAttackDamage ());
	NESS.attack ("PAULA");
	if (NESS.getHP () && NESS.getPP ())
		PAULA.takeDamage (NESS.getAttackDamage ());
	CLAPTRAP.beRepaired (1);

	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i << std::endl;
	PAULA.attack ("NESS");
	if (PAULA.getHP () && PAULA.getPP ())
		NESS.takeDamage (PAULA.getAttackDamage ());
	NESS.highFivesGuys ();
	CLAPTRAP.beRepaired (1);

	std::cout << std::endl;
}