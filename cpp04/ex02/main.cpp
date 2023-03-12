# include "AAnimal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "Brain.hpp"

int	main (void)
{
	int evensize = 4;
 	AAnimal	*animalArray [evensize];
//	AAnimal	*animal = new AAnimal (); -> wrong car impossible d instancier une classe abstraite
	int		arrayHalf = evensize / 2;

	for (int i = 0; i < arrayHalf; i++)
	{
		animalArray [i] = new Dog ();
		animalArray [arrayHalf + i] = new Cat ();
	}
	animalArray[evensize % 2]->makeSound ();
	animalArray[arrayHalf]->makeSound ();

	for (int i = 0; i < evensize; i++)
		delete animalArray [i];
	return 0;
}