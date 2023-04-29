#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <string>
# include <iostream>
# include <exception>

# define t_ui unsigned int

template <class T>
class Array {

	public:

		Array <T> () : _size (0), _array (NULL) {}

		Array <T> (t_ui n) : _size (n), _array (new T [n]) {
		
			for (t_ui i = 0; i < n; ++i)
				_array [i] = T ();
		}

		Array (Array const& original) : _array (NULL) {
			
			_size = original.size ();
			if (_size > 0)
			{
				_array = new T [_size];
				for (t_ui i = 0; i < _size; ++i)
					_array [i] = original.getArray () [i];
			}
		}

		~Array () {

			delete [] _array;
		}

		Array const&	operator= (Array const& rhs) {

			if (this != &rhs)
			{
				if (_size > 0)
					delete [] _array;
				_size = rhs.size ();
				if (_size > 0)
				{
					_array = new T [_size];
					for (t_ui i = 0; i < _size; ++i)
						_array [i] = rhs.getContent ();
				}
			}
			return *this;
		}

		T			operator[] (t_ui index) {

			if (index >= _size)
				throw std::out_of_range ();
			return _array [index];
		}

		t_ui			size () { return _size; }
		T const*		getArray () { return _array; }

	private:
		T*		_array;
		t_ui	_size;
};

# endif
