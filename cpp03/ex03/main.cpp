#include "DiamondTrap.hpp"

int	main (void)
{
	ClapTrap	CLAPTRAP("\033[0;32mCLAPTRAP\033[0m");
	ScavTrap	SCAVTRAP("\033[0;31mSCAVTRAP\033[0m");
	FragTrap	FRAGTRAP("\033[0;33mFRAGTRAP\033[0m");
	DiamondTrap	DIAMONDTRAP("\033[0;34mDIAMONDTRAP\033[0m");

	std::cout << std::endl;
	std::cout << CLAPTRAP << std::endl;
	std::cout << SCAVTRAP << std::endl;
	std::cout << FRAGTRAP << std::endl;
	std::cout << DIAMONDTRAP << std::endl;

	int i = 0;
	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i << END << std::endl;
	FRAGTRAP.highFivesGuys ();
	DIAMONDTRAP.whoAmI ();
	SCAVTRAP.attack ("DIAMONDTRAP");
	if (SCAVTRAP.getHP () && SCAVTRAP.getPP ())
		DIAMONDTRAP.takeDamage (SCAVTRAP.getAD ());
	CLAPTRAP.attack ("SCAVTRAP");
	if (CLAPTRAP.getHP () && CLAPTRAP.getPP ())
		SCAVTRAP.takeDamage (CLAPTRAP.getAD());
	
	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i <<  END <<std::endl;
	FRAGTRAP.attack ("DIAMONDTRAP");
	if (FRAGTRAP.getHP () && FRAGTRAP.getPP ())
		DIAMONDTRAP.takeDamage (FRAGTRAP.getAD ());
	DIAMONDTRAP.beRepaired (2);
	SCAVTRAP.guardGate ();
	CLAPTRAP.beRepaired (1);
	
	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i <<  END << std::endl;
	FRAGTRAP.beRepaired (2);
	DIAMONDTRAP.attack ("SCAVTRAP");
	if (DIAMONDTRAP.getHP () && DIAMONDTRAP.getPP ())
		SCAVTRAP.takeDamage (DIAMONDTRAP.getAD ());
	SCAVTRAP.attack ("DIAMONDTRAP");
	if (SCAVTRAP.getHP () && SCAVTRAP.getPP ())
		DIAMONDTRAP.takeDamage (SCAVTRAP.getAD ());
	CLAPTRAP.beRepaired (1);

	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i <<  END << std::endl;
	FRAGTRAP.highFivesGuys ();
	DIAMONDTRAP.attack ("SCAVTRAP");
	if (DIAMONDTRAP.getHP () && DIAMONDTRAP.getPP ())
		SCAVTRAP.takeDamage (DIAMONDTRAP.getAD ());
	SCAVTRAP.attack ("DIAMONDTRAP");
	if (SCAVTRAP.getHP () && SCAVTRAP.getPP ())
		DIAMONDTRAP.takeDamage (SCAVTRAP.getAD ());
	CLAPTRAP.beRepaired (1);

	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i <<  END << std::endl;
	FRAGTRAP.highFivesGuys ();
	DIAMONDTRAP.attack ("FRAGTRAP");
	if (DIAMONDTRAP.getHP () && DIAMONDTRAP.getPP ())
		FRAGTRAP.takeDamage (DIAMONDTRAP.getAD ());
	SCAVTRAP.attack ("DIAMONDTRAP");
	if (SCAVTRAP.getHP () && SCAVTRAP.getPP ())
		DIAMONDTRAP.takeDamage (SCAVTRAP.getAD ());
	CLAPTRAP.beRepaired (1);

	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i <<  END << std::endl;
	FRAGTRAP.highFivesGuys ();
	DIAMONDTRAP.attack ("SCAVTRAP");
	if (DIAMONDTRAP.getHP () && DIAMONDTRAP.getPP ())
		SCAVTRAP.takeDamage (DIAMONDTRAP.getAD ());
	SCAVTRAP.attack ("DIAMONDTRAP");
	if (SCAVTRAP.getHP () && SCAVTRAP.getPP ())
		DIAMONDTRAP.takeDamage (SCAVTRAP.getAD ());
	CLAPTRAP.beRepaired (1);

	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i <<  END << std::endl;
	FRAGTRAP.highFivesGuys ();
	DIAMONDTRAP.attack ("SCAVTRAP");
	if (DIAMONDTRAP.getHP () && DIAMONDTRAP.getPP ())
		SCAVTRAP.takeDamage (DIAMONDTRAP.getAD ());
	SCAVTRAP.guardGate ();
	CLAPTRAP.beRepaired (1);

	std::cout << std::endl;
}