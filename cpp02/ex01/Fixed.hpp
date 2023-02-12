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

		// OPERATORS
		Fixed&	operator= (Fixed const& right);

		// GETTERS / SETTERS
		int 	getRawBits (void) const;
		void	setRawBits (int const raw);
		
		// OTHERS
		int		toInt (void) const;
		float	toFloat (void) const;
};

std::ostream&	operator<< (std::ostream& o, Fixed const& right);

#endif