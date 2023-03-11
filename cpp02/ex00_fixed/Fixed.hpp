#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>

class	Fixed {

	private:
		int					_rawBits;
		static int const	_mantissa_sz = 8;

	public:
		Fixed ();						
		Fixed (Fixed const& copy);						
		~Fixed ();	

		Fixed&	operator= (Fixed const& right);			

		int 	getRawBits (void) const;
		void	setRawBits (int const raw);
};

#endif