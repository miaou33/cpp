#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <string>
# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack <T> {

	public:
		MutantStack () {}
		MutantStack (MutantStack <T> const& original) : std::stack <T> (original) {}
		MutantStack& operator= (MutantStack const& rhs) { 
			if (this != &rhs) 
				this->c = rhs.c;
			return *this;
		}
		~MutantStack () {}

		typedef typename std::stack <T>::container_type::iterator iterator;
		typedef typename std::stack <T>::container_type::const_iterator const_iterator;

		iterator begin() { return std::stack<T>::c.begin(); }
		iterator end() { return std::stack<T>::c.end(); }

		const_iterator begin() const { return std::stack<T>::c.begin(); }
		const_iterator end() const { return std::stack<T>::c.end(); }
};

# endif
