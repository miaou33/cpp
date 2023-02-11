#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <cmath>

class	Fixed {

	private:
		int					_val;
		static int const	_nb_bits_fractionnal = 8;

	public:
		Fixed ();
		Fixed (Fixed const &copy);
		Fixed (int const to_convert);
		Fixed (float const toFix);
		~Fixed ();

		Fixed &operator = (Fixed const &rhs);

		int 	getRawBits (void) const;
		void	setRawBits (int const raw);
		int		toInt (void) const;
		float	toFloat (void) const;
};

#endif