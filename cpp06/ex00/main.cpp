#include "Multicaster.hpp"

int	main (int ac, char **av)
{
	try {
		
		if (ac != 2)
			throw Multicaster::WrongArgument ();
		
		Multicaster	multicaster (av[1]);
		multicaster.displayCasts ();
	}
	
	catch (std::exception& e) {

		return 1;
	}

	return 0;
}