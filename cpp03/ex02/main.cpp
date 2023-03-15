#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main (void)
{
	ClapTrap	CLAPTRAP("CLAPTRAP");
	ScavTrap	SCAVTRAP("SCAVTRAP");
	FragTrap	FRAGTRAP("FRAGTRAP");
	
	std::cout << std::endl;
	CLAPTRAP.printStats ();
	SCAVTRAP.printStats ();
	FRAGTRAP.printStats ();
	
	std::cout << std::endl;
	FRAGTRAP.highFivesGuys ();
	SCAVTRAP.attack ("FRAGTRAP");
	if (SCAVTRAP.getHP () && SCAVTRAP.getPP ())
		FRAGTRAP.takeDamage (SCAVTRAP.getAD ());
	CLAPTRAP.attack ("SCAVTRAP");
	if (CLAPTRAP.getHP () && CLAPTRAP.getPP ())
		SCAVTRAP.takeDamage (CLAPTRAP.getAD());

	std::cout << std::endl;
	CLAPTRAP.printStats ();	
	SCAVTRAP.printStats ();
	FRAGTRAP.printStats ();

	std::cout << std::endl;
	FRAGTRAP.attack ("CLAPTRAP");
	if (FRAGTRAP.getHP () && FRAGTRAP.getPP ())
		CLAPTRAP.takeDamage (FRAGTRAP.getAD());
	SCAVTRAP.guardGate ();
	CLAPTRAP.beRepaired (10);

	std::cout << std::endl;
	CLAPTRAP.printStats ();
	SCAVTRAP.printStats ();
	FRAGTRAP.printStats ();

	std::cout << std::endl;
}