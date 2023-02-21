#include "ScavTrap.hpp"

int	main (void)
{
	ScavTrap	NESS("\033[0;31mNESS\033[0m");
	ScavTrap	PAULA("\033[0;33mPAULA\033[0m");

	NESS.attack ("PAULA");
	if (NESS.getHitPoints () && NESS.getEnergyPoints ())
		PAULA.takeDamage (NESS.getAttackDamage ());
	PAULA.beRepaired (30);
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