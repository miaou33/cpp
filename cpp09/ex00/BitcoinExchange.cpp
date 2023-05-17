# include "BitcoinExchange.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

BitcoinExchange::BitcoinExchange () {}

BitcoinExchange::BitcoinExchange () {

	std::ifstream		data;

	openCheckValid ("data.csv", data);
	fillExchangeRateMap ();
	data.close ();
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

void		BitcoinExchange::fillExchangeRateMap () {

	std::ifstream	data;
	std::string		line;
	std::string 	date;
	char			coma;
	double			exchange_rate;
	size_t			sep_pos;
	
	std::getline (data, line); //skip the first title line
	while (std::getline (data, line))
	{
		std::istringstream	iss (line);
		if (!(iss >> date >> coma >> exchange_rate))
			throw std::runtime_error ("Problem occured while parsing data.csv\n--> Please verify file is not corrupted");
		_priceMap [date] = exchange_rate;
	}
}

void		BitcoinExchange::getValues (char* const& arg) {

	std::ifstream	input;
	std::string		line;
	std::string 	date_str;
	std::string 	amount_str;
	size_t			sep_pos;
	
	openCheckValid (arg, input);
	std::getline (file, line); //skip the first title line
	while (std::getline (file, line))
	{
		sep_pos = line.find (sep);
		date_str = line.substr (0, sep_pos);
		amount_str = line.substr (sep_pos + sep.length ());
		try {
			checkDate (date_str, filename);
			price = getValue (amount_str, filename);
		}
		catch (BitcoinExchange::ParseError& e) {
			std::cout << e.what () << std::endl;
		}
	}
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


float		BitcoinExchange::getValue (std::string const& amount_str, std::string const& filename) {

	if (amount_str.find_first_not_of ("01234567890.-") != std::string::npos)
		throw BitcoinExchange::ParseError (filename, "Error: bad input => ", amount_str);

    size_t found = amount_str.find_first_of ('.');
    if (found != std::string::npos && (amount_str.find_last_of ('.') != found))
		throw BitcoinExchange::ParseError (filename, "Error: bad input => ", amount_str);
	
	found = amount_str.find_first_of ('-');
	if (found != std::string::npos && (found != 0 || amount_str.find_last_of ('-') != found))
		throw BitcoinExchange::ParseError (filename, "Error: bad input => ", amount_str);

    char *p;
    double n = std::strtof (amount_str.c_str (), &p);
    if (errno == ERANGE || n > std::numeric_limits<float>::max ())
		throw BitcoinExchange::ParseError (filename, "Error: bad input => ", amount_str);
	if (n < 0)
		throw BitcoinExchange::ParseError (filename, "Error: not a positive number => ", amount_str);
	//if (filename != "data.csv" && n > 1000)
	//	throw BitcoinExchange::ParseError (filename, "Error: too large value => ", amount_str);
    return n;
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

