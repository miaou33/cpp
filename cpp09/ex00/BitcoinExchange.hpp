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
#include <sys/stat.h>

class BitcoinExchange {

	public:
		BitcoinExchange (char* const& input_filename);
		BitcoinExchange (BitcoinExchange const& original);
		BitcoinExchange& operator= (BitcoinExchange const& rhs);
		~BitcoinExchange ();

		class WrongArg : public std::exception {

			public:
				virtual const char* what() const throw();
		};
		class FileError : public std::exception {

			public:
				FileError (std::string const& message, std::string const& error_desc);
				virtual ~FileError () throw ();
				virtual const char* what() const throw();

			private:
				std::string	_errorMessage;

		};
		class WrongInput : public std::exception {
			public: virtual const char* what() const throw(); };

	private:
		BitcoinExchange ();

		std::ifstream		_data;
		std::ifstream		_input;
		std::stringstream	_day;
		std::stringstream	_month;
		std::stringstream	_year;
		std::stringstream	_price;
		std::string			_line;
		std::string			_error;

		void				open_check (std::string const& name, std::ifstream& file);

};


# endif
