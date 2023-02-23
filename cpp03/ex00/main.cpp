#include "ClapTrap.hpp"

int	main (void)
{
	ClapTrap	Ness("Ness");
	ClapTrap	Paula("Paula");
	ClapTrap	Jeff("Jeff");

	Ness.attack ("Paula");
	Paula.takeDamage (Ness.getAD ());
	Paula.beRepaired (2);
	Jeff.attack ("Ness");
	Ness.takeDamage (Jeff.getAD ());

}