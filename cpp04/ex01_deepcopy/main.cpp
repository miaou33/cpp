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
	
	std::cout << std::endl;
	
	Cat *	kitty = new Cat ();
	Cat * kitty2 = new Cat (*kitty);
	Cat * kitty3 = new Cat ();
	*kitty3 = *kitty;
	std::cout << "kitty = " << &kitty << std::endl;
	std::cout << "kitty2 = " << &kitty2 << std::endl;
	kitty->setIdea (0, "iii");
	kitty->displayIdea (0);
	kitty2->displayIdea (0);
	kitty3->displayIdea (0);
	Animal animal ;

	delete kitty;
	delete kitty2;
	delete kitty3;
	return 0;
}