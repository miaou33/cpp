#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <string>
# include <iostream>
# include <deque>

template <
	class T,
	class Container = std::stack <T>
>
class MutantStack {

	public:
		MutantStack ();
		explicit MutantStack (Container const& cont = Container());
		MutantStack& operator= (MutantStack const& rhs);
		virtual ~MutantStack ();

		size_t	size () const;
		size_t	empty () const;

	private:
		size_t	_size;
};


# endif
