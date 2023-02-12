#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class	Point {

	private:
		Fixed const	_x;
		Fixed const _y;

	public:

		// CONSTRUCTORS
		Point ();
		Point (Point const& copy);
		Point (float const x, float const y);
		~Point ();
	
	 	// OPERATORS
		Point&	operator= (Point const& right);
		
		// GETTERS / SETTERS
		int 	getRawBits (void) const;
		void	setRawBits (int const raw);
		
};

#endif