# include "Array.hpp"

template <class T>
Array <T>::Array () : array (NULL), _size (0) {}

template <class T>
Array <T>::Array (t_ui n) : array (new T [n]), _size (n) {
		
	for (t_ui i = 0; i < n; ++i)
		array [i] = T ();
}

template <class T>
Array <T>::Array (Array const& original) : array (NULL) {
	
	*this = original;
}

template <class T>
Array <T>::~Array () {

	delete [] array;
}

template <class T>
Array <T> const&	Array <T>::operator= (Array const& rhs) {

	if (this != &rhs)
	{
		if (_size > 0)
			delete [] array;
		_size = rhs.size ();
		if (_size > 0)
		{
			array = new T [_size];
			for (t_ui i = 0; i < _size; ++i)
				array [i] = rhs [i];
		}
	}
	return *this;
}

template <class T>
T&					Array <T>::operator[] (t_ui const index) const {

	if (index >= _size)
		throw std::out_of_range ("index not in array");
	return array [index];
}

template <class T>
t_ui				Array <T>::size () const { return _size; }

template <class T>
std::ostream&		operator<< (std::ostream& o, Array <T>& rhs)
{
	if (rhs.size ())
	{
		std::cout << "{ ";
		for (t_ui i = 0; i < rhs.size (); ++i)
		{
			std::cout << rhs [i];
			if (i != rhs.size () - 1)
				std::cout << ", ";
		}
		std::cout << " }";
	}
	else {
		std::cout << "NULL";
	}
	return o;
}

