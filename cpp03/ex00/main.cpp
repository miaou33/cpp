#include "ClapTrap.hpp"

int	main (void)
{
	ClapTrap	Clap1 ("Clap1");
	ClapTrap	Clap2 ("Clap2");
	ClapTrap	Clap3 ("Clap3");

	std::cout << std::endl;
	Clap1.printStats ();
	Clap2.printStats ();
	Clap3.printStats ();
	std::cout << std::endl;

/* 	for (int i = 0; i < 11; i++)
		Clap1.beRepaired (1); */
	Clap1.attack ("Clap2");
	if (Clap1.getHP () && Clap1.getPP ())
		Clap2.takeDamage (Clap1.getAD ());
	Clap3.attack ("Clap1");
	if (Clap3.getHP () && Clap3.getPP ())
		Clap1.takeDamage (Clap3.getAD ());
	Clap2.beRepaired (1);

	std::cout << std::endl;
	Clap1.printStats ();
	Clap2.printStats ();
	Clap3.printStats ();
	std::cout << std::endl;
}