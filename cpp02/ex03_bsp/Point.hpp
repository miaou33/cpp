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
		Point (Point const& original);
		Point (float const x, float const y);
		~Point ();
	
	 	// OPERATORS
		Point&	operator= (Point const& right);
		
		// GETTERS / SETTERS
		Fixed X (void) const;
		Fixed Y (void) const;
		
};

std::ostream&	operator<< (std::ostream& o, Point const& right);

#endif