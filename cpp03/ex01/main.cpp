#include "ClapTrap.hpp"

int	main (void)
{
	ClapTrap	Ness("Ness");
	ClapTrap	Paula("Paula");
	ClapTrap	Jeff("Jeff");

	Ness.attack ("Paula");
	Paula.takeDamage (Ness.getAttackDamage ());
	Paula.beRepaired (2);
	Jeff.attack ("Ness");
	Ness.takeDamage (Jeff.getAttackDamage ());
	Ness.attack ("Jeff");
	Jeff.takeDamage (Ness.getAttackDamage ());
	Ness.attack ("Jeff");
	Jeff.takeDamage (Ness.getAttackDamage ());
	Ness.attack ("Jeff");
	Jeff.takeDamage (Ness.getAttackDamage ());
	Ness.attack ("Jeff");
	Jeff.takeDamage (Ness.getAttackDamage ());
	Ness.attack ("Jeff");
	Jeff.takeDamage (Ness.getAttackDamage ());
	Ness.attack ("Jeff");
	Jeff.takeDamage (Ness.getAttackDamage ());
	Ness.attack ("Jeff");
	Jeff.takeDamage (Ness.getAttackDamage ());
	Ness.attack ("Jeff");
	Jeff.takeDamage (Ness.getAttackDamage ());
	Ness.attack ("Jeff");
	Jeff.takeDamage (Ness.getAttackDamage ());
	Ness.attack ("Jeff");
	Jeff.takeDamage (Ness.getAttackDamage ());
	Ness.attack ("Jeff");
	Jeff.takeDamage (Ness.getAttackDamage ());
}