# include "BitcoinExchange.hpp"
#include <cstdlib>

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

BitcoinExchange::BitcoinExchange () {}

BitcoinExchange::BitcoinExchange (char* const& input) {

	openCheckValid ("data.csv", _data);
	openCheckValid (input, _input);

	std::getline (_data, _line); //skip the first title line
	std::string	line;
	std::string date_str;
	std::string price_str;
	size_t		sep_pos;
	while (std::getline (_data, line))
	{
		sep_pos = line.find (',');
		date_str = line.substr (0, sep_pos);
		price_str = line.substr (sep_pos + 1);
		try {
			checkDate (date_str, "data.csv");
			//checkPrice (price_str, "data.csv");
			std::cout << "date OK! " << date_str << std::endl;
		}
		catch (BitcoinExchange::ParseError& e) {
			std::cout << e.what () << std::endl;
		}
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

void		BitcoinExchange::openCheckValid (std::string const& name, std::ifstream& file) {

	file.open (name.c_str ());

	if (file.fail ()) 
		throw FileError (name, strerror (errno));
	
	struct stat fileInfo;
    if (stat(name.c_str(), &fileInfo) == 0 && S_ISDIR (fileInfo.st_mode))
		throw FileError (name, "Regular file expected");
}

void		BitcoinExchange::checkDate (std::string date_str, std::string filename) {

    std::istringstream iss(date_str);
    int year, month, day;
    char delimiter1;
    char delimiter2;

    if (iss >> year >> delimiter1 >> month >> delimiter2 >> day)
	{
		if (delimiter1 == '-' && delimiter2 == '-' &&
			year >= 2009 && month >= 1 && month <= 12 && day >= 1 && day <= 31 && 
			!((month == 4 || month == 6 || month == 9 || month == 11) && day > 30))
		{
			if (month == 2) {
				bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
				if ((isLeapYear && day > 29) || (!isLeapYear && day > 28)) {
					throw BitcoinExchange::ParseError(filename, "Error: bad input => ", date_str);
				}
			}
			return ;
		}
	}
	throw BitcoinExchange::ParseError (filename, "Error: bad input => ", date_str);
}

void		BitcoinExchange::checkPrice (std::string price_str) {

	if (price_str.find_first_not_of ("01234567890.-") != std::string::npos)
		throw BitcoinExchange::ParseError ("data.csv", "Error: bad input => ", price_str);
		
	//if (price < 0)
	if (std::strtof (price_str.c_str (), NULL))
		return ;

}

bool		BitcoinExchange::double_lex (std::string const& s) {

    size_t    found;

    if ((found = s.find_first_of ('.')) != std::string::npos && (s.find_last_of ('.') != found))
        return false;
    }
    return false;
}

bool		BitcoinExchange::int_lex (std::string const& s) {

    char *p;
    long n = std::strtol (s.c_str (), &p, 10);

    if (errno == ERANGE || n < std::numeric_limits<int>::min ()
                        || n > std::numeric_limits<int>::max ())
    {
        throw ScalarConverter::OutOfRangeValue ();
    }
    return true;
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

// PARSE ERROR
BitcoinExchange::ParseError::ParseError (std::string const& filename, std::string const& error_desc, std::string const& error_source)

	: _errorMessage ("'" + filename + "' : " + error_desc + error_source) {}

BitcoinExchange::ParseError::~ParseError () throw () {}

const char*	BitcoinExchange::ParseError::what () const throw () {

	return (_errorMessage.c_str ());
}

