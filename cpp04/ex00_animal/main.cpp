# include "Animal.hpp"
# include "WrongAnimal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"

int	main (void)
{
	const Animal *	animal = new Animal ();
	const Animal *	dog = new Dog ();
	const Animal *	cat = new Cat ();
	
	std::cout << animal->getType () << "'s sound :\n\t";
	animal->makeSound ();
	std::cout << dog->getType () << "'s sound :\n\t";
	dog->makeSound ();
	std::cout << cat->getType () << "'s sound :\n\t";
	cat->makeSound ();

	delete dog;
	delete cat;
	delete animal;

	std::cout << std::endl;

	// WRONG ANIMALS : non virtual methods

	const WrongAnimal *	wanimal = new WrongAnimal ();
	const WrongAnimal *	wcat = new WrongCat ();
	
	std::cout << wanimal->getType () << "'s sound :\n\t";
	wanimal->makeSound ();
	std::cout << wcat->getType () << "'s sound :\n\t";
	wcat->makeSound ();
	
	delete wcat;
	delete wanimal;
	
	std::cout << std::endl;

	return (0);
}