#include "DiamondTrap.hpp"

int	main (void)
{
	ClapTrap	CLAPTRAP("CLAPTRAP");
	ScavTrap	SCAVTRAP("SCAVTRAP");
	FragTrap	FRAGTRAP("FRAGTRAP");
	DiamondTrap	DIAMONDTRAP("DIAMONDTRAP");
	
	std::cout << std::endl;
	std::cout << CLAPTRAP << std::endl;
	std::cout << SCAVTRAP << std::endl;
	std::cout << FRAGTRAP << std::endl;
	std::cout << DIAMONDTRAP << std::endl;
	
	std::cout << std::endl;
	
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