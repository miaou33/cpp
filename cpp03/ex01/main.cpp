#include "ScavTrap.hpp"

int	main (void)
{
	ClapTrap	CLAPTRAP("weakCLAPTRAP");
	ScavTrap	NESS("\033[0;31mNESS\033[0m");
	ScavTrap	PAULA("\033[0;33mPAULA\033[0m");

	PAULA.highFivesGuys ();
	NESS.attack ("PAULA");
	if (NESS.getHitPoints () && NESS.getEnergyPoints ())
		PAULA.takeDamage (NESS.getAttackDamage ());
	CLAPTRAP.takeDamage (2);
	CLAPTRAP.beRepaired (1);
	CLAPTRAP.beRepaired (1);
	CLAPTRAP.beRepaired (30);
	CLAPTRAP.beRepaired (30);
	CLAPTRAP.beRepaired (30);
	CLAPTRAP.beRepaired (30);
	CLAPTRAP.beRepaired (30);
	CLAPTRAP.beRepaired (30);
	CLAPTRAP.beRepaired (30);
	CLAPTRAP.beRepaired (30);
	CLAPTRAP.beRepaired (30);
	CLAPTRAP.beRepaired (30);
	CLAPTRAP.beRepaired (30);
	CLAPTRAP.beRepaired (30);
	CLAPTRAP.beRepaired (30);
	CLAPTRAP.beRepaired (30);
	CLAPTRAP.attack ("PAULA");
	if (CLAPTRAP.getHitPoints () && CLAPTRAP.getEnergyPoints ())
		PAULA.takeDamage (CLAPTRAP.getAttackDamage ());
	NESS.attack ("PAULA");
	if (NESS.getHitPoints () && NESS.getEnergyPoints ())
		PAULA.takeDamage (NESS.getAttackDamage ());
	PAULA.attack ("NESS");
	if (PAULA.getHitPoints () && PAULA.getEnergyPoints ())
		NESS.takeDamage (PAULA.getAttackDamage ());
	NESS.attack ("PAULA");
	if (NESS.getHitPoints () && NESS.getEnergyPoints ())
		PAULA.takeDamage (NESS.getAttackDamage ());
}