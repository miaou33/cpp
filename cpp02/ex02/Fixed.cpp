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
/* 					   GETTERS						 */
/* ************************************************* */

int Fixed::getRawBits (void) const {

	return (_rawBits);
}


/* ************************************************* */
/* 					   SETTERS						 */
/* ************************************************* */

void	Fixed::setRawBits (int const raw) {

	_rawBits = raw;
}


/* ************************************************* */
/* 					   OTHERS						 */
/* ************************************************* */

std::ostream&	operator<< (std::ostream& o, Fixed const& right) {

	o << right.toFloat ();
	return (o);
}

int		Fixed::toInt (void) const {

	return (_rawBits >> _nb_bits_fractionnal);
}

float	Fixed::toFloat (void) const {

	return ((float)_rawBits / (1 << _nb_bits_fractionnal));
}
