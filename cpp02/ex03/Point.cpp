#include "Point.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

Point::Point () : 	_x(0),
					_y(0) {}

Point::Point (Point const& original) :
								_x(original.getX()),
								_y(original.getY()) {}

Point::Point (float const x, float const y) :	_x (Fixed (x)),
												_y (Fixed (y)) {}

Point::~Point () {}


/* ************************************************* */
/* 					GETTERS / SETTERS				 */
/* ************************************************* */

Fixed const	Point::getX (void) const {

	return _x;
}

Fixed const	Point::getY (void) const {

	return _y;
}

/* ************************************************* */
/* 					OPERATOR OVERLOADS		 		 */
/* ************************************************* */

// ASSIGNMENT
Point&	Point::operator= (Point const& right) {

	if (right == &this)
		return *this;
 	this->~Point ();
	new (this) Point (right);
	return *this;
}
