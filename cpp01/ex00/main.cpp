#include "Zombie.hpp"

int	main (void)
{
	randomChump ("stackZomb");

	std::cout << std::endl;
	
	Zombie	*z = newZombie("heapZomb");
	z->announce();
	delete z;

	return (0);
}