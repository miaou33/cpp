#include "Fixed.hpp"

Fixed::Fixed (void) :	_rawBits(0) {

	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (Fixed const& original) {

	std::cout << "Copy constructor called" << std::endl;
	_rawBits = original.getRawBits ();
}

Fixed::~Fixed (void) {

	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator= (Fixed const& right) {

	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = right.getRawBits ();
	return (*this);
}


int Fixed::getRawBits (void) const {

	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void	Fixed::setRawBits (int const raw) {

	_rawBits = raw;
}