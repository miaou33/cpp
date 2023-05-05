#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <string>
# include <iostream>
# include <stdexcept>

# define t_ui unsigned int

template <class T>
class Array {

	public:

		Array <T> ();
		Array <T> (t_ui n);
		Array <T> (Array const& original);
		~Array ();

		Array <T> const&	operator= (Array <T> const& rhs);
		T&					operator[] (t_ui const index) const;

		t_ui				size () const;

	private:

		T*		array;
		t_ui	_size;
};

template <class T>
std::ostream&		operator<< (std::ostream& o, Array <T>& rhs);

# include "Array.tpp"

# endif
