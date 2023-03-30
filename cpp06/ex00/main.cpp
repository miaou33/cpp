#include "Analyzer.hpp"

int	main (int ac, char **av)
{
	try {
		
		if (ac != 2)
			throw Analyzer::WrongArgument ();
		
		Analyzer	analyzer;
		analyzer.convert (av[1]);
		analyzer.print ();
	}
	
	catch (std::exception& e) {

		std::cout << e.what () << std::endl;
		return 1;
	}

	return 0;
}