# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "Brain.hpp"

int	main (void)
{
 	Animal	*animalArray [10];
	int		arrayHalf = 5;

	for (int i = 0; i < arrayHalf; i++)
	{
		animalArray [i] = new Dog ();
		animalArray [arrayHalf + i] = new Cat ();
	}
	animalArray[3]->makeSound ();
	animalArray[9]->makeSound ();

	for (int i = 0; i < 10; i++)
		delete animalArray [i];
	return 0;
}