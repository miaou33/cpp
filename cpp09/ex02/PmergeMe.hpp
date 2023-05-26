#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "colors.hpp"
# include <exception>
# include <list>
# include <string>
# include <iostream>
# include <vector>

class PmergeMe {

	public:

		PmergeMe ();
		PmergeMe (PmergeMe const& original);
		PmergeMe& operator= (PmergeMe const& rhs);
		~PmergeMe ();

		//Exceptions
		class Error : public std::exception {
			public:
				Error (std::string const& error_desc);
				virtual ~Error () throw ();
				virtual const char* what () const throw ();
			private:
				std::string	_errorMessage;
		};

	private:
		std::vector <int>	_vecContainer;
		std::list <int>		_listContainer;

};

# endif
