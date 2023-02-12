#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <cmath>

class	Fixed {

	private:

		int					_rawBits;
		static int const	_nb_bits_fractionnal = 8;

	public:

		// CONSTRUCTORS
		Fixed ();
		Fixed (Fixed const& copy);
		Fixed (int const intVal);
		Fixed (float const floatVal);
		~Fixed ();
	
		// GETTERS / SETTERS
		int 	getRawBits (void) const;
		void	setRawBits (int const raw);
		
		// CONVERTERS
		int		toInt (void) const;
		float	toFloat (void) const;

		// ARITHMETIC OPERATORS
		Fixed&	operator= (Fixed const& right);
		Fixed	operator+ (Fixed const& right);
		Fixed	operator- (Fixed const& right);
		Fixed	operator* (Fixed const& right);
		Fixed	operator/ (Fixed const& right);

		// COMPARISON OPERATORS
		bool	operator> (Fixed const& right) const;
		bool	operator< (Fixed const& right) const;
		bool	operator>= (Fixed const& right) const;
		bool	operator<= (Fixed const& right) const;
		bool	operator== (Fixed const& right) const;
		bool	operator!= (Fixed const& right) const;

		// PREFIX INCREMENT / DECREMENT OPERATORS
		Fixed&	operator++ ();
		Fixed&	operator-- ();

		// POSTFIX INCREMENT / DECREMENT OPERATORS
		Fixed	operator++ (int);
		Fixed	operator-- (int);

		// MIN / MAX FINDERS
		static Fixed const&	min(Fixed const& left, Fixed const& right);
		static Fixed const&	max(Fixed const& left, Fixed const& right);
		static Fixed&		min(Fixed& left, Fixed& right);
		static Fixed&		max(Fixed& left, Fixed& right);
};

std::ostream&	operator<< (std::ostream& o, Fixed const& right);

#endif