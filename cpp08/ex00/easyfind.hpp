#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind (T& container, int value)
{
    typename T::iterator it;

	it = std::find (container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("Value not found");
    }
    return it;
}

#endif

/*
** typename devant T pour signifier au compilateur qu'iterator est un type
** > sinon, ne pourrait pas savoir s'il s'agit d'une classe ou d'un type de donnees 
*/
