#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <iostream>

class PmergeMe {

	public:

		PmergeMe ();
		PmergeMe (PmergeMe const& original);
		PmergeMe& operator= (PmergeMe const& rhs);
		~PmergeMe ();

	private:

};

# endif
