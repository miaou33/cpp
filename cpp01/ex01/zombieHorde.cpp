#include "Zombie.hpp"

Zombie	*zombieHorde (int N, std::string name)
{
	Zombie	*z = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		z[i].addName (name);
	}
	return (z);
	
/* 	while (N--)
	{
		*Z
	} */
/* 	Zombie	Z[N];
	
	for (int i = N; i > 0; i--)
	{
		Z[i] = new Zombie (name);
	}
	return (Z[0]); */

}