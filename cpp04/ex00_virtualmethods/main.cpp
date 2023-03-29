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
	
	std::cout << std::endl;
	std::cout << animal->getType () << "'s sound : ";
	animal->makeSound ();
	std::cout << dog->getType () << "'s sound : ";
	dog->makeSound ();
	std::cout << cat->getType () << "'s sound : ";
	cat->makeSound ();
	std::cout << std::endl;

	delete dog;
	delete cat;
	delete animal;

	std::cout << std::endl;

	// WRONG ANIMALS : non virtual methods

	const WrongAnimal *	wanimal = new WrongAnimal ();
	const WrongAnimal *	wcat = new WrongCat ();
	
	std::cout << std::endl;
	std::cout << wanimal->getType () << "'s sound : ";
	wanimal->makeSound ();
	std::cout << wcat->getType () << "'s sound : ";
	wcat->makeSound ();
	std::cout << std::endl;
	
	delete wcat;
	delete wanimal;
	
	std::cout << std::endl;

	return (0);
}