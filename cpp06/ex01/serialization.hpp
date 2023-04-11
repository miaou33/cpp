#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <stdint.h>
# include "data.hpp"

uintptr_t   serialize (Data *ptr);
Data        *deserialize (uintptr_t raw);

#endif