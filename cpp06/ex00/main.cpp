#include "Analyzer.hpp"

int	main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Format: " << av[0] << " <litteral>" << std::endl;
		return 1;
	}
	return 0;
}