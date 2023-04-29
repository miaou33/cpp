#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <string>
# include <iostream>
# include <exception>

# define t_ui unsigned int

template <class T>
class Array {

	public:

		T*		array;

		Array <T> () : array (NULL), _size (0) {}

		Array <T> (t_ui n) : array (new T [n]), _size (n) {
		
			for (t_ui i = 0; i < n; ++i)
				array [i] = T ();
		}

		Array (Array const& original) : array (NULL) {
			
			_size = original.size ();
			if (_size > 0)
			{
				array = new T [_size];
				for (t_ui i = 0; i < _size; ++i)
					array [i] = original.array [i];
			}
		}

		~Array () {

			delete [] array;
		}

		Array const&	operator= (Array const& rhs) {

			if (this != &rhs)
			{
				if (_size > 0)
					delete [] array;
				_size = rhs.size ();
				if (_size > 0)
				{
					array = new T [_size];
					for (t_ui i = 0; i < _size; ++i)
						array [i] = rhs.array [i];
				}
			}
			return *this;
		}

		T			operator[] (t_ui index) {

			if (index >= _size)
				throw std::out_of_range ();
			return array [index];
		}

		t_ui			size () { return _size; }

	private:
		t_ui	_size;
};

template <class T>
std::ostream&		operator<< (std::ostream& o, Array <T>& rhs)
{
	if (rhs.size ())
	{
		for (t_ui i = 0; i < rhs.size (); ++i)
			std::cout << rhs.array [i] << std::endl;
	}
	else {
		std::cout << "NULL" << std::endl;
	}
	return o;
}

# endif
