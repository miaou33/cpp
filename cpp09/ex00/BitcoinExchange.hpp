#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <cstddef>
# include <cstdlib>
# include <cstring>
# include <ctime>
# include <errno.h>
# include <exception>
# include <filesystem>
# include <fstream>
# include <iostream>
# include <limits>
# include <map>
# include <stdexcept>
# include <string>
# include <sstream>
# include <sys/stat.h>
# include "colors.hpp"

class BitcoinExchange {

	public:
		// CONSTR/DESTR----------------------------------------------
		BitcoinExchange ();
		BitcoinExchange (BitcoinExchange const& original);
		BitcoinExchange& operator= (BitcoinExchange const& rhs);
		~BitcoinExchange ();

		// METHODS---------------------------------------------------
		std::map<std::string, float> const&	getPriceMap () const;
		void								getValues (char* const& arg);

		// EXCEPTIONS------------------------------------------------
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
		// P.VARIABLES-----------------------------------------------
		std::map<std::string, float>	_priceMap;

		// P.METHODS-------------------------------------------------
		void				openCheckValid (std::string const& name, std::ifstream& file);
		void				fillMap (std::string const& filename, std::ifstream& file);
		void				fillPriceMap ();
		void				checkDate (std::string date_str, std::string filename);
		float				getPrice (std::string const& date_str);
		float				getValue (std::string const& value_str, std::string const& filename);
};


# endif
