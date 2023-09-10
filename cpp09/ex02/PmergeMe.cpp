# include "PmergeMe.hpp"

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::CONSTRUCTORS

PmergeMe::PmergeMe () {}

PmergeMe::PmergeMe (PmergeMe const& original) { *this = original; }

PmergeMe& PmergeMe::operator= (PmergeMe const& rhs) { if (this != &rhs) {} return *this; }

PmergeMe::~PmergeMe () {}


//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::METHODS

void	PmergeMe::sort (int ac, char** av) {

	fillContainers (ac, av);
	displayBefore ();

	double vecTime = vec_merge_insert_sort (_vecContainer, 0, _vecContainer.size () - 1);
	std::cout << _GREEN << "Sorted vector: " << _END;
	displayContainer (_vecContainer);
	std::cout << "Time to process a range of " << _vecContainer.size () << " elements with std::vector: " << vecTime << " us" << std::endl;

//	std::cout << std::endl;
//
//	double listTime = lstMergeInsertionSort (_listContainer, _listContainer.begin (), _listContainer.end ());
//	std::cout << _GREEN << "Sorted list: " << _END;
//	displayContainer (_listContainer);
//	std::cout << "Time to process a range of " << _listContainer.size () << " elements with std::list: " << listTime << " us" << std::endl;

}

void	PmergeMe::fillContainers (int ac, char** av) {

	for (int i = 1; i < ac; ++i)
	{
		if (!isPositiveNumeric (av [i]))
			throw PmergeMe::Error ("Invalid input. Only positive integers are allowed.");

		long long num = std::atoll (av [i]);
		if (num == 0 || num > std::numeric_limits <int>::max ())
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

	std::cout << _PURPLE << "Before: " << _END << std::endl;
	std::cout << "- Vector: ";
	displayContainer (_vecContainer);
//	std::cout << "- List  : ";
//	displayContainer (_listContainer);
//	std::cout << std::endl;
}


//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::EXCEPTIONS

PmergeMe::Error::Error (std::string const& error_desc)

	: _errorMessage (error_desc) {
}

PmergeMe::Error::~Error () throw () {}

const char*	PmergeMe::Error::what () const throw () {

	return (_errorMessage.c_str ());
}
