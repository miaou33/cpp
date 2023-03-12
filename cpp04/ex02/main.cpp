# include "AAnimal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "Brain.hpp"

int	main (void)
{
	int evensize = 4;
 	AAnimal	*animalArray [evensize];
	int		arrayHalf = evensize / 2;

	for (int i = 0; i < arrayHalf; i++)
	{
		animalArray [i] = new Dog ();
		animalArray [arrayHalf + i] = new Cat ();
	}
	animalArray[arrayHalf - 1]->makeSound ();
	animalArray[arrayHalf + 1]->makeSound ();

	for (int i = 0; i < 10; i++)
		delete animalArray [i];
	return 0;
}