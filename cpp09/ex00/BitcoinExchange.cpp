# include "BitcoinExchange.hpp"

/******************************************************************************************************/
/*	*/
/******************************************************************************************************/

void	check_file (std::ifstream& file) {

	if (file.fail ()) 
		throw std::invalid_argument (strerror (errno));
	
	file.seekg (0, std::ios::end);
	if (!file.good ())
		throw std::invalid_argument ("Regular file expected");
}

