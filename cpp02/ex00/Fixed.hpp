#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>

class	Fixed {

	private:
		int					_rawBits;
		static int const	_mantissa_sz = 8;

	public:
		Fixed ();										// canonical
		Fixed (Fixed const& copy);						// canonical
		~Fixed ();										// canonical (just miss virtual)

		Fixed&	operator= (Fixed const& right);			// canonical

		int 	getRawBits (void) const;
		void	setRawBits (int const raw);
};

#endif