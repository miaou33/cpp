#include "ClapTrap.hpp"

int	main (void)
{
	ClapTrap	Ness("Ness");
	ClapTrap	Paula("Paula");
	ClapTrap	Jeff("Jeff");
	ClapTrap 	NessClone (Ness);
	ClapTrap	PaulaClone ("PaulaClone");
	PaulaClone = Paula;

	Ness.attack ("Paula");
	Paula.takeDamage (Ness.getAttackDamage ());
	Paula.
}