#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <cstring>
#include <ctime>
#include <errno.h>
#include <exception>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <sys/stat.h>
#include "colors.hpp"

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
		class ParseError : public std::exception {

			public:
				ParseError (std::string const& message, std::string const& error_desc, std::string const& error_source);
				virtual ~ParseError () throw ();
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

		void				openCheckValid (std::string const& name, std::ifstream& file);
		void				checkDate (std::string date_str, std::string filename);
		void				checkPrice (std::string price_str);

};


# endif
