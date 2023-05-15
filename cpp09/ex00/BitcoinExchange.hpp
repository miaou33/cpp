#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <cstring>
#include <errno.h>
#include <exception>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include "colors.hpp"


class BitcoinExchange {

	public:
		BitcoinExchange (char* const& input_filename);
		BitcoinExchange (BitcoinExchange const& original);
		BitcoinExchange& operator= (BitcoinExchange const& rhs);
		~BitcoinExchange ();

		class WrongFormat : public std::exception {
			public: virtual const char* what() const throw(); };

		class WrongData {
			public:
				WrongData (std::string const& message);
				virtual ~WrongData ();
				virtual const char* what() const throw();
			private:
				std::string	_errorMessage;
		};
		class WrongInput : public std::exception {
			public: virtual const char* what() const throw(); };

	private:
		BitcoinExchange ();

		std::stringstream	_day;
		std::stringstream	_month;
		std::stringstream	_year;
		std::stringstream	_price;
		std::string			_line;


};

void	check_file (std::ifstream& file);

# endif
