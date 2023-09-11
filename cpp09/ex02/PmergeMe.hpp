#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <algorithm>
# include <cmath>
# include <exception>
# include <iostream>
# include <iterator>
# include <limits>
# include <list>
# include <string>
# include <vector>

# include "colors.hpp"

enum {
	VEC,
	LST
};

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(PmergeMe const& rhs);
		PmergeMe& operator=(PmergeMe const& rhs);
		~PmergeMe();

		std::vector<int>	getVec() const;
		std::list<int>		getLst() const;
		clock_t				getStartTime(int const& index) const;
		clock_t				getEndTime(int const& index) const;

        void                checkArgs(int ac, char **av);
        void                sort(int ac, char **av);

		class Error : public std::exception {
			public:
				Error (std::string const& error_desc);
				virtual ~Error () throw ();
				virtual const char* what () const throw ();
			private:
				std::string	_errorMessage;
		};

	private:
		std::vector<int>	_vec;
		std::list<int>		_lst;

		clock_t				_startTime[2];
		clock_t 			_endTime[2];

		void				_sortVec(std::vector<int> &X);
		void				_sortLst(std::list<int> &X);

        void                _sortHalfVec(std::vector<int> &S, std::vector<int> &remaining, const std::vector<int> &X);
        void                _sortHalfLst(std::list<int> &S, std::list<int> &remaining, const std::list<int> &X);

		void				_printVec(std::vector<int> const& X);
		void				_printLst(std::list<int> const& X);

		bool				_isPositiveNumeric (std::string const& s);
};	

#endif
