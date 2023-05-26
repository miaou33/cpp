#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "colors.hpp"
# include <cstdlib>
# include <exception>
# include <limits>
# include <list>
# include <string>
# include <iostream>
# include <vector>

class PmergeMe {

	public:
		static void	sort (int ac, char** av);

		class Error : public std::exception {
			public:
				Error (std::string const& error_desc);
				virtual ~Error () throw ();
				virtual const char* what () const throw ();
			private:
				std::string	_errorMessage;
		};

	private:
		PmergeMe ();
		PmergeMe (PmergeMe const& original);
		PmergeMe& operator= (PmergeMe const& rhs);
		~PmergeMe ();

		static bool 				isPositiveNumeric (std::string const& s);
		static void					fillContainers (int ac, char** av);
		static void					displayBefore ();
		template <typename Container>
		static void					displayContainer (Container& c) {
			
			for (typename Container::const_iterator it = c.begin (); it != c.end (); ++it)
				std::cout << *it << " ";
			std::cout << std::endl;
		}
		static double				vecMergeInsertionSort (int left, int right);
		static void					vecInsertionSort (int left, int right);

		static const int			_insertionThreshold = 10;
		static std::vector <int>	_vecContainer;
		static std::list <int>		_listContainer;

};

# endif
