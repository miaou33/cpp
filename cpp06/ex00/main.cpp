#include "Analyzer.hpp"

int	main (int ac, char **av)
{
	try {
		
		if (ac != 2)
			throw Analyzer::WrongArgument ();
		
		Analyzer	analyzer;
		analyzer.findType (av[1]);
		std::cout << av[1] << std::endl;
	
	}
	
	catch (std::exception& e) {

		std::cout << e.what () << std::endl;
		return 1;
	}

	return 0;
}