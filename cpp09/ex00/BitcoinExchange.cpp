# include "BitcoinExchange.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

BitcoinExchange::BitcoinExchange () {}

BitcoinExchange::BitcoinExchange (char* const& input) {

		_error = "";

		open_check ("data.csv", _data);
		open_check (input, _input);

		while (std::getline (_data, _line))
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

void		BitcoinExchange::open_check (std::string const& name, std::ifstream& file) {

	file.open (name.c_str ());

	if (file.fail ()) 
		throw FileError (name, strerror (errno));
	
	struct stat fileInfo;
    if (stat(name.c_str(), &fileInfo) == 0)
		throw FileError (name, "Regular file expected");
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

