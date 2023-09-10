#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cmath>
# include <cstdlib>
# include <exception>
# include <iostream>
# include <limits>
# include <list>
# include <string>
# include <vector>

# include "colors.hpp"
# include "sort.hpp"

class PmergeMe {

	public:

		PmergeMe ();
		PmergeMe (PmergeMe const& original);
		PmergeMe& operator= (PmergeMe const& rhs);
		~PmergeMe ();

		void	sort (int ac, char** av);

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

		bool	isPositiveNumeric (std::string const& s);
		void	fillContainers (int ac, char** av);
		void	displayBefore ();

		template <typename Container>
		void	displayContainer (Container& c) {
			
			for (typename Container::const_iterator it = c.begin (); it != c.end (); ++it)
				std::cout << *it << " ";
			std::cout << std::endl;
		}


};

# endif
