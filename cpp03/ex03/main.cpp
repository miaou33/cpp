#include "DiamondTrap.hpp"

int	main (void)
{
	int i = 0;
	ClapTrap	CLAPTRAP("\033[0;33mCLAPTRAP\033[0m");
	ScavTrap	SCAVTRAP("\033[0;31mSCAVTRAP\033[0m");
	FragTrap	FRAGTRAP("\033[0;32mFRAGTRAP\033[0m");
	DiamondTrap	DIAMONDTRAP("\033[0;35mDIAMONDTRAP\033[0m");
	
	std::cout << std::endl;
	std::cout << CLAPTRAP << std::endl;
	std::cout << SCAVTRAP << std::endl;
	std::cout << FRAGTRAP << std::endl;
	std::cout << DIAMONDTRAP << std::endl;
	
	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i << std::endl;
	FRAGTRAP.highFivesGuys ();
	SCAVTRAP.attack ("FRAGTRAP");
	if (SCAVTRAP.getHP () && SCAVTRAP.getPP ())
		FRAGTRAP.takeDamage (SCAVTRAP.getAD ());
	CLAPTRAP.attack ("SCAVTRAP");
	if (CLAPTRAP.getHP () && CLAPTRAP.getPP ())
		SCAVTRAP.takeDamage (CLAPTRAP.getAD());
	DIAMONDTRAP.attack ("FRAGTRAP");
	if (DIAMONDTRAP.getHP () && DIAMONDTRAP.getPP ())
		FRAGTRAP.takeDamage (DIAMONDTRAP.getAD ());	

	std::cout << std::endl;
	std::cout << CLAPTRAP << std::endl;	
	std::cout << SCAVTRAP << std::endl;
	std::cout << FRAGTRAP << std::endl;
	std::cout << DIAMONDTRAP << std::endl;

	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i <<  std::endl;
	FRAGTRAP.beRepaired (2);
	SCAVTRAP.guardGate ();
	CLAPTRAP.beRepaired (10);
	DIAMONDTRAP.whoAmI ();

	std::cout << std::endl;
	std::cout << CLAPTRAP << std::endl;
	std::cout << SCAVTRAP << std::endl;
	std::cout << FRAGTRAP << std::endl;
	std::cout << DIAMONDTRAP << std::endl;

	std::cout << std::endl;

}