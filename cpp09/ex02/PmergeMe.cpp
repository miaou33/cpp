# include "PmergeMe.hpp"

/******************************************************************************************************/
/*	CONSTRUCTOR DESTRUCTOR ASSIGNMENT OPERATOR														  */
/******************************************************************************************************/

std::vector <int>	PmergeMe::_vecContainer = std::vector <int> ();
std::list <int>		PmergeMe::_listContainer = std::list <int> ();

PmergeMe::PmergeMe () {}

PmergeMe::PmergeMe (PmergeMe const& original) { *this = original; }

PmergeMe& PmergeMe::operator= (PmergeMe const& rhs) { if (this != &rhs) {} return *this; }

PmergeMe::~PmergeMe () {}

/******************************************************************************************************/
/*	*/
/******************************************************************************************************/

void	PmergeMe::sort (int ac, char** av) {

	fillContainers (ac, av);
	displayBefore ();
}

void	PmergeMe::fillContainers (int ac, char** av) {

	for (int i = 1; i < ac; ++i) {
		if (!isPositiveNumeric (av [i]))
			throw PmergeMe::Error ("Invalid input. Only positive integers are allowed.");
		long long num = std::atoll(av [i]);
		if (num > std::numeric_limits <int>::max ())
			throw PmergeMe::Error ("Invalid input. Only positive integers are allowed.");
		int elem = static_cast <int> (num);
		_vecContainer.push_back (elem);
		_listContainer.push_back (elem);
	}
}

bool PmergeMe::isPositiveNumeric (std::string const& s) {
    return (s.find_first_not_of ("0123456789") == std::string::npos);
}

void	PmergeMe::displayBefore () {

	std::cout << "Before: ";
	displayContainer (_vecContainer);
}

void	PmergeMe::displayAfter () {}

/******************************************************************************************************/
/*	EXCEPTIONS																						  */
/******************************************************************************************************/

PmergeMe::Error::Error (std::string const& error_desc)

	: _errorMessage (error_desc) {
}

PmergeMe::Error::~Error () throw () {}

const char*	PmergeMe::Error::what () const throw () {

	return (_errorMessage.c_str ());
}
