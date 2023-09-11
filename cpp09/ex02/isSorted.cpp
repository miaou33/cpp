#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
#include <string>
#include <vector>

#include "colors.hpp"

int main (int ac , char **av)
{
	std::vector<int> X;
	std::transform(av + 1, av + ac, std::back_inserter(X), std::atoi);

	std::cout << std::endl;

	std::is_sorted (X.begin(), X.end()) 
		? std::cout << _YELLOW << "Sorted !" << _END
		: std::cout << _YELLOW << "Not sorted!" << _END;

	std::cout << std::endl;

	return 0;
}