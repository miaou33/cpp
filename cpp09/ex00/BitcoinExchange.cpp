# include "BitcoinExchange.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

BitcoinExchange::BitcoinExchange () {}

BitcoinExchange::BitcoinExchange (char* const& input) {

		openCheckValid ("data.csv", _data);
		openCheckValid (input, _input);

		parseData ();
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

void		BitcoinExchange::parseData () {

	std::getline (_data, _line); //skip the first title line
	std::string	date_str;
	while (std::getline (_data, date_str, ',')) {
    std::tm time = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Initialiser la structure tm
    std::istringstream iss(date_str);
    int year, month, day;
    char delimiter;

    if (iss >> year >> delimiter >> month >> delimiter >> day) {
        time.tm_year = year - 1900;
        time.tm_mon = month - 1;
        time.tm_mday = day;

        std::time_t dateInSeconds = std::mktime(&time);
        throw BitcoinExchange::ParseError (name, "Wrong date");
    }

    return false; // La conversion a échoué, la date est invalide
	}
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

