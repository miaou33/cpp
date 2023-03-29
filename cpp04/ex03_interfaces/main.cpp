# include "AMateria.hpp"
# include "Character.hpp"
# include "MateriaSource.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

int	main (void)
{
	std::cout << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure ());

	AMateria*	tmp;

/* 	// ERROR HANDLING
	src->learnMateria(NULL);
	
	tmp = new Cure ();
	src->learnMateria(tmp);
	delete (tmp); */

	std::cout << std::endl;
	
	ICharacter* me = new Character("Me");

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

/* 	// ERROR HANDLING
	me->equip(NULL);
	
	tmp = src->createMateria("blabla");
	tmp = src->createMateria("cure");
	me->equip(tmp);
	delete tmp;
 */
	std::cout << std::endl;
	
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	std::cout << std::endl;
	
	// unequip ne delete pas donc s'en occuper dans le main
	tmp = me->getMateria (2);
	me->unequip (2);
	delete tmp;

	tmp = src->createMateria ("ice");
	me->equip (tmp);
	me->use (2, *bob);

	std::cout << std::endl;
	
	delete bob;
	delete me;
	delete src;
	return 0;
}