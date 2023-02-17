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
		Fixed const	getX (void) const;
		Fixed const	getY (void) const;
		void		setX (Fixed const x);
		void		setY (Fixed const y);
		
};

#endif