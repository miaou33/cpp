#include "Multicaster.hpp"

int	main (int ac, char **av)
{
	try {
		
		if (ac != 2)
			throw Multicaster::WrongArgument ();
		
		Multicaster	Multicaster;
		Multicaster.convert (av[1]);
	}
	
	catch (std::exception& e) {

		std::cout << e.what () << std::endl;
		return 1;
	}

	return 0;
}