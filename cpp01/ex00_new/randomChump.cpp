#include "Zombie.hpp"

void	randomChump (std::string name)
{
	Zombie	stackZomb (name);
	stackZomb.announce ();
}
