#include "Fixed.hpp"

Fixed::Fixed (void) :	_val(0) {

	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (Fixed const &original) {

	std::cout << "Copy constructor called" << std::endl;

	_val = original.getRawBits ();
}

Fixed::~Fixed (void) {

	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator = (Fixed const & rhs) {

	std::cout << "Copy assignment operator called" << std::endl;

	this->_val = rhs.getRawBits ();
	return (*this);
}


int Fixed::getRawBits (void) const {

	std::cout << "getRawBits member function called" << std::endl;
	
	return (_val);
}

void	Fixed::setRawBits (int const raw) {

	_val = raw;
}