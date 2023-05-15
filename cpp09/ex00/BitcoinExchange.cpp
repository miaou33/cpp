# include "BitcoinExchange.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

BitcoinExchange::BitcoinExchange () {}

BitcoinExchange::BitcoinExchange (char* const& input) {

		std::ifstream prices ("data.csv");
		check_file (prices);
		std::ifstream amount (input);
		check_file (amount);

		while (std::getline (prices, _line))
		{
			_day << _line;
			std::cout << _day.str () << std::endl;
			_month << _line;
			std::cout << _month.str () << std::endl;
			_year << _line;
			std::cout << _year.str () << std::endl;
			_price << _line;
			std::cout << _price.str () << std::endl;
		}
}

BitcoinExchange::BitcoinExchange (BitcoinExchange const& original) { *this = original; }

BitcoinExchange& BitcoinExchange::operator= (BitcoinExchange const& rhs) {

	if (this != &rhs)
	{

	}
	return *this;
}

BitcoinExchange::~BitcoinExchange () {}

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

/******************************************************************************************************/
/*	EXCEPTIONS																						  */
/******************************************************************************************************/
BitcoinExchange::WrongData (std::string const& message) : BitcoinExchange::WrongData::_errorMessage (message + "") {}

const char*	BitcoinExchange::WrongFormat::what () const throw () {

	return ("Format: ./btc <bitcoin price database> <amount/date database>");
}

const char*	BitcoinExchange::WrongData::what () const throw () {

	return ("Invalid data file: ");
}

const char*	BitcoinExchange::WrongInput::what () const throw () {

	return ("Invalid input file: ");
}
