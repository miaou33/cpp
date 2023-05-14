#include "BitcoinExchange.hpp"

//void	parse_file (std::ifstream& file, std::string sep) {
//
//
//}

int	main (int ac, char **av) {

	if (ac != 2) {
		std::cerr << _RED << "Error: " << _END << "Format: ./btc <bitcoin price database> <amount/date database>" << std::endl;
		return 1;
	}
	try {
		std::ifstream prices ("data.csv");
		check_file (prices);
	}
	catch (const std::exception& e) {
		std::cerr << _RED << "Error: " << _END << "data.csv: " << e.what () << std::endl;
		return 1;
	}
	try {
		std::ifstream amount (av[1]);
		check_file (amount);
	}
	catch (const std::exception& e) {
		std::cerr << _RED << "Error: " << _END << e.what () << std::endl;
		return 1;
	}
	return 0;
}
