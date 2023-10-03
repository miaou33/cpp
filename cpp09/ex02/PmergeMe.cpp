#include "PmergeMe.hpp"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::CANONICAL

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const& rhs) {

	*this = rhs;
}

PmergeMe& PmergeMe::operator=(PmergeMe const& rhs) {

	if (this != &rhs)
	{
		this->_vec = rhs.getVec ();
		this->_lst = rhs.getLst ();
		this->_startTime[VEC] = rhs.getStartTime(VEC);
		this->_endTime[VEC] = rhs.getEndTime(VEC);
		this->_startTime[LST] = rhs.getStartTime(LST);
		this->_endTime[LST] = rhs.getEndTime(LST);
	}
	return *this;
}

PmergeMe::~PmergeMe() {

}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::GETTERS

std::vector<int> PmergeMe::getVec() const { return this->_vec; }

std::list<int> PmergeMe::getLst() const { return this->_lst; }

clock_t PmergeMe::getStartTime(int const& index) const { return this->_startTime[index]; }

clock_t PmergeMe::getEndTime(int const& index) const { return this->_endTime[index]; }

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::EXCEPTIONS

PmergeMe::Error::Error (std::string const& error_desc)

	: _errorMessage (error_desc) {
}

PmergeMe::Error::~Error () throw () {}

const char*	PmergeMe::Error::what () const throw () {

	return (_errorMessage.c_str ());
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::SORT

void PmergeMe::sort(int ac, char **av) {

    std::transform(av + 1, av + ac, std::back_inserter(_vec), std::atoi);
	std::transform(av + 1, av + ac, std::back_inserter(_lst), std::atoi);

	_vec.resize(ac - 1);
	_lst.resize(ac - 1);

	std::cout << std::endl;
    std::cout << _BLUE << "Before: " << _END << std::endl;
    this->_printVec(_vec);
    this->_printLst(_lst);

    this->_sortVec(_vec);
    this->_sortLst(_lst);

	std::cout << std::endl;
    std::cout << _BLUE << "After: " << _END << std::endl;
    this->_printVec(_vec);
    this->_printLst(_lst);
	std::cout << std::endl;

    std::cout	<< _YELLOW << "Time to process a range of " << _vec.size() << " elements with std::vector: "
				<< this->_endTime[VEC] - this->_startTime[VEC] << " us"  << _END << std::endl;
    std::cout	<< _GREEN << "Time to process a range of " << _lst.size() << " elements with std::list:   "
				<< this->_endTime[LST] - this->_startTime[LST] << " us"  << _END << std::endl; 
}

void    PmergeMe::_sortHalfVec(std::vector<int> &S, std::vector<int> &remaining, const std::vector<int> &X) {

    for (size_t i = 0; i < X.size(); i += 2) {
        if (X[i] < X[i + 1]) {
            S.push_back(X[i + 1]);
            remaining.push_back(X[i]);
        } else {
            S.push_back(X[i]);
            remaining.push_back(X[i + 1]);
        }
    }
    std::sort(S.begin(), S.end());
}

void    PmergeMe::_sortHalfLst(std::list<int> &S, std::list<int> &remaining, const std::list<int> &X) {

    
    for (std::list<int>::const_iterator it = X.begin(); it != X.end(); std::advance(it , 2) ) {
        
        if (std::distance(it, X.end()) == 1) {
            remaining.push_back(*it);
            break;
        }
    
        int next = *(++it);
        --it;
        if (*it < next) {
            S.push_back(next);
            remaining.push_back(*it);
        }
        else {
            S.push_back(*it);
            remaining.push_back(next);
        }
    }
    S.sort();
}

void    PmergeMe::_sortVec(std::vector<int> &X) {

    this->_startTime[VEC] = clock();

    size_t n = X.size();
    if (n <= 1) {
        return;
    }

    std::vector<int> S;
    std::vector<int> remaining;
    _sortHalfVec(S, remaining, X);

    // Insert the smallest element from remaining into S
    int min_remaining = *std::min_element(remaining.begin(), remaining.end());
    std::vector<int>::iterator pos = std::lower_bound(S.begin(), S.end(), min_remaining);
    S.insert(pos, min_remaining);

    // Remove smallest element from remaining
    remaining.erase(std::remove(remaining.begin(), remaining.end(), min_remaining), remaining.end());

    // Insert remaining elements into S based on the computed positions
    for (std::vector<int>::iterator it = remaining.begin(); it != remaining.end(); ++it) {
        pos = std::lower_bound(S.begin(), S.end(), *it);
        S.insert(pos, *it);
    }

    // Copy the sorted elements back to X
    std::copy(S.begin(), S.end(), X.begin());
    this->_endTime[VEC] = clock();
}

void    PmergeMe::_sortLst(std::list<int> &X) {

	this->_startTime[LST] = clock();

    size_t n = X.size();
    if (n <= 1) {
        return;
    }

    std::list<int> S;
    std::list<int> remaining;
    _sortHalfLst(S, remaining, X);

    // Insert the smallest element from remaining into S
    int min_remaining = *std::min_element(remaining.begin(), remaining.end());
    std::list<int>::iterator pos = std::lower_bound(S.begin(), S.end(), min_remaining);
    S.insert(pos, min_remaining);

    // Remove smallest element from remaining
    remaining.erase(std::remove(remaining.begin(), remaining.end(), min_remaining), remaining.end());

    // Insert remaining elements into S based on the computed positions
    for (std::list<int>::iterator it = remaining.begin(); it != remaining.end(); ++it)
    {
        pos = std::lower_bound(S.begin(), S.end(), *it);
        S.insert(pos, *it);
    }

    // Copy the sorted elements back to X
    std::copy(S.begin(), S.end(), X.begin());

	this->_endTime[LST] = clock();
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::UTILS

void PmergeMe::_printVec(std::vector<int> const& X) {

    std::cout << _YELLOW << "- Vector: ";
	std::copy(X.begin(), X.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << _END << std::endl;
}

void PmergeMe::_printLst(std::list<int> const& X) {

    std::cout << _GREEN << "- List:   ";
	std::copy(X.begin(), X.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << _END << std::endl;
}

bool    PmergeMe::_isPositiveNumeric (std::string const& s) {

	return (s.find_first_not_of ("0123456789") == std::string::npos);
}

void    PmergeMe::checkArgs(int ac, char **av) {

    for (int i = 1; i < ac; ++i)
    {
        if (!this->_isPositiveNumeric (av [i]))
            throw PmergeMe::Error ("Invalid input. Only positive integers are allowed.");
        if (std::atoll (av [i]) == 0 || std::atoll (av [i]) > std::numeric_limits <int>::max ())
            throw PmergeMe::Error ("Invalid input. Only positive integers are allowed.");
    }
}
