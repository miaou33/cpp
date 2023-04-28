#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <string>
# include <iostream>

template <class T>
class Array {

	public:
		Array ();
		Array (Array const& original);
		~Array ();

		Array const&	operator= (Array const& rhs);
	
		T array;

	private:
}

# endif
