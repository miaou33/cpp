# include "BitcoinExchange.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

BitcoinExchange::BitcoinExchange () {}

BitcoinExchange::BitcoinExchange (char* const& input) {

		std::ifstream prices ("data.csv");
		std::string error = check_file (prices);
		if (!error.empty ())
			throw FileError ("data.csv", error);

		std::ifstream amount (input);
		error = check_file (amount);
		if (!error.empty ())
			throw FileError (input, error);

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

std::string		BitcoinExchange::check_file (std::ifstream& file) {

	if (file.fail ()) 
		return (strerror (errno));
	
	file.seekg (0, std::ios::end);
	if (!file.good ())
		return ("Regular file expected");

	return ("");
}

/******************************************************************************************************/
/*	EXCEPTIONS																						  */
/******************************************************************************************************/

// WRONG ARGUMENTS
const char*	BitcoinExchange::WrongArg::what () const throw () {

	return ("Format: ./btc <bitcoin price database> <amount/date database>");
}

// WRONG FILE
BitcoinExchange::FileError::FileError (std::string const& filename, std::string const& error_desc)

	: _errorMessage ("'" + filename + "' : " + error_desc) {}

BitcoinExchange::FileError::~FileError () throw () {}

const char*	BitcoinExchange::FileError::what () const throw () {

	return (_errorMessage.c_str ());
}

