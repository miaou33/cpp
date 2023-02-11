#include "Fixed.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

Fixed::Fixed (void) :	_val(0) {

	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (Fixed const& original) {

	std::cout << "Copy constructor called" << std::endl;
	_val = original.getRawBits ();
}

Fixed::Fixed (int const toFix) {

	std::cout << "Int constructor called" << std::endl;
	_val = toFix;
}

Fixed::Fixed (float const toFix) {

	std::cout << "Float constructor called" << std::endl;
	_val = roundf(toFix);
}

Fixed::~Fixed (void) {

	std::cout << "Destructor called" << std::endl;
}


/* ************************************************* */
/* 					   OPERATORS					 */
/* ************************************************* */

Fixed&	Fixed::operator = (Fixed const& rhs) {

	std::cout << "Copy assignment operator called" << std::endl;
	this->_val = rhs.getRawBits ();
	return (*this);
}

/* ************************************************* */
/* 					   GETTERS						 */
/* ************************************************* */

int Fixed::getRawBits (void) const {

	std::cout << "getRawBits member function called" << std::endl;
	return (_val);
}


/* ************************************************* */
/* 					   SETTERS						 */
/* ************************************************* */

void	Fixed::setRawBits (int const raw) {

	_val = raw;
}


/* ************************************************* */
/* 					   OTHERS						 */
/* ************************************************* */
