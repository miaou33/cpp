#include "Point.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

Point::Point () : 	_x(0),
					_y(0) {}

Point::Point (Point const& original) :
								_x(original.X()),
								_y(original.Y()) {}

Point::Point (float const x, float const y) :	_x (Fixed (x)),
												_y (Fixed (y)) {}

Point::~Point () {}


/* ************************************************* */
/* 					GETTERS / SETTERS				 */
/* ************************************************* */

Fixed Point::X (void) const {

	return _x;
}

Fixed Point::Y (void) const {

	return _y;
}

/* ************************************************* */
/* 					OPERATOR OVERLOADS		 		 */
/* ************************************************* */

// ASSIGNMENT
Point&	Point::operator= (Point const& right) {

	if (&right == this)
		return *this;
 	this->~Point ();
	new (this) Point (right);
	return *this;
}

// COUT
std::ostream&	operator<< (std::ostream& o, Point const& right) {

	o << "(" << right.X () << ", " << right.Y () << ")";
	return (o);
}