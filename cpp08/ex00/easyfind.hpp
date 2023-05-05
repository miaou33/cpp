#ifndef EASYFIND_HPP
# define EASYFIND_HPP

// # include <stdexcept>
// # include <algorithm>
// 
// template <typename T>
// typename T::iterator	easyfind (T container, int i)
// {
// 	typename T::iterator res = std::find (container.begin (), container.end (), i);
// 
// 	if (res == container.end ())
// 		throw std::runtime_error ("integer not found");
// 	return res;
// }

#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("Value not found");
    }
    return it;
}


#endif
