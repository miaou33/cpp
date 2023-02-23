#include "ScavTrap.hpp"

int	main (void)
{
	int i = 0;
	ClapTrap	CLAPTRAP("\033[0;33mCLAPT\033[0m");
	ScavTrap	SCAV1("\033[0;31mSCAV1\033[0m");
	ScavTrap	SCAV2("\033[0;31mSCAV2\033[0m");
	
	std::cout << std::endl;
	std::cout << CLAPTRAP << std::endl;
	std::cout << SCAV1 << std::endl;
	std::cout << SCAV2 << std::endl;
	
	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i << std::endl;
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
	std::cout << CLAPTRAP << std::endl;	
	std::cout << SCAV1 << std::endl;
	std::cout << SCAV2 << std::endl;

	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i <<  std::endl;
	SCAV2.beRepaired (2);
	SCAV1.guardGate ();
	CLAPTRAP.beRepaired (10);

	std::cout << std::endl;
	std::cout << CLAPTRAP << std::endl;
	std::cout << SCAV1 << std::endl;
	std::cout << SCAV2 << std::endl;
	
	std::cout << std::endl;
}