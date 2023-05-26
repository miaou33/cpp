#include "PmergeMe.hpp"

int	main (int ac, char** av)
{
	try {
		if (ac < 2)
			throw PmergeMe::Error ("Format: ./PMergeMe <positive integer sequence>");	
		(void) av;
	}
	catch (const std::exception& e) {
		std::cout << _RED << "Error: " << _END << e.what () << std::endl;
		return 1;
	}
	return 0;
}
