#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <string>
# include <iostream>
# include <stdexcept>

# define t_ui unsigned int

template <class T>
class Array {

	public:

		Array <T> () : array (NULL), _size (0) {}

		Array <T> (t_ui n) : array (new T [n]), _size (n) {
		
			for (t_ui i = 0; i < n; ++i)
				array [i] = T ();
		}

		Array <T> (Array <T> const& original) : array (NULL) {
			
			*this = original;
		}

		~Array () {

			delete [] array;
		}

		Array <T> const&	operator= (Array <T> const& rhs) {

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

		T&			operator[] (t_ui const index) const {

			if (index >= _size)
				throw std::out_of_range ("index not in array");
			return array [index];
		}

		t_ui			size () const { return _size; }


	private:

		T*		array;
		t_ui	_size;
};

template <class T>
std::ostream&		operator<< (std::ostream& o, Array <T>& rhs)
{
	if (rhs.size ())
	{
		for (t_ui i = 0; i < rhs.size (); ++i)
			std::cout << rhs [i] << std::endl;
	}
	else {
		std::cout << "NULL" << std::endl;
	}
	return o;
}

# endif
