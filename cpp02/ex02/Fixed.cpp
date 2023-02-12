#include "Fixed.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

Fixed::Fixed (void) {

	setRawBits (0);
}

Fixed::Fixed (Fixed const& original) {

	*this = original;
}

Fixed::Fixed (int const intVal) {

	setRawBits (intVal << _nb_bits_fractionnal);
}

Fixed::Fixed (float const floatVal) {

	setRawBits (roundf (floatVal * (1 << _nb_bits_fractionnal)));
}

Fixed::~Fixed (void) {

}


/* ************************************************* */
/* 					GETTERS / SETTERS				 */
/* ************************************************* */

int Fixed::getRawBits (void) const {

	return (_rawBits);
}

void	Fixed::setRawBits (int const raw) {

	_rawBits = raw;
}


/* ************************************************* */
/* 					CONVERTERS				 		 */
/* ************************************************* */

int		Fixed::toInt (void) const {

	return (_rawBits >> _nb_bits_fractionnal);
}

float	Fixed::toFloat (void) const {

	return ((float)_rawBits / (1 << _nb_bits_fractionnal));
}


/* ************************************************* */
/* 				ARITHMETIC OPERATORS				 */
/* ************************************************* */

Fixed&	Fixed::operator= (Fixed const& right) {

	_rawBits = right.getRawBits ();
	return (*this);
}

Fixed	Fixed::operator+ (Fixed const& right) {

	Fixed res (this->toFloat () + right.toFloat ());
	return (res);
}

Fixed	Fixed::operator- (Fixed const& right) {

	Fixed res (this->toFloat () - right.toFloat ());
	return (res);
}

Fixed	Fixed::operator* (Fixed const& right) {

	Fixed res (this->toFloat () * right.toFloat ());
	return (res);
}

Fixed	Fixed::operator/ (Fixed const& right) {

	Fixed res (this->toFloat () / right.toFloat ());
	return (res);
}


/* ************************************************* */
/* 				COMPARISON  OPERATORS				 */
/* ************************************************* */

bool	Fixed::operator> (Fixed const& right) const {

	return (_rawBits > right.getRawBits ());
}

bool	Fixed::operator< (Fixed const& right) const {

	return (_rawBits < right.getRawBits ());
}

bool	Fixed::operator>= (Fixed const& right) const {

	return (_rawBits >= right.getRawBits ());
}

bool	Fixed::operator<= (Fixed const& right) const {

	return (_rawBits <= right.getRawBits ());
}

bool	Fixed::operator== (Fixed const& right) const {

	return (_rawBits == right.getRawBits ());
}

bool	Fixed::operator!= (Fixed const& right) const {

	return (_rawBits != right.getRawBits ());
}

/* ************************************************* */
/* 				MIN / MAX FINDERS					 */
/* ************************************************* */


static Fixed const&	min(Fixed const& left, Fixed const& right) {

	if (left.getRawBits () < right.getRawBits ())
		return (left);
	else
		return (right);
}

static Fixed const&	max(Fixed const& left, Fixed const& right) {

	if (left.getRawBits () > right.getRawBits ())
		return (left);
	else
		return (right);
}

static Fixed&	min(Fixed& left, Fixed &right) {

	if (left.getRawBits () < right.getRawBits ())
		return (left);
	else
		return (right);
}

static Fixed&	max(Fixed& left, Fixed &right) {

	if (left.getRawBits () > right.getRawBits ())
		return (left);
	else
		return (right);
}


/* ************************************************* */
/* 				OFSTREAM OPERATOR					 */
/* ************************************************* */

std::ostream&	operator<< (std::ostream& o, Fixed const& right) {

	o << right.toFloat ();
	return (o);
}

