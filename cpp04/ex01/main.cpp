# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "Brain.hpp"

int	main (void)
{
/* 	Animal	*animalArray;

	for (int i = 0; i < 5; i++)
	{
		Dog *dog = new Dog ();
		animalArray [i] = *dog;
	}
	for (int i = 5; i < 10; i++)
	{
		Cat	*cat = new Cat ();
		animalArray [i] = *cat;
	}
	for (int i = 0; i < 10; i++)
		delete *animalArray;
	delete [] animalArray;
	return (0); */
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	j->makeSound();
	i->makeSound();
	delete j;//should not create a leak
	delete i;
	return 0;
}