#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>

class	Fixed {

	private:
		int					_val;
		static int const	_nb_bits_fractionnal = 8;

	public:
		Fixed ();
		Fixed (Fixed const& copy);
		~Fixed ();

		Fixed&	operator= (Fixed const& rhs);

		int 	getRawBits (void) const;
		void	setRawBits (int const raw);
};

#endif