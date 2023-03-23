#include "ScavTrap.hpp"

int	main (void)
{
	ClapTrap	CLAPTRAP("CLAPT");
	ScavTrap	SCAV1("SCAV1");
	ScavTrap	SCAV2("SCAV2");
	
	std::cout << std::endl;
	CLAPTRAP.printStats ();
	SCAV1.printStats ();
	SCAV2.printStats ();
	
	std::cout << std::endl;
	SCAV2.attack ("CLAPTRAP");
	if (SCAV2.getHP () && SCAV2.getPP ())
		CLAPTRAP.takeDamage (SCAV2.getAD ());	
	SCAV1.attack ("SCAV2");
	if (SCAV1.getHP () && SCAV1.getPP ())
		SCAV2.takeDamage (SCAV1.getAD ());
	CLAPTRAP.attack ("SCAV1");
	if (CLAPTRAP.getHP () && CLAPTRAP.getPP ())
		SCAV1.takeDamage (CLAPTRAP.getAD());

	std::cout << std::endl;
	CLAPTRAP.printStats ();	
	SCAV1.printStats ();
	SCAV2.printStats ();

	std::cout << std::endl;
	SCAV2.beRepaired (2);
	SCAV1.guardGate ();
	CLAPTRAP.beRepaired (10);

	std::cout << std::endl;
	CLAPTRAP.printStats ();
	SCAV1.printStats ();
	SCAV2.printStats ();
	
	std::cout << std::endl;
}