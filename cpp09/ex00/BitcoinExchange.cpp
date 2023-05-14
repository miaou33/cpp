# include "BitcoinExchange.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

BitcoinExchange::BitcoinExchange () {}

BitcoinExchange::BitcoinExchange (BitcoinExchange const& original) { *this = original; }

BitcoinExchange& BitcoinExchange::operator= (BitcoinExchange const& rhs) {

	if (this != &rhs)
	{

	}
	return *this;
}

BitcoinExchange::~BitcoinExchange () {}

/******************************************************************************************************/
/*	GETTERS SETTERS																	  				  */
/******************************************************************************************************/

/******************************************************************************************************/
/*	OTHER MB FUNCTIONS																				  */
/******************************************************************************************************/

void	check_file (std::ifstream& file) {

	if (file.fail ()) 
		throw std::invalid_argument (strerror (errno));
	
	file.seekg (0, std::ios::end);
	if (!file.good ())
		throw std::invalid_argument ("Regular file expected");
}

