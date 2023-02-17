#include "Point.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

Point::Point () : _x(0), _y(0) {}

Point::Point (Point const& original) {
	
	*this = original;
}

Point::Point (float const x, float const y) :	_x (Fixed (x)),
												_y (Fixed (y))
{}

Point::~Point () {}


/* ************************************************* */
/* 					GETTERS / SETTERS				 */
/* ************************************************* */

Fixed const	Point::getX (void) const {

	return (_x);
}

Fixed const	Point::getY (void) const {

	return (_y);
}

void		Point::setX (Fixed const x) {

	_x = x;
}

void		Point::setY (Fixed const y) {

}

/* ************************************************* */
/* 					OPERATOR OVERLOADS		 		 */
/* ************************************************* */

// ASSIGNMENT
Point&	Point::operator= (Point const& right)
{
	this->setX (right.getX ());
	this->setY (right.getY ());
	return (*this);
}

// OSTREAM
