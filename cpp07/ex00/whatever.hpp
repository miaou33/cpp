#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <string>
# include <iostream>

template <typename T>
void swap (T* a, T* b) {

	if (!a || !b)
	{
		std::cout << "Null pointer. Aborting" << std::endl;
		return ;
	}

    T tmp = *a;
    *a = *b;
    *b = tmp;
}

template <typename T>
T min (T const& a, T const& b) {

    return (a < b ? a : b);
}

template <typename T>
T max (T const& a, T const& b) {

    return (a > b ? a : b);
}

# endif
