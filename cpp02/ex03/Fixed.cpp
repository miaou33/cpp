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

//	floats and doubles have internal structure (specific bit for sign, some bits for exponent, some for exponent, some for mantissa)
//	x = 2.0 = 1 * 2^1   : sign = 0, mantissa = 1, exponent = 1 -> 0 10000000 00000000000000000000000
//	=> shifting de 1 donne la valeur -0 (car bit de sign est desormais a 1 -> on voit que ce process n a pas de sens)
	setRawBits (roundf (floatVal * (1 << _nb_bits_fractionnal)));
}

Fixed::~Fixed (void) {

}


/* ************************************************* */
/* 					GETTERS / SETTERS				 */
/* ************************************************* */

int 	Fixed::getRawBits (void) const {

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

	_rawBits = (((long long)(_rawBits * right.getRawBits ())) >>  _nb_bits_fractionnal);
    return *this;
}

Fixed	Fixed::operator/ (Fixed const& right) {

	if (right == 0)
	{
		std::cout << "Error: Division by 0" << std::endl;
		return (0);
	}
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


Fixed const&	Fixed::min(Fixed const& left, Fixed const& right) {

	if (left.getRawBits () < right.getRawBits ())
		return (left);
	else
		return (right);
}

Fixed const&	Fixed::max(Fixed const& left, Fixed const& right) {

	if (left.getRawBits () > right.getRawBits ())
		return (left);
	else
		return (right);
}

Fixed&			Fixed::min(Fixed& left, Fixed& right) {

	if (left.getRawBits () < right.getRawBits ())
		return (left);
	else
		return (right);
}

Fixed&			Fixed::max(Fixed& left, Fixed& right) {

	if (left.getRawBits () > right.getRawBits ())
		return (left);
	else
		return (right);
}


/* ************************************************* */
/* 				INCREMENT / DECREMENT				 */
/* ************************************************* */

// PREFIX
Fixed&	Fixed::operator++ () {

	_rawBits += 1;
	return (*this);
}

Fixed&	Fixed::operator-- () {

	_rawBits -= 1;
	return (*this);
}

// POSTFIX
Fixed	Fixed::operator++ (int) {

	Fixed	prevFixed (*this);

	_rawBits += 1;
	return (prevFixed);
}

Fixed	Fixed::operator-- (int) {

	Fixed	prevFixed (*this);

	_rawBits -= 1;
	return (prevFixed);
}


/* ************************************************* */
/* 				OFSTREAM OPERATOR					 */
/* ************************************************* */

std::ostream&	operator<< (std::ostream& o, Fixed const& right) {

	o << right.toFloat ();
	return (o);
}
