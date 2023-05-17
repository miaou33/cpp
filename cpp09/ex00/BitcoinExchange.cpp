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

void		BitcoinExchange::fillPriceMap () {

	std::ifstream		data;
	std::string			line;
	std::string 		date;
	std::string			exchange_rate_str;
	double				exchange_rate;
	static std::string	date_fmt = "XXXX-XX-XX";
	static size_t		date_fmt_sz = date_fmt.length ();
	
	openCheckValid ("data.csv", data);
	std::getline (data, line); //skip the first title line
	while (std::getline (data, line))
	{
		date = line.substr (0, date_fmt_sz - 1);
		std::cout << date << " ";//------------------------debug
		exchange_rate_str = line.substr (date_fmt_sz + 1);
		std::istringstream iss (exchange_rate_str);
		iss >> exchange_rate;
		std::cout << exchange_rate << std::endl;//------------------------debug
        _priceMap.insert (std::make_pair (date, exchange_rate));
	}
	data.close ();
}

void		BitcoinExchange::getValues (char* const& arg) {

	std::ifstream	input;
	std::string		line;
	std::string 	date_str;
	std::string 	amount_str;
	float			value;
	double			price;
	size_t			sep_pos;
	
	fillPriceMap ();

	openCheckValid (arg, input);
	std::getline (input, line); //skip the first title line
	while (std::getline (input, line))
	{
		sep_pos = line.find (" | ");
		date_str = line.substr (0, sep_pos);
		amount_str = line.substr (sep_pos + 3);
		try {
			checkDate (date_str, arg);
			value = getValue (amount_str, arg);
			price = getPrice (date_str);
			std::cout << date_str << " => " << value << " = " << value * price << std::endl;
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

    size_t	found_point = amount_str.find_first_of ('.');
	size_t	found_dash = amount_str.find_first_of ('-');

	if (amount_str.find_first_not_of ("01234567890.-") != std::string::npos
		|| (found_point != std::string::npos && (amount_str.find_last_of ('.') != found_point))
		|| (found_dash != std::string::npos && (found_dash != 0 || amount_str.find_last_of ('-') != found_dash)))
	{
		throw BitcoinExchange::ParseError (filename, "Error: bad input => ", amount_str);
	}	

    float value = std::strtof (amount_str.c_str (), NULL);
	if (value < 0)
		throw BitcoinExchange::ParseError (filename, "Error: not a positive number => ", amount_str);
    if (value > 1000)
		throw BitcoinExchange::ParseError (filename, "Error: too large number", amount_str);
    return value;
}


float		BitcoinExchange::getPrice (std::string const& date_str) const {

	std::map<std::string, float>::const_iterator it = _priceMap.begin ();
	std::map<std::string, float>::const_iterator ite = _priceMap.end ();
	//typedef std::map<std::string, float>::iterator const_iterator;
	
	(void)it;
	(void)ite;
	//f = _priceMap.find (date_str);
	//if (f != ite)
	//	return f->second;
	return 0;
	//if (find 
	//std::map<std::string, float>::iterator it = _priceMap.begin ();
	//std::map<std::string, float>::iterator ite = _priceMap.end ();

	//while (it != ite)
	//{
	//	if (it->first == date_str)
	//}
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

