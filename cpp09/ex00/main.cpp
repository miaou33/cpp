#include "BitcoinExchange.hpp"
#include <map>
#include <sstream>
#include <string>

int	main (int ac, char **av) {

	try {
		if (ac != 2) 
			throw BitcoinExchange::WrongArg ();

		BitcoinExchange btc;
		btc.getValues (av [1]);
	}
	catch (std::exception const& e) {
		std::cerr << _RED << "Error: " << _END << e.what () << std::endl;
		return 1;
	}
	return 0;
}
