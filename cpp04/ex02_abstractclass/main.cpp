# include "AAnimal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "Brain.hpp"

int	main (void)
{
 	AAnimal	*animalArray [10];
	int		arrayHalf = 5;

	for (int i = 0; i < arrayHalf; i++)
	{
		animalArray [i] = new Dog ();
		animalArray [arrayHalf + i] = new Cat ();
	}
	
	std::cout << std::endl;
	animalArray[3]->makeSound ();
	animalArray[9]->makeSound ();
	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
		delete animalArray [i];

/*  // cannot work coz abstract class now:
	const AAnimal *	AAnimal = new AAnimal (); */
	const AAnimal *	dog = new Dog ();
	const AAnimal *	cat = new Cat ();
	
	std::cout << std::endl;
/* 	std::cout << AAnimal->getType () << "'s sound : ";
	AAnimal->makeSound (); */
	std::cout << dog->getType () << "'s sound : ";
	dog->makeSound ();
	std::cout << cat->getType () << "'s sound : ";
	cat->makeSound ();
	std::cout << std::endl;

	delete dog;
	delete cat;
//	delete AAnimal;
	
	std::cout << std::endl;
	
	Cat *	kitty1 = new Cat ();
	Cat *	kitty2 = new Cat (*kitty1);
	Cat *	kitty3 = new Cat ();
	*kitty3 = *kitty1;

	std::cout << std::endl;
	std::cout << "kitty1, kitty2, kitty3's default ideas :" << std::endl;
	kitty1->displayIdea (0);
	kitty2->displayIdea (0);
	kitty3->displayIdea (0);
	std::cout << "changing kitty1's idea to 'miaou' ..." << std::endl;
	kitty1->setIdea (0, "miaou");
	std::cout << "kitty1, kitty2, kitty3's new ideas :" << std::endl;
	kitty1->displayIdea (0);
	kitty2->displayIdea (0);
	kitty3->displayIdea (0);
	std::cout << std::endl;

	delete kitty1;
	delete kitty2;
	delete kitty3;
	return 0;
}