#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main (void)
{
	int i = 0;
	ClapTrap	CLAPTRAP("CLAPTRAP");
	ScavTrap	NESS("\033[0;31mNESS\033[0m");
	ScavTrap	PAULA("\033[0;33mPAULA\033[0m");
	FragTrap	FRAGTRAP("FRAGTRAP");

	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i << END << std::endl;
	FRAGTRAP.highFivesGuys ();
	PAULA.guardGate ();
	NESS.attack ("PAULA");
	if (NESS.getHP () && NESS.getPP ())
		PAULA.takeDamage (NESS.getAD ());
	CLAPTRAP.attack ("NESS");
	if (CLAPTRAP.getHP () && CLAPTRAP.getPP ())
		NESS.takeDamage (CLAPTRAP.getAD());
	
	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i <<  END <<std::endl;
	FRAGTRAP.attack ("PAULA");
	if (FRAGTRAP.getHP () && FRAGTRAP.getPP ())
		PAULA.takeDamage (FRAGTRAP.getAD ());
	PAULA.beRepaired (2);
	NESS.guardGate ();
	CLAPTRAP.beRepaired (1);
	
	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i <<  END << std::endl;
	FRAGTRAP.beRepaired (2);
	PAULA.attack ("NESS");
	if (PAULA.getHP () && PAULA.getPP ())
		NESS.takeDamage (PAULA.getAD ());
	NESS.attack ("PAULA");
	if (NESS.getHP () && NESS.getPP ())
		PAULA.takeDamage (NESS.getAD ());
	CLAPTRAP.beRepaired (1);

	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i <<  END << std::endl;
	FRAGTRAP.highFivesGuys ();
	PAULA.attack ("NESS");
	if (PAULA.getHP () && PAULA.getPP ())
		NESS.takeDamage (PAULA.getAD ());
	NESS.attack ("PAULA");
	if (NESS.getHP () && NESS.getPP ())
		PAULA.takeDamage (NESS.getAD ());
	CLAPTRAP.beRepaired (1);

	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i <<  END << std::endl;
	FRAGTRAP.highFivesGuys ();
	PAULA.attack ("FRAGTRAP");
	if (PAULA.getHP () && PAULA.getPP ())
		FRAGTRAP.takeDamage (PAULA.getAD ());
	NESS.attack ("PAULA");
	if (NESS.getHP () && NESS.getPP ())
		PAULA.takeDamage (NESS.getAD ());
	CLAPTRAP.beRepaired (1);

	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i <<  END << std::endl;
	FRAGTRAP.highFivesGuys ();
	PAULA.attack ("NESS");
	if (PAULA.getHP () && PAULA.getPP ())
		NESS.takeDamage (PAULA.getAD ());
	NESS.attack ("PAULA");
	if (NESS.getHP () && NESS.getPP ())
		PAULA.takeDamage (NESS.getAD ());
	CLAPTRAP.beRepaired (1);

	std::cout << std::endl;
	std::cout << UNDER << "ROUND " << ++i <<  END << std::endl;
	FRAGTRAP.highFivesGuys ();
	PAULA.attack ("NESS");
	if (PAULA.getHP () && PAULA.getPP ())
		NESS.takeDamage (PAULA.getAD ());
	NESS.guardGate ();
	CLAPTRAP.beRepaired (1);

	std::cout << std::endl;
}