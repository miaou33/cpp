#include "Zombie.hpp"

Zombie	*newZombie (std::string name)
{
	return (new Zombie (name));
}

/*
--> new uses the constructor so can take parameters if constructor does
	delete uses the destructor
*/