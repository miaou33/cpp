#include "Fixed.hpp"

/* ************************************************* */
/* 					 CONSTRUCTORS					 */
/* ************************************************* */

Fixed::Fixed (void) : _rawBits(0) {}

Fixed::Fixed (Fixed const& original) :	_rawBits(original.getRawBits()) {}

Fixed::Fixed (int const intVal) : _rawBits (intVal << _mantissa_sz) {}

Fixed::Fixed (float const floatVal) : _rawBits (roundf (floatVal * (1 << _mantissa_sz))) {}

//	floats and doubles have internal structure (specific bit for sign, some bits for exponent, some for exponent, some for mantissa)
//	x = 2.0 = 1 * 2^1   : sign = 0, mantissa = 1, exponent = 1 -> 0 10000000 00000000000000000000000
//	=> shifting de 1 donne la valeur -0 (car bit de sign est desormais a 1 -> on voit que ce process n a pas de sens)

Fixed::~Fixed (void) {}


/* ************************************************* */
/* 					GETTERS / SETTERS				 */
/* ************************************************* */

int 	Fixed::getRawBits (void) const {

	return _rawBits;
}


/* ************************************************* */
/* 					CONVERTERS				 		 */
/* ************************************************* */

int		Fixed::toInt (void) const {

	return _rawBits >> _mantissa_sz;
}

float	Fixed::toFloat (void) const {

	return (float)_rawBits / (1 << _mantissa_sz);
}


/* ************************************************* */
/* 				ARITHMETIC OPERATORS				 */
/* ************************************************* */

Fixed&	Fixed::operator= (Fixed const& right) {

	_rawBits = right.getRawBits ();
	return *this;
}

Fixed	Fixed::operator+ (Fixed const& right) {

	Fixed res (this->toFloat () + right.toFloat ());
	return res;
}

Fixed	Fixed::operator- (Fixed const& right) {

	Fixed res (this->toFloat () - right.toFloat ());
	return res;
}

Fixed	Fixed::operator* (Fixed const& right) {

	Fixed  res (this->toFloat () * right.toFloat ());
	return (res);
}

Fixed	Fixed::operator/ (Fixed const& right) {

	if (right == 0)
	{
		std::cout << "Error: Division by 0. Res set to 0. ";
		Fixed error (0);
		return (error);
	}
	Fixed res (this->toFloat () / right.toFloat ());
	return res;
}


/* ************************************************* */
/* 				INCREMENT / DECREMENT				 */
/* ************************************************* */

// PREFIX
Fixed&	Fixed::operator++ () {

	_rawBits += 1;
	return *this;
}

Fixed&	Fixed::operator-- () {

	_rawBits -= 1;
	return *this;
}

// POSTFIX
Fixed	Fixed::operator++ (int) {

	Fixed	prevFixed (*this);

	_rawBits += 1;
	return prevFixed;
}

Fixed	Fixed::operator-- (int) {

	Fixed	prevFixed (*this);

	_rawBits -= 1;
	return prevFixed;
}


/* ************************************************* */
/* 				COMPARISON  OPERATORS				 */
/* ************************************************* */

bool	Fixed::operator> (Fixed const& right) const {

	return _rawBits > right.getRawBits ();
}

bool	Fixed::operator< (Fixed const& right) const {

	return _rawBits < right.getRawBits ();
}

bool	Fixed::operator>= (Fixed const& right) const {

	return _rawBits >= right.getRawBits ();
}

bool	Fixed::operator<= (Fixed const& right) const {

	return _rawBits <= right.getRawBits ();
}

bool	Fixed::operator== (Fixed const& right) const {

	return _rawBits == right.getRawBits ();
}

bool	Fixed::operator!= (Fixed const& right) const {

	return _rawBits != right.getRawBits ();
}


/* ************************************************* */
/* 				MIN / MAX FINDERS					 */
/* ************************************************* */


Fixed const&	Fixed::min(Fixed const& left, Fixed const& right) {

	if (left.getRawBits () < right.getRawBits ())
		return left;
	else
		return right;
}

Fixed const&	Fixed::max(Fixed const& left, Fixed const& right) {

	if (left.getRawBits () > right.getRawBits ())
		return left;
	else
		return right;
}

Fixed&			Fixed::min(Fixed& left, Fixed& right) {

	if (left.getRawBits () < right.getRawBits ())
		return left;
	else
		return right;
}

Fixed&			Fixed::max(Fixed& left, Fixed& right) {

	if (left.getRawBits () > right.getRawBits ())
		return left;
	else
		return right;
}

/* ************************************************* */
/* 				OFSTREAM OPERATOR					 */
/* ************************************************* */

std::ostream&	operator<< (std::ostream& o, Fixed const& right) {

	o << right.toFloat ();
	return o;
}

