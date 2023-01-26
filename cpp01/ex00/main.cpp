#include "Zombie.hpp"

int	main (void)
{
	Zombie	*z = newZombie("heapZomb");
	randomChump ("stackZomb");
	z->announce();
	delete z;
	return (0);
}