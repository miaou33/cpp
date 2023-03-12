#include "DiamondTrap.hpp"

int	main (void)
{
	ClapTrap	CLAPTRAP("CLAPTRAP");
	std::cout << std::endl;
	ScavTrap	SCAVTRAP("SCAVTRAP");
	std::cout << std::endl;
	FragTrap	FRAGTRAP("FRAGTRAP");
	std::cout << std::endl;
	DiamondTrap	DIAMONDTRAP("DIAMONDTRAP");
	
	std::cout << std::endl;
	CLAPTRAP.printStats ();
	SCAVTRAP.printStats ();
	FRAGTRAP.printStats ();
	DIAMONDTRAP.printStats ();
	
	std::cout << std::endl;
	
	FRAGTRAP.highFivesGuys ();
	SCAVTRAP.attack ("DIAMONDTRAP");
	if (SCAVTRAP.getHP () && SCAVTRAP.getPP ())
		DIAMONDTRAP.takeDamage (SCAVTRAP.getAD ());
	CLAPTRAP.attack ("SCAVTRAP");
	if (CLAPTRAP.getHP () && CLAPTRAP.getPP ())
		SCAVTRAP.takeDamage (CLAPTRAP.getAD());
	DIAMONDTRAP.attack ("FRAGTRAP");
	if (DIAMONDTRAP.getHP () && DIAMONDTRAP.getPP ())
		FRAGTRAP.takeDamage (DIAMONDTRAP.getAD ());	

	std::cout << std::endl;
	CLAPTRAP.printStats ();	
	SCAVTRAP.printStats ();
	FRAGTRAP.printStats ();
	DIAMONDTRAP.printStats ();

	std::cout << std::endl;
	FRAGTRAP.beRepaired (2);
	SCAVTRAP.guardGate ();
	SCAVTRAP.attack ("DIAMONDTRAP");
	if (SCAVTRAP.getHP () && SCAVTRAP.getPP ())
		DIAMONDTRAP.takeDamage (SCAVTRAP.getAD ());
	CLAPTRAP.beRepaired (10);
	DIAMONDTRAP.whoAmI ();

	std::cout << std::endl;
	CLAPTRAP.printStats ();
	SCAVTRAP.printStats ();
	FRAGTRAP.printStats ();
	DIAMONDTRAP.printStats ();

	std::cout << std::endl;

}