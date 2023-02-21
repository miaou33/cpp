#include "Fixed.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

Fixed::Fixed (void) {

	std::cout << "Default constructor called" << std::endl;
	setRawBits (0);
}

Fixed::Fixed (Fixed const& original) {

	std::cout << "Copy constructor called" << std::endl;
	*this = original;
}

Fixed::Fixed (int const intVal) {

	std::cout << "Int constructor called" << std::endl;
	setRawBits (intVal << _mantissa_sz);
}

Fixed::Fixed (float const floatVal) {

	std::cout << "Float constructor called" << std::endl;
	setRawBits (roundf (floatVal * (1 << _mantissa_sz)));
}

Fixed::~Fixed (void) {

	std::cout << "Destructor called" << std::endl;
}


/* ************************************************* */
/* 					   OPERATORS					 */
/* ************************************************* */

Fixed&	Fixed::operator= (Fixed const& right) {

	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = right.getRawBits ();
	return (*this);
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

	return (_rawBits >> _mantissa_sz);
}

float	Fixed::toFloat (void) const {

	return ((float)_rawBits / (1 << _mantissa_sz));
}
