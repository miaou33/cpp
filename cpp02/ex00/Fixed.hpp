#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>

class	Fixed {

	private:
		int					_val;
		static int const	_nb_bits_fractionnal = 8;

	public:
		Fixed ();										// canonical
		Fixed (Fixed const& copy);						// canonical
		~Fixed ();										// canonical (just miss virtual)

		Fixed&	operator= (Fixed const& rhs);			// canonical

		int 	getRawBits (void) const;
		void	setRawBits (int const raw);
};

#endif