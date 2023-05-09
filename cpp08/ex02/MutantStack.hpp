#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <string>
# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack <T> {

	public:
		MutantStack ();
		MutantStack (MutantStack <T> const& original);
		MutantStack& operator= (MutantStack const& rhs);
		virtual ~MutantStack ();

		typedef typename std::stack <T>::container_type::iterator iterator;
		typedef typename std::stack <T>::container_type::const_iterator const_iterator;

		const_iterator	begin () const;
		const_iterator	end () const;
};

# include "MutantStack.tpp"

# endif
