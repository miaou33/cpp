#include "Zombie.hpp"

int	main (void)
{
	int	N = 3;
	Zombie	*z = zombieHorde (N, "anon");

	for (int i = 0; i < N; i++)
		z[i].announce ();

	delete[] z;

	return (0);
}