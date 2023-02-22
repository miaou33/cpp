#include "DiamondTrap.hpp"

int	main (void)
{
	ClapTrap	CLAPTRAP("\033[0;32mCLAPTRAP\033[0m");
	ScavTrap	NESS("\033[0;31mSCAVTRAP\033[0m");
	FragTrap	FRAGTRAP("\033[0;33mFRAGTRAP\033[0m");
	DiamondTrap	DIAMONDTRAP("\033[0;34mDIAMONDTRAP\033[0m");

	std::cout << std::endl;
	std::cout << CLAPTRAP << std::endl;
	std::cout << NESS << std::endl;
	std::cout << FRAGTRAP << std::endl;
	std::cout << DIAMONDTRAP << std::endl;

/* 	int i = 0;
	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i << RESET << std::endl;
	FRAGTRAP.highFivesGuys ();
	DIAMONDTRAP.whoAmI ();
	NESS.attack ("DIAMONDTRAP");
	if (NESS.getHP () && NESS.getPP ())
		DIAMONDTRAP.takeDamage (NESS.getAttackDamage ());
	CLAPTRAP.attack ("NESS");
	if (CLAPTRAP.getHP () && CLAPTRAP.getPP ())
		NESS.takeDamage (CLAPTRAP.getAttackDamage());
	
	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i <<  RESET <<std::endl;
	FRAGTRAP.attack ("DIAMONDTRAP");
	if (FRAGTRAP.getHP () && FRAGTRAP.getPP ())
		DIAMONDTRAP.takeDamage (FRAGTRAP.getAttackDamage ());
	DIAMONDTRAP.beRepaired (2);
	NESS.guardGate ();
	CLAPTRAP.beRepaired (1);
	
	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i <<  RESET << std::endl;
	FRAGTRAP.beRepaired (2);
	DIAMONDTRAP.attack ("NESS");
	if (DIAMONDTRAP.getHP () && DIAMONDTRAP.getPP ())
		NESS.takeDamage (DIAMONDTRAP.getAttackDamage ());
	NESS.attack ("DIAMONDTRAP");
	if (NESS.getHP () && NESS.getPP ())
		DIAMONDTRAP.takeDamage (NESS.getAttackDamage ());
	CLAPTRAP.beRepaired (1);

	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i <<  RESET << std::endl;
	FRAGTRAP.highFivesGuys ();
	DIAMONDTRAP.attack ("NESS");
	if (DIAMONDTRAP.getHP () && DIAMONDTRAP.getPP ())
		NESS.takeDamage (DIAMONDTRAP.getAttackDamage ());
	NESS.attack ("DIAMONDTRAP");
	if (NESS.getHP () && NESS.getPP ())
		DIAMONDTRAP.takeDamage (NESS.getAttackDamage ());
	CLAPTRAP.beRepaired (1);

	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i <<  RESET << std::endl;
	FRAGTRAP.highFivesGuys ();
	DIAMONDTRAP.attack ("FRAGTRAP");
	if (DIAMONDTRAP.getHP () && DIAMONDTRAP.getPP ())
		FRAGTRAP.takeDamage (DIAMONDTRAP.getAttackDamage ());
	NESS.attack ("DIAMONDTRAP");
	if (NESS.getHP () && NESS.getPP ())
		DIAMONDTRAP.takeDamage (NESS.getAttackDamage ());
	CLAPTRAP.beRepaired (1);

	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i <<  RESET << std::endl;
	FRAGTRAP.highFivesGuys ();
	DIAMONDTRAP.attack ("NESS");
	if (DIAMONDTRAP.getHP () && DIAMONDTRAP.getPP ())
		NESS.takeDamage (DIAMONDTRAP.getAttackDamage ());
	NESS.attack ("DIAMONDTRAP");
	if (NESS.getHP () && NESS.getPP ())
		DIAMONDTRAP.takeDamage (NESS.getAttackDamage ());
	CLAPTRAP.beRepaired (1);

	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i <<  RESET << std::endl;
	FRAGTRAP.highFivesGuys ();
	DIAMONDTRAP.attack ("NESS");
	if (DIAMONDTRAP.getHP () && DIAMONDTRAP.getPP ())
		NESS.takeDamage (DIAMONDTRAP.getAttackDamage ());
	NESS.guardGate ();
	CLAPTRAP.beRepaired (1); */

	std::cout << std::endl;
}