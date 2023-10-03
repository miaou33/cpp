#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# define _END "\033[0m"
# define _BOLD  "\033[1m"
# define _UNDER  "\033[4m"
# define _REV  "\033[7m"

# define _GREY  "\033[30m"
# define _RED  "\033[31m"
# define _GREEN  "\033[32m"
# define _YELLOW  "\033[33m"
# define _BLUE  "\033[34m"
# define _PURPLE  "\033[35m"
# define _CYAN  "\033[36m"
# define _WHITE  "\033[37m"

# include <algorithm>
# include <cmath>
# include <exception>
# include <iostream>
# include <iterator>
# include <limits>
# include <list>
# include <string>
# include <vector>

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
